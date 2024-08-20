#include QMK_KEYBOARD_H
#include "neekpizza.h"


bool process_record_user_neekpizza(uint16_t keycode, keyrecord_t *record) {
    #ifdef OLED_ENABLE
    if(!process_record_user_oled_neekpizza(keycode, record)) return false;
    #endif
    switch(keycode) {
        case KC_SNIP:
            if(record->event.pressed) {
                tap_code16(G(S(C(KC_4))));
            }
        return false;
    }

    return true;
}
