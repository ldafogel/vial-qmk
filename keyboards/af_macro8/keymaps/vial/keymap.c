#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, LCTL(KC_C), LCTL(KC_V), LGUI(KC_SPC), KC_APP ),
  [1] = LAYOUT( KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20 ),
  [2] = LAYOUT( _______, _______, _______, _______, _______, _______, _______, _______ ),
  [3] = LAYOUT( _______, _______, _______, _______, _______, _______, _______, _______ )
};

void keyboard_post_init_user(void) {
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD);
    rgblight_sethsv(HSV_CYAN);
}
