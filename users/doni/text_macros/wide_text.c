/* Copyright 2024 @ Doni Crosby (https://donicrosby.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "action.h"
#include "keycodes.h"
#include "wide_text.h"
#include "doni.h"

static struct {
    bool on;
    bool first;
} wide_text_config = {false, false};

bool process_record_wide_text(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WIDETXT:
            if (record->event.pressed) {
                wide_text_config.on = !wide_text_config.on;
                wide_text_config.first = true;
            }
            return false;
    }

    if (wide_text_config.on) {
        if(record->event.pressed) {
            switch (keycode) {
                case KC_A...KC_0:
                case KC_MINS...KC_SLASH:
                case KC_SPACE:
                    if (wide_text_config.first) {
                        wide_text_config.first = false;
                    } else {
                        send_char(' ');
                    }
                    break;
                case KC_ENT:
                    wide_text_config.first = true;
                    break;
                case KC_BSPC:
                    send_char('\b');
                    break;
            }
        }
    }

    return true;
}
