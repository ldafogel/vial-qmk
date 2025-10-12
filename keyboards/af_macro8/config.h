#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xA1F0
#define PRODUCT_ID      0xAF08
#define DEVICE_VER      0x0001
#define MANUFACTURER    AlexFogel
#define PRODUCT         afMacro8

/* Matrix: using direct pins (1 row, 8 columns) */
#define MATRIX_ROWS 1
#define MATRIX_COLS 8

#define DIRECT_PINS { \
    { D1, D0, D4, C6, B5, B4, E6, D7 } \
}

#define DIODE_DIRECTION COL2ROW

/* Debounce */
#define DEBOUNCE 5

/* RGB Underglow / per-key chain */
#define RGB_DI_PIN B6
#define RGBLED_NUM 8
#define RGBLIGHT_LIMIT_VAL 140
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL

/* Vial */
#define VIAL_KEYBOARD_UID { 0x5C, 0xFA, 0xD5, 0x30, 0x9A, 0xE5, 0x44, 0x64 }
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

/* Disable deprecated stuff */
#define NO_ACTION_ONESHOT
