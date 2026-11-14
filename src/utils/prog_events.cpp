#include "ui.h"

static void release_btn_timer_cb(lv_timer_t * timer) {
    lv_obj_t * btn = (lv_obj_t *)timer->user_data;

    if(lv_obj_is_valid(btn)) {
        lv_obj_clear_state(btn, LV_STATE_PRESSED);
        lv_event_send(btn, LV_EVENT_RELEASED, NULL);
        lv_event_send(btn, LV_EVENT_CLICKED, NULL);
    }
}


void progBtnClick(lv_obj_t * btn, uint32_t delay_ms) {
    lv_obj_add_state(btn, LV_STATE_PRESSED);
    lv_event_send(btn, LV_EVENT_PRESSED, NULL);

    lv_timer_t * timer = lv_timer_create(release_btn_timer_cb, delay_ms, btn);
    
    lv_timer_set_repeat_count(timer, 1);
}