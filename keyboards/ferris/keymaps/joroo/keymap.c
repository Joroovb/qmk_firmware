#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used
  

#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)

enum ferris_layers {
  _QWERTY,
  _NUM,
  _SYM,
  _NAV
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* QWERTY */
    KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,    KC_Y,  KC_U,         KC_I,         KC_O,         KC_P,
    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    KC_H,  LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_QUOT),
    KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,    KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,
                                    KC_SPC, LT(_NAV, KC_TAB), LT(_NUM, KC_ENT), LT(_SYM, KC_BSPC)
  ),

  [_NUM] = LAYOUT(
    KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,   U_NA, U_NA,    U_NA,    U_NA,    U_NA, 
    KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,    U_NA, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_GRV,  KC_1, KC_2, KC_3, KC_BSLS,   U_NA, U_NA,    U_NA,    KC_ALGR, U_NA, 
                       KC_0, KC_MINS, U_NA, U_NA
  ),
  [_NAV] = LAYOUT(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,              U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, U_NA,
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,              KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
                                        U_NA, U_NA, KC_ESC, KC_BSPC
  ),

  [_SYM] = LAYOUT(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,  U_NA, U_NA,    U_NA,    U_NA,    U_NA,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,  U_NA, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,  U_NA, U_NA,    U_NA,    U_NA,    U_NA,
                               KC_LPRN, KC_UNDS, U_NA, U_NA  
  )
};

