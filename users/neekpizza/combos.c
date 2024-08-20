#include "combos.h"
#include QMK_KEYBOARD_H

enum combos {
  OP_BSPS,
  L_SCLN_ENT,
  QW_TAB,
  COMBO_COUNT
};

const uint16_t COMBO_LEN = COMBO_COUNT;

const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM l_scln_combo[] = {SFT_T(KC_L), CTL_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[] = {
  [OP_BSPS] = COMBO(op_combo, KC_BSPC),
  [L_SCLN_ENT] = COMBO(l_scln_combo, KC_ENT),
  [QW_TAB] = COMBO(qw_combo, KC_TAB),
};
