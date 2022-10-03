#include <Arduino.h>
#include <M5EPD.h>
#include "lv_ui/ui.h"
#include "lv_ui/ui_helpers.h"
#include "lvgl.h"

#define LV_HOR_RES_MAX  540
#define LV_VER_RES_MAX  960

static lv_disp_draw_buf_t draw_buf;
static lv_disp_drv_t disp_drv;
static lv_indev_drv_t indev_drv;

M5EPD_Driver *epd;
bool touch_pressed = false;
tp_finger_t touch_pos;

uint8_t *epd_buffer;
lv_color_t *display_buffer;

static void ta_event_cb(lv_event_t * e);
static lv_obj_t * kb;

static void ta_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED || code == LV_EVENT_FOCUSED) {
        /*Focus on the clicked text area*/
        if(kb != NULL) lv_keyboard_set_textarea(kb, ta);
    }

    else if(code == LV_EVENT_READY) {
        LV_LOG_USER("Ready, current text: %s", lv_textarea_get_text(ta));
    }
}

void my_log_cb(const char * buf)
{
  Serial.println(buf);
}

void init_display() {
  M5.begin();
  M5.EPD.SetRotation(90);
  M5.TP.SetRotation(90);
  M5.EPD.Clear(true);

  lv_init();

  epd_buffer = (uint8_t *)ps_malloc(((LV_HOR_RES_MAX * LV_VER_RES_MAX) / 2) * sizeof(uint8_t));
  display_buffer = (lv_color_t *)ps_malloc((LV_HOR_RES_MAX * LV_VER_RES_MAX) * sizeof(lv_color_t));

  lv_disp_draw_buf_init(&draw_buf, display_buffer, NULL, LV_HOR_RES_MAX * LV_VER_RES_MAX);

  epd = &M5.EPD;
}

void flush_display(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  Serial.printf("draw: %d, %d, %d, %d\n", area->x1, area->y1, w, h);
  
  m5epd_err_t err;

  err = epd->WritePartGram4bpp(area->x1, area->y1, w, h, epd_buffer);
  if(err != M5EPD_OK) {
    Serial.println("WritePartGram4bpp failed");
  }

  err = epd->UpdateArea(area->x1, area->y1, w, h, UPDATE_MODE_DU4);
  if(err != M5EPD_OK) {
    Serial.println("UpdateArea failed");
  }

  lv_disp_flush_ready(disp);
}

void my_set_px_cb(lv_disp_drv_t * disp_drv, uint8_t* buf, lv_coord_t buf_w, lv_coord_t x, lv_coord_t y, lv_color_t color, lv_opa_t opa)
{
    if(x == 0 && y == 0) {
      Serial.printf("set_px: %d, %d, %d, %d", color.ch.red, color.ch.green, color.ch.blue, color.full);
    }

    // Test using RGB232. Darker the color otherwise is too light for this epaper:
    int16_t epd_color = 255;
    if ((int16_t)color.full<250) {
        epd_color = (int16_t)color.full/3;
    }

    epd_color = 255 - epd_color;

    if(x == 0 && y == 0) {
      Serial.printf("set_px: %d, %d, %d, %d, %d", color.ch.red, color.ch.green, color.ch.blue, color.full, epd_color);
    }

    int16_t x1 = (int16_t)x;
    int16_t y1 = (int16_t)y;
    // framebuffer is the epaper buffer that is sent via parallel 8 wire using EPDiy
    //Instead of using epd_draw_pixel: Set pixel directly in buffer
    //epd_draw_pixel(x1, y1, epd_color, framebuffer);
    // 4 bit per pixel (16 grayscales)
    uint8_t *buf_ptr = &epd_buffer[y1 * buf_w / 2 + x1 / 2];
    if (x % 2) {
        *buf_ptr = (*buf_ptr & 0x0F) | (epd_color & 0xF0);
    } else {
        *buf_ptr = (*buf_ptr & 0xF0) | (epd_color >> 4);
    }
}

void my_rounder_cb(lv_disp_drv_t * disp_drv, lv_area_t * area)
{
  if(area->x1 % 4 > 0) {
    area->x1 = area->x1 - (area->x1 % 4);
  }

  if(area->y1 % 4 > 0) {
    area->y1 = area->y1 - (area->y1 % 4);
  }

  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);
  
  if(w % 4 > 0) {
    w = w + (4 - (w % 4));
    area->x2 = area->x1 + w - 1;
  }

  if(h % 4 > 0) {
    h = h + (4 - (h % 4));
    area->y2 = area->y1 + h - 1;
  }
}

void init_display_driver() {
  lv_disp_drv_init(&disp_drv);  // Basic initialization

  disp_drv.full_refresh = 0;
  disp_drv.rounder_cb = my_rounder_cb;
  disp_drv.flush_cb = flush_display;  // Set your driver function
  disp_drv.set_px_cb = my_set_px_cb;
  disp_drv.draw_buf = &draw_buf;      // Assign the buffer to the display
  disp_drv.hor_res = LV_HOR_RES_MAX;  // Set the horizontal resolution of the display
  disp_drv.ver_res = LV_VER_RES_MAX;  // Set the vertical resolution of the display

  lv_disp_drv_register(&disp_drv);                   // Finally register the driver
  lv_disp_set_bg_color(NULL, lv_color_hex3(0x000));  // Set default background color to black
}

void touchpad_read(lv_indev_drv_t * drv, lv_indev_data_t * data)
{
  if(!touch_pressed) {    
    data->state = LV_INDEV_STATE_REL;
  } else {
    data->state = LV_INDEV_STATE_PR; 
    data->point.x = touch_pos.x;
    data->point.y = touch_pos.y;
  }
}

void init_touch_driver() {
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = touchpad_read;
  lv_indev_t * my_indev = lv_indev_drv_register(&indev_drv);  // register
}


void setup() {
  lv_log_register_print_cb(my_log_cb);
  init_display();
  init_display_driver();
  init_touch_driver();
  ui_init();
  setCpuFrequencyMhz(240);
}

void loop() {
  if(M5.TP.avaliable()) {
    M5.TP.update();

    touch_pressed = !M5.TP.isFingerUp();
    touch_pos = M5.TP.readFinger(0);
  }

  lv_task_handler();

  delay(5);
}