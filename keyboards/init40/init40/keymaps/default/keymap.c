/* Copyright 2023 Yiancar-Designs
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
#include QMK_KEYBOARD_H
#include "../../../lib/rdr_lib/rdr_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_Q,    KC_W,      KC_E,     KC_R,       KC_T,      KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
        KC_TAB,  KC_A,    KC_S,      KC_D,     KC_F,       KC_G,      KC_H,     KC_J,    KC_K,     KC_L,     KC_ENT,
        KC_LSFT, KC_Z,    KC_X,      KC_C,     KC_V,       KC_B,      KC_N,     KC_M,    KC_COMMA, KC_DOT,   KC_RSFT,
        KC_LCTL, MO(2),   KC_LALT,             KC_SPC,     KC_SPC,                       KC_RALT,  KC_RGUI,  KC_APP
    ),
    [1] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_Q,    KC_W,      KC_E,     KC_R,       KC_T,      KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
        KC_TAB,  KC_A,    KC_S,      KC_D,     KC_F,       KC_G,      KC_H,     KC_J,    KC_K,     KC_L,     KC_ENT,
        KC_LSFT, KC_Z,    KC_X,      KC_C,     KC_V,       KC_B,      KC_N,     KC_M,    KC_COMMA, KC_DOT,   KC_RSFT,
        KC_LCTL, MO(3),   KC_LGUI,             KC_SPC,     KC_SPC,                       KC_RGUI,  KC_RALT,  KC_APP
    ),
    [2] = LAYOUT_tkl_ansi(
        KC_GRV,  KC_1,    KC_2,      KC_3,     KC_4,       KC_5,      KC_6,     KC_7,    KC_8,     KC_9,     KC_0,     RGB_RTOG,
        MD_USB,  MD_BLE1, MD_BLE2,   MD_BLE3,  MD_24G,     MW_CH,     KC_MINS,  KC_EQL,  KC_LBRC,  KC_RBRC,  RGB_MOD,
        KC_LSFT, KC_INS,  KC_HOME,   KC_END,   KC_PGUP,    KC_PGDN,   KC_SCLN,  KC_QUOT, KC_SLASH, KC_UP,    KC_DEL,
        QK_BAT,  KC_NO,   LOGO_TOG,            KC_SPC,     U_EE_CLR,                     KC_LEFT,  KC_DOWN,  KC_RIGHT
    ),
    [3] = LAYOUT_tkl_ansi(
        KC_GRV,  KC_1,    KC_2,      KC_3,     KC_4,       KC_5,      KC_6,     KC_7,    KC_8,     KC_9,     KC_0,     RGB_RTOG,
        MD_USB,  MD_BLE1, MD_BLE2,   MD_BLE3,  MD_24G,     MW_CH,     KC_MINS,  KC_EQL,  KC_LBRC,  KC_RBRC,  RGB_MOD,
        KC_LSFT, KC_INS,  KC_HOME,   KC_END,   KC_PGUP,    KC_PGDN,   KC_SCLN,  KC_QUOT, KC_SLASH, KC_UP,    KC_DEL,
        QK_BAT,  KC_NO,   LOGO_TOG,            KC_SPC,     U_EE_CLR,                     KC_LEFT,  KC_DOWN,  KC_RIGHT
    ),
    [4] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_Q,    KC_W,      KC_E,     KC_R,       KC_T,      KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
        KC_TAB,  KC_A,    KC_S,      KC_D,     KC_F,       KC_G,      KC_H,     KC_J,    KC_K,     KC_L,     KC_ENT,
        KC_LSFT, KC_Z,    KC_X,      KC_C,     KC_V,       KC_B,      KC_N,     KC_M,    KC_COMMA, KC_DOT,   KC_RSFT,
        KC_LCTL, KC_NO,   KC_LALT,             KC_SPC,     KC_SPC,                       KC_RALT,  KC_RGUI,  KC_APP
    ),
    [5] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_Q,    KC_W,      KC_E,     KC_R,       KC_T,      KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
        KC_TAB,  KC_A,    KC_S,      KC_D,     KC_F,       KC_G,      KC_H,     KC_J,    KC_K,     KC_L,     KC_ENT,
        KC_LSFT, KC_Z,    KC_X,      KC_C,     KC_V,       KC_B,      KC_N,     KC_M,    KC_COMMA, KC_DOT,   KC_RSFT,
        KC_LCTL, KC_NO,   KC_LALT,             KC_SPC,     KC_SPC,                       KC_RALT,  KC_RGUI,  KC_APP
    ),
    [6] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_Q,    KC_W,      KC_E,     KC_R,       KC_T,      KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
        KC_TAB,  KC_A,    KC_S,      KC_D,     KC_F,       KC_G,      KC_H,     KC_J,    KC_K,     KC_L,     KC_ENT,
        KC_LSFT, KC_Z,    KC_X,      KC_C,     KC_V,       KC_B,      KC_N,     KC_M,    KC_COMMA, KC_DOT,   KC_RSFT,
        KC_LCTL, KC_NO,   KC_LALT,             KC_SPC,     KC_SPC,                       KC_RALT,  KC_RGUI,  KC_APP
    ),
    [7] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_Q,    KC_W,      KC_E,     KC_R,       KC_T,      KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
        KC_TAB,  KC_A,    KC_S,      KC_D,     KC_F,       KC_G,      KC_H,     KC_J,    KC_K,     KC_L,     KC_ENT,
        KC_LSFT, KC_Z,    KC_X,      KC_C,     KC_V,       KC_B,      KC_N,     KC_M,    KC_COMMA, KC_DOT,   KC_RSFT,
        KC_LCTL, KC_NO,   KC_LALT,             KC_SPC,     KC_SPC,                       KC_RALT,  KC_RGUI,  KC_APP
    ),
    [8] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_Q,    KC_W,      KC_E,     KC_R,       KC_T,      KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
        KC_TAB,  KC_A,    KC_S,      KC_D,     KC_F,       KC_G,      KC_H,     KC_J,    KC_K,     KC_L,     KC_ENT,
        KC_LSFT, KC_Z,    KC_X,      KC_C,     KC_V,       KC_B,      KC_N,     KC_M,    KC_COMMA, KC_DOT,   KC_RSFT,
        KC_LCTL, KC_NO,   KC_LALT,             KC_SPC,     KC_SPC,                       KC_RALT,  KC_RGUI,  KC_APP
    ),
    [9] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_Q,    KC_W,      KC_E,     KC_R,       KC_T,      KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
        KC_TAB,  KC_A,    KC_S,      KC_D,     KC_F,       KC_G,      KC_H,     KC_J,    KC_K,     KC_L,     KC_ENT,
        KC_LSFT, KC_Z,    KC_X,      KC_C,     KC_V,       KC_B,      KC_N,     KC_M,    KC_COMMA, KC_DOT,   KC_RSFT,
        KC_LCTL, KC_NO,   KC_LALT,             KC_SPC,     KC_SPC,                       KC_RALT,  KC_RGUI,  KC_APP
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [1] = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [2] = { ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [3] = { ENCODER_CCW_CW(RGB_SPD, RGB_SPI) }
};

#endif


