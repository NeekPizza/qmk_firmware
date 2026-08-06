#include QMK_KEYBOARD_H
#include "neekpizza.h"

#define LAYOUT_wrapper_3x5_2(...) LAYOUT_split_3x5_2(__VA_ARGS__)
#define LAYOUT_ferris_wrapper(...) LAYOUT_wrapper_3x5_2(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ferris_wrapper(
    __________________BASE_L1__________________,  __________________BASE_R1__________________,
    __________________BASE_L2__________________,  __________________BASE_R2__________________,
    __________________BASE_L3__________________,  __________________BASE_R3__________________,
                          TWO_THUMBS_L1,  TWO_THUMBS_R1
  ),

  [_NUM] = LAYOUT_ferris_wrapper(
    __________________NUM_L1___________________,  __________________NUM_R1___________________,
    __________________NUM_L2___________________,  __________________NUM_R2___________________,
    __________________NUM_L3___________________,  __________________NUM_R3___________________,
                        TWO_THUMBS_TRNS,  TWO_THUMBS_TRNS
  ),

  [_MEDIA] = LAYOUT_ferris_wrapper(
    __________________MEDIA_L1_________________,  __________________MEDIA_R1_________________,
    __________________MEDIA_L2_________________,  __________________MEDIA_R2_________________,
    __________________MEDIA_L3_________________,  __________________MEDIA_R3_________________,
                        TWO_THUMBS_TRNS,  TWO_THUMBS_TRNS
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_record_user_neekpizza(keycode, record);
}
