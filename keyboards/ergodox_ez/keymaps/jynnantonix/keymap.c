#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  
    QWERTY,
    SYMB,  
    NUMPAD,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_NO, KC_1,    KC_2,    KC_3,          KC_4,            KC_5,   KC_NO,                   KC_NO,         KC_6,    KC_7,      KC_8,          KC_9,   KC_0,  KC_NO,
  KC_NO, KC_SCLN, KC_COMM, KC_DOT,        KC_P,            KC_Y,   KC_NO,                   KC_NO,         KC_F,    KC_G,      KC_C,          KC_R,   KC_L,  KC_NO,
  KC_NO, KC_A,    KC_O,    KC_E,          KC_U,            KC_I,                                           KC_D,    KC_H,      KC_T,          KC_N,   KC_S,  KC_NO,
  KC_NO, KC_QUOT, KC_Q,    KC_J,          KC_K,            KC_X,   OSL(NUMPAD),             KC_ESC,        KC_B,    KC_M,      KC_W,          KC_V,   KC_Z,  KC_NO,
  KC_NO, KC_NO,   KC_NO,   OSM(MOD_LGUI), OSM(MOD_LSFT),                                                            OSL(SYMB), OSM(MOD_LALT), KC_NO,  KC_NO, KC_NO,
                                                           KC_NO,  DF(QWERTY),              LGUI(KC_L),    KC_NO,
                                                                   KC_NO,                   KC_NO,
                                          GUI_T(KC_ENT),   KC_TAB, OSM(MOD_LCTL),           OSM(MOD_LALT), KC_BSPC, KC_SPC
),
/* Keymap 1: Original base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[QWERTY] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_TRNS,        KC_TRNS,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,           KC_MINS,
  KC_TRNS,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_ENT,         TG(SYMB),     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,           KC_BSLS,
  KC_TRNS,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,        GUI_T(KC_QUOT),
  KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_ESC,         LALT(KC_TAB), KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_T(KC_SLSH), KC_RSFT,
  LT(SYMB,KC_GRV), KC_QUOT, KC_TRNS, KC_TRNS, KC_LCTL,                                                KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,       TT(SYMB),
                                                       KC_NO,  DF(BASE),       KC_PGUP,      CTL_T(KC_ESC),
                                                               KC_HOME,        KC_PGDN,
                                              KC_SPC,  KC_TAB, KC_END,         KC_LALT,      KC_BSPC, KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6,   KC_F7,      KC_F8,    KC_F9,   KC_F10,   KC_F11,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_EQL,  KC_TRNS,     KC_TRNS, KC_PGUP, LALT(KC_G), KC_MINUS, KC_BSLS, KC_SLSH,  KC_F12,
  KC_TRNS, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,                       KC_PGDN, KC_LEFT,    KC_DOWN,  KC_UP,   KC_RIGHT, KC_TRNS,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_GRV,  KC_TRNS,     KC_TRNS, KC_TILD, KC_HASH,    KC_DLR,   KC_HOME, KC_END,   KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
[NUMPAD] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                       KC_TRNS, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,                                         KC_0,    KC_DOT,  KC_TRNS, KC_EQL,  KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
