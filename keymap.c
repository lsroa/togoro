/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <g/keymap_combo.h>

enum layer_names {
  _BASE,
  _LOWER,
  _RAISE,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

#define CTRL_A LCTL_T(KC_A)
#define SF_S LSFT_T(KC_S)
#define SF_L RSFT_T(KC_L)
#define CTRL_SM RCTL_T(KC_SCLN)
#define GUI_J LGUI_T(KC_J)
#define ALT_F RALT_T(KC_F)
#define ENT_GUI LGUI_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung34(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    CTRL_A,  SF_S,    KC_D,    ALT_F,   KC_G,          KC_H,    GUI_J,   KC_K,    SF_L,    CTRL_SM,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                               LOWER,   KC_SPC,        ENT_GUI,  RAISE
  ),

  [_LOWER] = LAYOUT_reviung34(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_BSPC,
                               _______, KC_SPC,        ENT_GUI, XXXXXXX
  ),

  [_RAISE] = LAYOUT_reviung34(
    KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_GRV,  KC_TILD, KC_QUOTE, KC_DQUO, XXXXXXX,       KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    XXXXXXX, XXXXXXX, KC_RGUI,  KC_LALT, XXXXXXX,       KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                                XXXXXXX, KC_SPC,        ENT_GUI, _______
  ),
};
