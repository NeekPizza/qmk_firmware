#include QMK_KEYBOARD_H
#include "neekpizza.h"
#include "ocean_dream.h"
#define LAYOUT_wrapper_3x5_3(...) LAYOUT_split_3x5_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper_3x5_3(
    BASE_L1, BASE_R1,
    BASE_L2, BASE_R2,
    BASE_L3, BASE_R3,
     OSM(MOD_MEH),      MO(1),      KC_ESC,     KC_SPC, MO(2), OSM(MOD_HYPR)
  ),

  [_NUM] = LAYOUT_split_3x5_3(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
    KC_GRV,  KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS,         KC_TRNS,   KC_EQL,  KC_MINS, KC_BSLS,  KC_QUOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SNIP,         KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_SPC
  ),

  [_MEDIA] = LAYOUT_split_3x5_3(
    _______, _______, _______, _______, _______,         KC_TRNS, KC_MUTE, KC_MPLY, KC_MSTP, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS
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

