#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

// SPANISH DVORAK LAYOUT
// Software layout must be set to spanish qwerty (so you can get 'ñ' and others)
// Includes Auxiliary keys on layer 1 and full qwerty layout on layer 2

// LAYERS
#define BASE 0 // default layout
#define AUX 1 // auxiliary keys
#define QWERTY 2 // qwerty layout

// MACROS
#define OBRACE 0 // key { or shift
#define CBRACE 1 // key } or shift
#define OBRACK 2 // key [ or left alt
#define CBRACK 3 // key ] or left alt
#define CAPS 4 // caps lock

// LEDS
#define USB_LED_NUM_LOCK                0
#define USB_LED_CAPS_LOCK               1
#define USB_LED_SCROLL_LOCK             2
#define USB_LED_COMPOSE                 3
#define USB_LED_KANA                    4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 * Keys with double values (like Esc/Ctrl) correspond to the 'tapped' key and the 'held' key, respectively
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   \    |   1  |   2  |   3  |   4  |   5  |  <>  |           |   ¡  |   6  |   7  |   8  |   9  |   0  |   '    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | F1/~L1 |   .  |   ,  |   Ñ  |   P  |   Y  |MEH_T |           |ALL_T |   F  |   G  |   C  |   H  |   L  | L1/~L1 |
 * |--------+------+------+------+------+------|  +   |           | DEL  |------+------+------+------+------+--------|
 * |Esc/Ctrl|   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   R  |   T  |   N  |   S  |'/RCtrl |
 * |--------+------+------+------+------+------| LGUI |           | RALT |------+------+------+------+------+--------|
 * | {/LSft |   -  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | }/RSft |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |[/LALT| HOME |PGDOWN| PGUP | END  |                                       | LEFT | DOWN |  UP  |RIGHT |]/LALT|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  F5  |  F6  |       |  F7  |  F8  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  F2  |       |  F11 |        |      |
 *                                 | BSPC | TAB  |------|       |------|  ENTER | SPACE|
 *                                 |      |      |F3/Salt|    |F12/Salt|        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = KEYMAP(
        // left hand
        KC_GRAVE,       KC_1,            KC_2,    KC_3,   KC_4,   KC_5,   KC_NONUS_BSLASH,
        LT(AUX, KC_F1),   KC_DOT,          KC_COMM, KC_SCLN,KC_P,   KC_Y,   MEH_T(KC_RBRACKET),
        CTL_T(KC_ESC),  KC_A,            KC_O,    KC_E,   KC_U,   KC_I,
        M(OBRACE),      KC_SLSH,         KC_Q,    KC_J,   KC_K,   KC_X,   KC_LGUI,
        M(OBRACK),      KC_HOME,         KC_PGDN, KC_PGUP,  KC_END,
                                                                    KC_F5,  LT(AUX, KC_F6),
                                                                                 KC_F2,
                                        KC_BSPC,KC_TAB,MT((MOD_LALT | MOD_LSFT), KC_F3),
        // right hand
             KC_EQL,            KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINUS,
             ALL_T(KC_DEL),     KC_F,   KC_G,   KC_C,   KC_H,   KC_L,   KC_FN1,
                                KC_D,   KC_R,   KC_T,   KC_N,   KC_S,   CTL_T(KC_QUOTE),
             KC_RALT,KC_B,      KC_M,   KC_W,   KC_V,   KC_Z,   M(CBRACE),
                                        KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,M(CBRACK),
            KC_F7, KC_F8,
            KC_F11,
            MT(MOD_LALT | MOD_LSFT, KC_F12),KC_ENT, KC_SPC
    ),
/* Keymap 1: Aux layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | SLEEP            | PWR  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |   Up |   7  |   8  |   9  |   *  |  ~L0   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Down |   4  |   5  |   6  |   +  |  `^    |
 * |--------+------+------+------+------+------|      |           |PSCR  |------+------+------+------+------+--------|
 * |CAPSLOCK|      |      |      |      |      |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | Prev | Next |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | VolUp|      |      |
 *                                 |      |      |------|       |------| Play | Stop |
 *                                 |      |      |  L2  |       | VolDn|      |      |
 *                                 `--------------------'       `--------------------'
 */
[AUX] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_SLEP,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       M(CAPS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, TG(QWERTY),
       // right hand
       KC_PWR,  KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_TRNS,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_LBRACKET,
       KC_PSCR, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_MPRV, KC_MNXT,
       KC_VOLU,
       KC_VOLD, KC_MPLY, KC_MSTP
),
/* Keymap 2: QWERTY layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   \    |   1  |   2  |   3  |   4  |   5  |  <>  |           |   ¡  |   6  |   7  |   8  |   9  |   0  |   '    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    F1  |   Q  |   W  |   E  |   R  |   T  |MEH_T |           |ALL_T |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|  +   |           | DEL  |------+------+------+------+------+--------|
 * |Esc/Ctrl|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ñ  |'/RCtrl |
 * |--------+------+------+------+------+------| LGUI |           | RALT |------+------+------+------+------+--------|
 * | {/LSft |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   -  | }/RSft |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |[/LALT| HOME |PGDOWN| PGUP | END  |                                       | LEFT | DOWN |  UP  |RIGHT |]/LALT|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  F5  |  F6  |       |  F7  |  F8  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  F2  |       |  F11 |        |      |
 *                                 | BSPC | TAB  |------|       |------|  ENTER | SPACE|
 *                                 |      |      |  L1  |     |F12/Salt|        |      |
 *                                 `--------------------'       `----------------------'
 */
[QWERTY] = KEYMAP(
        // left hand
        KC_GRAVE,       KC_1,         KC_2,    KC_3,   KC_4,   KC_5,   KC_NONUS_BSLASH,
        LT(AUX, KC_F1),   KC_Q,         KC_W,    KC_E,   KC_R,   KC_T,   MEH_T(KC_RBRACKET),
        CTL_T(KC_ESC),  KC_A,         KC_S,    KC_D,   KC_F,   KC_G,
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
    [1] = ACTION_LAYER_TAP_TOGGLE(AUX)                // FN1 - Momentary Layer 1 (Aux)
};

static uint16_t key_timer;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case OBRACE: {
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
                if (timer_elapsed(key_timer) < 150) {
                    register_code(KC_RALT);
                    register_code(KC_QUOTE);
                    unregister_code(KC_QUOTE);
                    unregister_code(KC_RALT);
                }
            }
            break;
        }
        case CBRACE: {
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_RSFT);
            } else { 
                unregister_code(KC_RSFT);
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
                register_code(KC_LALT);
            } else { 
                unregister_code(KC_LALT);
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
                register_code(KC_LALT);
            } else { 
                unregister_code(KC_LALT);
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
    
    // Turn the caps lock led on
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_1_on();
    }

}

