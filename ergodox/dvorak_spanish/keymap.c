#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define QWERTY 2 // media keys

#define OBRACE 0 // macro press key { or shift
#define CBRACE 1 // macro press key } or shift
#define OBRACK 2 // macro press key [ or alt
#define CBRACK 3 // macro press key ] or alt
#define CAPS 4 // caps lock macro

/* keyboard LEDs */
#define USB_LED_NUM_LOCK                0
#define USB_LED_CAPS_LOCK               1
#define USB_LED_SCROLL_LOCK             2
#define USB_LED_COMPOSE                 3
#define USB_LED_KANA                    4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   '  |   ,  |   .  |   P  |   Y  |  L1  |           |  L1  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |S / L2|   -    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |:/Ctrl|   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
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
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRAVE,       KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_NONUS_BSLASH,
        LT(1, KC_F1),   KC_DOT,          KC_COMM, KC_SCLN, KC_P,   KC_Y,   MEH_T(KC_RBRACKET),
        CTL_T(KC_ESC),  KC_A,            KC_O,    KC_E,   KC_U,   KC_I,
        M(OBRACE),      KC_SLSH,         KC_Q,    KC_J,   KC_K,   KC_X,   KC_LGUI,
        M(OBRACK),      KC_HOME,      KC_PGDN,  KC_PGUP,  KC_END,
                                                                    KC_F5,  LT(1, KC_F6),
                                                                                 KC_F2,
                                        KC_BSPC,KC_TAB,MT((MOD_LALT | MOD_LSFT), KC_F3),
        // right hand
             KC_EQL,            KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINUS,
             ALL_T(KC_DEL),     KC_F,   KC_G,   KC_C,   KC_H,   KC_L,   KC_FN1,
                                KC_D,   KC_R,   KC_T,   KC_N,   KC_S,   CTL_T(KC_QUOTE),
             KC_RALT,KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,   M(CBRACE),
                                        KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,M(CBRACK),
            KC_F7, KC_F8,
            KC_F11,
            MT(MOD_LALT | MOD_LSFT, KC_F12),KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_SLEP,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       M(CAPS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, TG(2),
       // right hand
       KC_PWR, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_TRNS,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_LBRACKET,
       KC_PSCR, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_MPRV, KC_MNXT,
       KC_VOLU,
       KC_VOLD, KC_MPLY, KC_MSTP
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// QWERTY LAYER
[QWERTY] = KEYMAP(
        // left hand
        KC_GRAVE,       KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_NONUS_BSLASH,
        LT(1, KC_F1),   KC_Q,          KC_W, KC_E, KC_R,   KC_T,   MEH_T(KC_RBRACKET),
        CTL_T(KC_ESC),  KC_A,            KC_S,    KC_D,   KC_F,   KC_G,
        M(OBRACE),      KC_Z,         KC_X,    KC_C,   KC_V,   KC_B,   KC_LGUI,
        M(OBRACK),      KC_HOME,      KC_PGDN,  KC_PGUP,  KC_END,
                                                                          KC_F5,  KC_F6,
                                                                                 KC_F2,
                                                                  KC_BSPC,KC_TAB,KC_TRNS,
        // right hand
             KC_EQL,            KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINUS,
             ALL_T(KC_DEL),     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_FN1,
                                KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   CTL_T(KC_QUOTE),
            KC_RALT,KC_N,   KC_M,   KC_COMM,   KC_DOT,   KC_SLSH,   M(CBRACE),
                                        KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,M(CBRACK),
            KC_F7, KC_F8,
            KC_F11,
            MT(MOD_LALT | MOD_LSFT, KC_F12),KC_ENT, KC_SPC
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

static uint16_t key_timer;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case OBRACE: {
            if (record->event.pressed) {
                key_timer = timer_read(); // if the key is being pressed, we start the timer.
                register_code(KC_RSFT); // we're now holding down Shift.
            } else { // this means the key was just released, so we can figure out how long it was pressed for (tap or "held down").
                unregister_code(KC_RSFT); // let's release the Shift key now.
                if (timer_elapsed(key_timer) < 150) { // 150 being 150ms, the threshhold we pick for counting something as a tap. 
                    register_code(KC_RALT); // we're now holding down Shift.
                    register_code(KC_QUOTE); // sending 9 while Shift is held down gives us an opening paren
                    unregister_code(KC_QUOTE); // now let's let go of that key
                    unregister_code(KC_RALT); // let's release the Shift key now.
                }
            }
            break;
        }
        case CBRACE: {
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_RSFT); // we're now holding down Shift.
            } else { 
                unregister_code(KC_RSFT); // let's release the Shift key now.
                if (timer_elapsed(key_timer) < 150) { 
                    register_code(KC_RALT); 
                    register_code(KC_BSLS); 
                    unregister_code(KC_BSLS); 
                    unregister_code(KC_RALT); 
                }
            }
            break;
        }
        case OBRACK: {
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_LALT); // we're now holding down Shift.
            } else { 
                unregister_code(KC_LALT); // let's release the Shift key now.
                if (timer_elapsed(key_timer) < 150) { 
                    register_code(KC_RALT); 
                    register_code(KC_LBRACKET); 
                    unregister_code(KC_LBRACKET); 
                    unregister_code(KC_RALT); 
                }
            }
            break;
        }
        case CBRACK: {
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_LALT); // we're now holding down Shift.
            } else { 
                unregister_code(KC_LALT); // let's release the Shift key now.
                if (timer_elapsed(key_timer) < 150) { 
                    register_code(KC_RALT); 
                    register_code(KC_RBRACKET); 
                    unregister_code(KC_RBRACKET); 
                    unregister_code(KC_RALT); 
                }
            }
            break;
        }
        case CAPS: {
            if (record->event.pressed) {
                register_code(KC_CAPSLOCK);
            } else { 
                unregister_code(KC_CAPSLOCK);
            }
            break;
        }
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_3_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
    
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_1_on();
    }

}

