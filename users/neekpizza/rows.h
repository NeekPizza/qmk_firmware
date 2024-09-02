#pragma once
#include "neekpizza.h"
#include QMK_KEYBOARD_H
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define TRNS _______, _______, _______, _______, _______

#define __________________BASE_L1__________________ KC_Q, KC_W, KC_E, KC_R, KC_T
#define __________________BASE_L2__________________ CTL_T(KC_A), SFT_T(KC_S), GUI_T(KC_D), KC_F, KC_G
#define __________________BASE_L3__________________ KC_Z, KC_X, KC_C, KC_V, KC_B


#define __________________BASE_R1__________________ KC_Y, KC_U, KC_I,        KC_O,        KC_P
#define __________________BASE_R2__________________ KC_H,       KC_J, GUI_T(KC_K), SFT_T(KC_L), CTL_T(KC_SCLN)
#define __________________BASE_R3__________________ KC_N,       KC_M, KC_COMM,     KC_DOT,      KC_SLSH

#define __________________NUM_L1___________________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __________________NUM_L2___________________ KC_GRV,  _______, KC_LBRC, KC_RBRC, _______
#define __________________NUM_L3___________________ TRNS

#define __________________NUM_R1___________________ KC_6,    KC_7,    KC_8,    KC_9,     KC_0
#define __________________NUM_R2___________________ _______,   KC_EQL,  KC_MINS, KC_BSLS,  KC_QUOT
#define __________________NUM_R3___________________ KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______

#define __________________MEDIA_L1_________________ TRNS
#define __________________MEDIA_L2_________________ _______, _______, KC_F7, KC_F8, _______
#define __________________MEDIA_L3_________________ TRNS

#define __________________MEDIA_R1_________________ _______, KC_MUTE, KC_MPLY, KC_MSTP, _______
#define __________________MEDIA_R2_________________ _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
#define __________________MEDIA_R3_________________ _______, _______, _______, _______, _______

#define TWO_THUMBS_R1  KC_SPC, MO(_MEDIA)
#define TWO_THUMBS_L1  MO(_NUM), KC_ESC
#define TWO_THUMBS_TRNS _______, _______

