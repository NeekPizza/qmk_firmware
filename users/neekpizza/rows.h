#pragma once
#include "neekpizza.h"
#include QMK_KEYBOARD_H
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define TRNS _______, _______, _______, _______, _______

#define BASE_L1 KC_Q, KC_W, KC_E, KC_R, KC_T
#define BASE_L2 CTL_T(KC_A), SFT_T(KC_S), GUI_T(KC_D), KC_F, KC_G
#define BASE_L3 KC_Z, KC_X, KC_C, KC_V, KC_B


#define BASE_R1 KC_Y, KC_U, KC_I,        KC_O,        KC_P
#define BASE_R2 KC_H,       KC_J, GUI_T(KC_K), SFT_T(KC_L), CTL_T(KC_SCLN)
#define BASE_R3 KC_N,       KC_M, KC_COMM,     KC_DOT,      KC_SLSH

#define NUM_L1 KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define NUM_L2 KC_GRV,  _______, KC_LBRC, KC_RBRC, _______
#define NUM_L3 TRNS

#define NUM_R1  KC_6,    KC_7,    KC_8,    KC_9,     KC_0
#define NUM_R2  _______,   KC_EQL,  KC_MINS, KC_BSLS,  KC_QUOT
#define NUM_R3  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______

#define MEDIA_L1 TRNS
#define MEDIA_L2 _______, _______, KC_F7, KC_F8, _______
#define MEDIA_L3 TRNS

#define MEDIA_R1 _______, KC_MUTE, KC_MPLY, KC_MSTP, _______
#define MEDIA_R2 _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
#define MEDIA_R3 _______, _______, _______, _______, _______

#define TWO_THUMBS_R1  KC_SPC, MO(_MEDIA)
#define TWO_THUMBS_L1  MO(_NUM), KC_ESC
#define TWO_THUMBS_TRNS _______, _______

