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
#pragma once

#include QMK_KEYBOARD_H
#include "keychron_common.h"

// clang-format off

#ifdef ENABLE_TEXT_MEMES
enum {
    TAUNTTXT = NEW_SAFE_RANGE,
    WIDETXT,
};


bool process_record_doni_memes(uint16_t keycode, keyrecord_t *record);
#endif
