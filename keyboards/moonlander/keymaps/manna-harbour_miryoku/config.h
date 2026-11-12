// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define XXX KC_NO

// Extra moonlander-only layers appended after the standard miryoku layers:
//   QWERTY - a regular full-size QWERTY layout (thumb keys arranged like the
//            glove80 default layer in miryoku_zmk)
//   QWFN   - function / media / numpad layer, held from QWERTY
#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base") \
MIRYOKU_X(EXTRA,  "Extra") \
MIRYOKU_X(TAP,    "Tap") \
MIRYOKU_X(BUTTON, "Button") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Mouse") \
MIRYOKU_X(MEDIA,  "Media") \
MIRYOKU_X(NUM,    "Num") \
MIRYOKU_X(SYM,    "Sym") \
MIRYOKU_X(FUN,    "Fun") \
MIRYOKU_X(QWERTY, "Qwerty") \
MIRYOKU_X(QWFN,   "Qwerty Fn")

// Pressing both red thumb keys together (a combo, see keymap.c) toggles
// between miryoku and QWERTY. On their own the red keys do nothing, so a stray
// press is harmless. QWERTY sits above all the miryoku layers, so toggling it
// off drops back to whichever miryoku base layer was active.
#define U_RED_L QK_USER_0
#define U_RED_R QK_USER_1

#define COMBO_COUNT 1
#define COMBO_TERM 100

#define LAYOUT_miryoku(\
     K00, K01, K02, K03, K04,               K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,               K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,               K25, K26, K27, K28, K29,\
     N30, N31, K32, K33, K34,               K35, K36, K37, N38, N39\
)\
LAYOUT_moonlander(\
XXX, XXX, XXX, XXX, XXX, XXX, XXX,     XXX, XXX, XXX, XXX, XXX, XXX, XXX,\
XXX, K00, K01, K02, K03, K04, XXX,     XXX, K05, K06, K07, K08, K09, XXX,\
XXX, K10, K11, K12, K13, K14, XXX,     XXX, K15, K16, K17, K18, K19, XXX,\
XXX, K20, K21, K22, K23, K24,               K25, K26, K27, K28, K29, XXX,\
XXX, XXX, XXX, XXX, K32,      U_RED_L, U_RED_R,  K37, XXX, XXX, XXX, XXX,\
                    K33, K34, XXX,     XXX, K35, K36\
)

// QWERTY
//
// ,------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------.
// |  =   |  1   |  2   |  3   |  4   |  5   | BSPC |  | PGUP |  6   |  7   |  8   |  9   |  0   |  -   |
// |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
// | TAB  |  Q   |  W   |  E   |  R   |  T   | ENT  |  | PGDN |  Y   |  U   |  I   |  O   |  P   |  \   |
// |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
// | ESC  |  A   |  S   |  D   |  F   |  G   | LGUI |  | RCTL |  H   |  J   |  K   |  L   |  ;   |  '   |
// |------+------+------+------+------+------+------'  `------+------+------+------+------+------+------|
// | LSFT |  Z   |  X   |  C   |  V   |  B   |                |  N   |  M   |  ,   |  .   |  /   | RSFT |
// |------+------+------+------+------+------'                `------+------+------+------+------+------|
// |  `   | HOME | END  | LEFT | RGHT |  ,------.    ,------.  |  UP  | DOWN |  [   |  ]   |  FN  |
// `----------------------------------'  | RED  |    | RED  |  `----------------------------------'
//                                       `------'    `------'
//                             ,------+------+------.  ,------+------+------.
//                             | SPC  | LCTL | LALT |  | RALT |  FN  | DEL  |
//                             `------+------+------'  `------+------+------'
//
// RED+RED (both together) = back to miryoku. FN = hold for the QWFN layer.
#define MIRYOKU_LAYERMAPPING_QWERTY LAYOUT_moonlander
#define MIRYOKU_LAYER_QWERTY \
KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC,     KC_PGUP, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ENT,      KC_PGDN, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LGUI,     KC_RCTL, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
KC_GRV,  KC_HOME, KC_END,  KC_LEFT, KC_RGHT,          U_RED_L,     U_RED_R,          KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(U_QWFN), \
                                    KC_SPC,  KC_LCTL, KC_LALT,     KC_RALT, MO(U_QWFN), KC_DEL

// QWFN (held from QWERTY; blank keys fall through to QWERTY)
//
// ,------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------.
// |      |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |  | F12  |  F6  |  F7  |  F8  |  F9  | F10  |      |
// |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
// |      | PREV |  UP  | NEXT | HOME | PGUP |      |  |      |  /   |  7   |  8   |  9   |  -   | PSCR |
// |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
// |      | LEFT | DOWN | RGHT | END  | PGDN |      |  |      |  *   |  4   |  5   |  6   |  +   | SLCK |
// |------+------+------+------+------+------+------'  `------+------+------+------+------+------+------|
// |      | MUTE | VOL- | VOL+ | PLAY | MENU |                |  ,   |  1   |  2   |  3   | ENT  |      |
// |------+------+------+------+------+------'                `------+------+------+------+------+------|
// | CAPS | INS  | BRI- | BRI+ | PAUS |  ,------.    ,------.  |  0   |  .   | NUM  |  =   |      |
// `----------------------------------'  |      |    |      |  `----------------------------------'
//                                       `------'    `------'
//                             ,------+------+------.  ,------+------+------.
//                             |      |      |      |  |      |      |      |
//                             `------+------+------'  `------+------+------'
#define MIRYOKU_LAYERMAPPING_QWFN LAYOUT_moonlander
#define MIRYOKU_LAYER_QWFN \
KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,      KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS, \
KC_TRNS, KC_MPRV, KC_UP,   KC_MNXT, KC_HOME, KC_PGUP, KC_TRNS,     KC_TRNS, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PSCR, \
KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PGDN, KC_TRNS,     KC_TRNS, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_SCRL, \
KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_APP,                        KC_PCMM, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_TRNS, \
KC_CAPS, KC_INS,  KC_BRID, KC_BRIU, KC_PAUS,          KC_TRNS,     KC_TRNS,          KC_P0,   KC_PDOT, KC_NUM,  KC_PEQL, KC_TRNS, \
                                    KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
