#include QMK_KEYBOARD_H

#define _LAYER0 0

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT(
                    KC_NO,
                    KC_NO,
                    KC_NO, KC_NO,
                    KC_NO, KC_NO,
                    KC_NO, KC_NO,
                    KC_NO, KC_NO,
                    KC_NO, KC_NO,
                    KC_NO, KC_NO,
                    KC_NO, KC_NO,
                    KC_NO, KC_NO)

};
