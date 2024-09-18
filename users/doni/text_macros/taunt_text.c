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
#include "modifiers.h"
#include "quantum_keycodes.h"
#include "taunt_text.h"
#include "doni.h"

static struct {
    bool on;
    bool is_a_z;
    bool taunt_text;
} taunt_text_config = {false, false, false};

bool process_record_taunt_text(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TAUNTTXT:
            if (record->event.pressed) {
                taunt_text_config.on = !taunt_text_config.on;
                taunt_text_config.is_a_z = false;
                taunt_text_config.taunt_text = false;

                return false;
            }
        case KC_A...KC_Z:
            taunt_text_config.is_a_z = true;
            break;
        default:
            taunt_text_config.is_a_z = false;
            break;
    }
    if (taunt_text_config.on) {
        if (record->event.pressed) {
            if (keycode != KC_SPACE) {
                taunt_text_config.taunt_text = !taunt_text_config.taunt_text;
                if (taunt_text_config.taunt_text && taunt_text_config.is_a_z) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(keycode);
                    } else {
                        tap_code16(S(keycode));
                    }

                    return false;
                }
            }
        }
    }

    return true;
}
