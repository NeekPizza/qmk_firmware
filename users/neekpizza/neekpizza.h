#pragma once

#include "rows.h"
#include "layers.h"
#include "neekpizza_keycodes.h"

#ifdef OLED_ENABLE
    #include "oled.h"
#endif

#ifdef COMBO_ENABLE
    #include "combos.h"
#endif

bool process_record_user_neekpizza(uint16_t keycode, keyrecord_t *record);
