#include QMK_KEYBOARD_H
#include "neekpizza.h"
#include "ocean_dream.h"

#define LAYOUT_wrapper_3x5_3(...) LAYOUT_split_3x5_3(__VA_ARGS__)
#define LAYOUT_crkbd_wrapper(...) LAYOUT_wrapper_3x5_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_crkbd_wrapper(
    __________________BASE_L1__________________,  __________________BASE_R1__________________,
    __________________BASE_L2__________________,  __________________BASE_R2__________________,
    __________________BASE_L3__________________,  __________________BASE_R3__________________,
                    OSM(MOD_MEH), MO(1), KC_ESC,  KC_SPC, MO(2), OSM(MOD_HYPR)
  ),

  [_NUM] = LAYOUT_crkbd_wrapper(
    __________________NUM_L1___________________,  __________________NUM_R1___________________,
    __________________NUM_L2___________________,  __________________NUM_R2___________________,
    __________________NUM_L3___________________,  __________________NUM_R3___________________,
                      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_MEDIA] = LAYOUT_crkbd_wrapper(
    __________________MEDIA_L1_________________,  __________________MEDIA_R1_________________,
    __________________MEDIA_L2_________________,  __________________MEDIA_R2_________________,
    __________________MEDIA_L3_________________,  __________________MEDIA_R3_________________,
                      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(!process_record_user_neekpizza(keycode, record)) return false;
    switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
          #ifdef OCEAN_DREAM_ENABLE
            is_calm = (record->event.pressed) ? true : false;
          #endif
          break;
    }
    return true;
}

