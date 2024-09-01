#include "oled.h"
#include "layers.h"
#include "ocean_dream.h"
#include "bongo_cat.h"
#include QMK_KEYBOARD_H

char wpm_str[10];

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
    }
    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        #ifdef OCEAN_DREAM_ENABLE
            render_stars();
        #endif
    } else {
        #ifdef BONGO_CAT_ENABLE
        render_bongo_cat();  // renders pixelart
        oled_set_cursor(0, 0);                            // sets cursor to (row, column) using charactar spacing (5 rows on 128x32 screen, anything more will overflow back to the top)
        sprintf(wpm_str, "WPM:%03d", get_current_wpm());  // edit the string to change wwhat shows up, edit %03d to change how many digits show up
        oled_write(wpm_str, false);                       // writes wpm on top left corner of string
        oled_set_cursor(0, 1);
        #endif
   }

   return false;
}