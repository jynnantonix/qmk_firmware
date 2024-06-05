// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// enum layer_names {
//     _QW,
//     _RS,
//     _LW,
// };

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//   [_QW] = LAYOUT( /* Qwerty */
//     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
//     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
//     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,  KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
//     KC_ESC, KC_TAB, KC_LGUI,  KC_LSFT, KC_BSPC,  KC_LCTL, KC_LALT, KC_SPC,  MO(_RS), KC_MINS, KC_QUOT, KC_ENT ),

//   [_RS] = LAYOUT( /* [> RAISE <] */
//     KC_EXLM, KC_AT,   KC_UP,   KC_DLR,  KC_PERC,                  KC_PGUP, KC_7,    KC_8,   KC_9, KC_BSPC,
//     KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN,                  KC_PGDN, KC_4,    KC_5,   KC_6, KC_BSLS,
//     KC_LBRC, KC_RBRC, KC_HASH, KC_LCBR, KC_RCBR, KC_CIRC, KC_AMPR,KC_ASTR, KC_1,    KC_2,   KC_3, KC_PLUS,
//     TG(_LW), KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT,KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL ),
    
//   [_LW] = LAYOUT( /* [> LOWER <] */
//     KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
//     KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
//     KC_NO,   KC_VOLU, KC_NO,   KC_NO,   QK_BOOT,   _______, _______, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
//     KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(_QW), KC_PSCR, KC_SCRL, KC_PAUS )
// };

enum layer_names {
  DV,
  SYM,
  NUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DV] = LAYOUT( /* Qwerty */
    KC_SCLN,        CTL_T(KC_COMM), KC_DOT,  KC_P,          KC_Y,                         KC_F,    KC_G,     KC_C,    KC_R,    KC_L,  
    KC_A,           KC_O,           KC_E,    KC_U,          KC_I,                         KC_D,    KC_H,     KC_T,    KC_N,    KC_S,                                          
    GUI_T(KC_QUOT), KC_Q,           KC_J,    KC_K,          KC_X,    OSL(NUM),   KC_ESC,  KC_B,    KC_M,     KC_W,    KC_V,    GUI_T(KC_Z),  
    LALT(KC_TAB),   KC_TRNS,        KC_TRNS, OSM(MOD_LSFT), KC_ENT,  KC_TAB,     KC_BSPC, KC_SPC,  OSL(SYM), KC_TRNS, KC_TRNS, OSM(MOD_LALT) ),
  [SYM] = LAYOUT( 
    KC_EXLM,        KC_AT,   KC_LCBR, KC_RCBR,       KC_EQL,                       KC_PGUP, LALT(KC_G), KC_MINUS, KC_BSLS, KC_SLSH,  
    KC_AMPR,        KC_ASTR, KC_LPRN, KC_RPRN,       KC_UNDS,                      KC_PGDN, KC_LEFT,    KC_DOWN,  KC_UP,   KC_RIGHT, 
    KC_PERC,        KC_CIRC, KC_LBRC, KC_RBRC,       KC_GRV,  KC_TRNS,    KC_TRNS, KC_TILD, KC_HASH,    KC_DLR,   KC_HOME, KC_END,    
    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS ),
  [NUM] = LAYOUT( 
    KC_TRNS,        KC_TRNS, KC_MS_U, KC_TRNS,       KC_TRNS,                      KC_TRNS, KC_7,    KC_8,    KC_9,    KC_ASTR, 
    KC_TRNS,        KC_MS_L, KC_MS_D, KC_MS_R,       KC_TRNS,                      KC_TRNS, KC_4,    KC_5,    KC_6,    KC_PLUS, 
    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_BSLS, 
    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,       KC_BTN1, KC_BTN2,    KC_TRNS, KC_TRNS, KC_0,    KC_TRNS, KC_TRNS, KC_EQL )
};
