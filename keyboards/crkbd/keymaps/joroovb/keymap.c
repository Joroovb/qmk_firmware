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

enum layers {
    _QWERTY,
    NAV,
    MEDIA,
    NUM,
    MOUSE,
    SYM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_HYPR,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LALT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_COLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_LGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
              LT(MEDIA, KC_ESC), LT(NAV, KC_SPC), LT(MOUSE, KC_TAB),     LT(SYM, KC_ENT),   LT(NUM, KC_BSPC), KC_DEL
                        //`--------------------           s--------------------'  `--------------------------'

  ),
  [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         U_NA, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                         U_NA,    U_NA,    U_NA,    U_NA,   U_NA,   U_NA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         U_NA, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                         U_NA, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  U_NA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         U_NA,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,                         U_NA,    U_NA,    U_NA,    U_NA,    U_NA,  U_NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             KC_DOT,  KC_0, KC_MINS,     KC_ENT, KC_BSPC,  KC_DEL
                                      //`--------------------------'  `--------------------------'

  ),
  [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,                        U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,  U_NA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         U_NA, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,    U_NA,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_CAPS,  U_NA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,  U_NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             U_NA,    U_NA,    U_NA,     KC_ENT, KC_BSPC,   KC_DEL
                                      //`--------------------------'  `--------------------------'

  ),
  [MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,                      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,  U_NA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         U_NA, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,    U_NA,                      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,    U_NU,  U_NA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,                         U_NA,    U_NU,    U_NU,    U_NU,    U_NU,  U_NU,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             U_NA,    U_NA,    U_NA,     KC_MSTP, KC_MPLY, KC_MUTE
                                      //`--------------------------'  `--------------------------'

  ),
  [MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,                        U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,  U_NA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         U_NA, KC_BTN8, KC_BTN3, KC_BTN2, KC_BTN1,    U_NA,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,    U_NU,  U_NA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,                      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,    U_NU,  U_NU,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             U_NA,    U_NA,    U_NA,       U_NA,    U_NA,    U_NA
                                      //`--------------------------'  `--------------------------'

  ),
  [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         U_NA, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                         U_NA,    U_NA,    U_NA,    U_NA,    U_NA,  U_NA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         U_NA, KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                         U_NA, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  U_NA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         U_NA, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                          U_NA,    U_NA,    U_NA,    U_NA,    U_NA,  U_NU,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LPRN, KC_RPRN, KC_UNDS,      U_NA,    U_NA,    U_NA
                                      //`--------------------------'  `--------------------------'

  )
};
