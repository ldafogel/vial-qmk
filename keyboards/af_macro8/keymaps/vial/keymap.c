// // Add these variables near the top of the file (outside any functions)
// static uint8_t saved_rgb_mode = 0;
// static uint8_t saved_rgb_hue = 0;
// static uint8_t saved_rgb_sat = 0;

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//         case 1:
//             // Save current RGB state before changing (not brightness)
//             saved_rgb_mode = rgb_matrix_get_mode();
//             saved_rgb_hue = rgb_matrix_get_hue();
//             saved_rgb_sat = rgb_matrix_get_sat();
//             // Set all LEDs to red (hue=0, full saturation, keep current brightness)
//             rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
//             rgb_matrix_sethsv_noeeprom(0, 255, rgb_matrix_get_val());
//             break;
//         case 0:
//             // Restore previous RGB state (not brightness)
//             if (saved_rgb_mode != 0) {
//                 rgb_matrix_mode_noeeprom(saved_rgb_mode);
//                 rgb_matrix_sethsv_noeeprom(saved_rgb_hue, saved_rgb_sat, rgb_matrix_get_val());
//             }
//             break;
//     }
//     return state;
// }

// // Add these variables near the top of the file (outside any functions)
// static uint8_t saved_rgb_mode = 0;
// static uint8_t saved_rgb_hue = 0;
// static uint8_t saved_rgb_sat = 0;

// layer_state_t layer_state_set_user(layer_state_t state) {
//     uint8_t highest_layer = get_highest_layer(state);
//     static uint8_t previous_layer = 0;

//     // Entering layer 1 from layer 0
//     if (highest_layer == 1 && previous_layer == 0) {
//         saved_rgb_mode = rgb_matrix_get_mode();
//         saved_rgb_hue = rgb_matrix_get_hue();
//         saved_rgb_sat = rgb_matrix_get_sat();
//         rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
//         rgb_matrix_sethsv_noeeprom(0, 255, rgb_matrix_get_val());
//     }
//     // Exiting layer 1 to layer 0
//     else if (highest_layer == 0 && previous_layer == 1) {
//         uint8_t current_mode = rgb_matrix_get_mode();
//         uint8_t current_hue = rgb_matrix_get_hue();
//         uint8_t current_sat = rgb_matrix_get_sat();

//         // Check if user changed away from red (hue=0, sat=255, solid color mode)
//         if (current_mode != RGB_MATRIX_SOLID_COLOR || current_hue != 0 || current_sat != 255) {
//             // User made changes, use the new state
//             saved_rgb_mode = current_mode;
//             saved_rgb_hue = current_hue;
//             saved_rgb_sat = current_sat;
//         }

//         // Restore the saved state (either old or newly changed)
//         rgb_matrix_mode_noeeprom(saved_rgb_mode);
//         rgb_matrix_sethsv_noeeprom(saved_rgb_hue, saved_rgb_sat, rgb_matrix_get_val());
//     }

//     previous_layer = highest_layer;
//     return state;
// }


enum custom_keycodes {
    AF_RGB_WHITE = QK_KB_0,
    AF_RGB_RED,
    AF_RGB_GREEN,
    AF_RGB_BLUE,
    AF_RGB_EOS,
};

static uint8_t current_layer_colors = 0;

layer_state_t layer_state_set_user(layer_state_t state) {
    current_layer_colors = get_highest_layer(state);
    return state;
}

bool rgb_matrix_indicators_user(void) {
    // Only apply custom colors when not using effects
    if (rgb_matrix_get_mode() == RGB_MATRIX_ALPHAS_MODS || !rgb_matrix_is_enabled()) {
        uint8_t val = rgb_matrix_get_val(); // Get current brightness

        switch(current_layer_colors) {
            case 0:
                rgb_matrix_set_color(0, val, 0, 0);
                rgb_matrix_set_color(1, 0, val, 0);
                rgb_matrix_set_color(2, 0, val, 0);
                rgb_matrix_set_color(3, 0, val, 0);
                rgb_matrix_set_color(4, 0, val, 0);
                rgb_matrix_set_color(5, val, val/2, 0);  // Orange
                rgb_matrix_set_color(6, 0, 0, val);
                rgb_matrix_set_color(7, val, val/2, 0);  // Orange
                break;
            case 1:
                rgb_matrix_set_color_all(val, 0, 0);
                break;
            case 2:
                rgb_matrix_set_color_all(0, val, 0);
                break;
            case 3:
                rgb_matrix_set_color_all(0, 0, val);
                break;
            case 4:
                rgb_matrix_set_color_all(val, val, val);
                break;
        }
    }
    return false;
}

// // Extract color setting into separate functions
// void set_rgb_white(void) {
//     rgb_matrix_set_color_all(255, 255, 255);
// }

// void set_rgb_red(void) {
//     rgb_matrix_set_color_all(255, 0, 0);
// }

// void set_rgb_green(void) {
//     rgb_matrix_set_color_all(0, 255, 0);
// }

// void set_rgb_blue(void) {
//     rgb_matrix_set_color_all(0, 0, 255);
// }

// void set_rgb_eos(void) {
//     rgb_matrix_set_color(0, 255, 0, 0);
//     rgb_matrix_set_color(1, 0, 255, 0);
//     rgb_matrix_set_color(2, 0, 255, 0);
//     rgb_matrix_set_color(3, 0, 255, 0);
//     rgb_matrix_set_color(4, 0, 255, 0);
//     rgb_matrix_set_color(5, 255, 127, 0);
//     rgb_matrix_set_color(6, 0, 0, 255);
//     rgb_matrix_set_color(7, 255, 127, 0);
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case AF_RGB_WHITE:
//             if (record->event.pressed) set_rgb_white();
//             return false;
//         case AF_RGB_RED:
//             if (record->event.pressed) set_rgb_red();
//             return false;
//         case AF_RGB_GREEN:
//             if (record->event.pressed) set_rgb_green();
//             return false;
//         case AF_RGB_BLUE:
//             if (record->event.pressed) set_rgb_blue();
//             return false;
//         case AF_RGB_EOS:
//             if (record->event.pressed) set_rgb_eos();
//             return false;
//     }
//     return true;
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//         case 0:
//             set_rgb_eos();
//             break;
//         case 1:
//             set_rgb_red();
//             break;
//         case 2:
//             set_rgb_green();
//             break;
//         case 3:
//             set_rgb_blue();
//             break;
//         case 4:
//             set_rgb_white();
//             break;
//     }
//     return state;
// }
