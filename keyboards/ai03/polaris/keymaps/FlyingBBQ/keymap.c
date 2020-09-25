#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FN,
    _AR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_all
    (
         KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSLS, KC_GRAVE,
         KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSPC,
         KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
         KC_LSFT, KC_NO  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, MO(_FN),
         KC_NO  , MO(_FN), KC_LGUI, KC_NO  , KC_SPC , KC_NO  , KC_NO  , KC_LEAD, KC_LALT, KC_NO
    ),
    [_FN] = LAYOUT_all
    (
         _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______,
         _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_DEL ,
         KC_CAPS, KC_HOME, KC_PGDN, KC_END , _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______, _______,
         _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, KC_PSCR, _______,
         _______, _______, _______, _______, _______, _______, _______, _______, KC_RALT, _______
    ),
    [_AR] = LAYOUT_all
    (
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______, _______,
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

void keyboard_post_init_user(void)
{
    rgblight_enable_noeeprom(); // Enables RGB, without saving settings
    rgblight_sethsv_noeeprom(HSV_BLUE); // Sets the color without saving
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

LEADER_EXTERNS();
void matrix_scan_user(void)
{
    LEADER_DICTIONARY() {
        leading = false;

        SEQ_TWO_KEYS(KC_G, KC_H) {
            SEND_STRING("https://www.github.com/FlyingBBQ\n");
        }
        SEQ_TWO_KEYS(KC_G, KC_L) {
            SEND_STRING("https://gitlab.com/FlyingBBQ\n");
        }
        SEQ_TWO_KEYS(KC_M, KC_K) {
            SEND_STRING("https://www.reddit.com/r/MechanicalKeyboards/\n");
        }
        // Put the keyboard into reset mode
        SEQ_THREE_KEYS(KC_R, KC_R, KC_R) {
            rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(HSV_RED);
            reset_keyboard();
        }
        // Toggle the _AR layer
        SEQ_TWO_KEYS(KC_A, KC_R) {
            if (IS_LAYER_ON(_AR)) {
                layer_off(_AR);
                keyboard_post_init_user();
            } else {
                layer_on(_AR);
                rgblight_enable_noeeprom();
                rgblight_sethsv_noeeprom(HSV_YELLOW);
            }
        }

        leader_end();
    }
}
