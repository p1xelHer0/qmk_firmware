#include QMK_KEYBOARD_H

#define _BASE_ALT 0
#define _BASE_CMD 1
#define _FN 2
#define _HHKB 3
#define _HHKB_ALT 4
#define _HHKB_CMD 5

enum custom_keycodes {
    TOGGLE_BASE = SAFE_RANGE,
    SE_AA,
    SE_AE,
    SE_OE,
};

char *alt_codes[][2] = {
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_9)),  // Alt + 0229 -> å
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_7)),  // Alt + 0197 -> Å
    },
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_8)),  // Alt + 0228 -> ä
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_6)),  // Alt + 0196 -> Ä
    },
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_6)),  // Alt + 0246 -> ö
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_4)),  // Alt + 0214 -> Ö
    },
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE_ALT] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,  KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
        KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_HHKB_ALT),
        KC_NO,   MO(_FN), KC_LALT,                            KC_SPC,                             KC_NO,   KC_LWIN, MO(_FN), KC_NO
    ),

    [_BASE_CMD] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,  KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
        KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_HHKB_CMD),
        KC_NO,   MO(_FN), KC_LCMD,                            KC_SPC,                             KC_NO,   KC_LALT, MO(_FN), KC_NO
    ),

    [_HHKB] = LAYOUT(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______, _______,
        _______, KC_VOLU, KC_VOLD, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______, TOGGLE_BASE,
        _______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, _______, KC_DOWN, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),

    [_HHKB_ALT] = LAYOUT(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______, _______,
        _______, KC_VOLU, KC_VOLD, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______, DF(_BASE_CMD),
        _______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, _______, KC_DOWN, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),

    [_HHKB_CMD] = LAYOUT(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______, _______,
        _______, KC_VOLU, KC_VOLD, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______, DF(_BASE_ALT),
        _______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, _______, KC_DOWN, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),

    [_FN] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BRID, KC_BRIU,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, SE_AA,   _______, KC_DEL,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, SE_OE,   SE_AE,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MNXT, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            KC_MPLY,                            _______, _______, _______, _______
    ),
    // clang-format on
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    switch (keycode) {
        case TOGGLE_BASE:
            switch (biton32(layer_state)) {
                case _BASE_ALT:
                    set_single_persistent_default_layer(_BASE_CMD);
                    return false;
                case _BASE_CMD:
                    set_single_persistent_default_layer(_BASE_ALT);
                    return false;
                default:
                    return false;
            }

        case SE_AA:
        case SE_AE:
        case SE_OE: {
            uint16_t index = keycode - SE_AA;
            uint8_t  shift = get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));

            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);

            send_string(alt_codes[index][(bool)shift]);

            if (shift & MOD_BIT(KC_LSFT)) register_code(KC_LSFT);
            if (shift & MOD_BIT(KC_RSFT)) register_code(KC_RSFT);

            return false;
        }

        default:
            return true;
    }
}
