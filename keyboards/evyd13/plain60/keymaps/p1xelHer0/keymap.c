#include QMK_KEYBOARD_H

#define PXL_BASE_ALT 0
#define PXL_BASE_CMD 1
#define PXL_FN       2
#define PXL_HHKB     3
#define PXL_HHKB_ALT 4
#define PXL_HHKB_CMD 5

enum custom_keycodes
{
  TOGGLE_BASE = SAFE_RANGE,
};

enum unicode_names
{
  SE_AA_LC,  // å
  SE_AE_LC,  // ä
  SE_OE_LC,  // ö
  SE_AA_UC,  // Å
  SE_AE_UC,  // Ä
  SE_OE_UC,  // Ö
};

const uint32_t PROGMEM unicode_map[] = {
  [SE_AA_LC] = 0x00E5,  // å
  [SE_AE_LC] = 0x00E4,  // ä
  [SE_OE_LC] = 0x00F6,  // ö
  [SE_AA_UC] = 0x00C5,  // Å
  [SE_AE_UC] = 0x00C4,  // Ä
  [SE_OE_UC] = 0x00D6,  // Ö
};

#define D_B_ALT DF(PXL_BASE_ALT)
#define D_B_CMD DF(PXL_BASE_CMD)
#define M_H_ALT MO(PXL_HHKB_ALT)
#define M_H_CMD MO(PXL_HHKB_CMD)
#define M_FN    MO(PXL_FN)
#define TGL_B   TOGGLE_BASE

#define SE_AA UP(SE_AA_LC, SE_AA_UC)
#define SE_AE UP(SE_AE_LC, SE_AE_UC)
#define SE_OE UP(SE_OE_LC, SE_OE_UC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [PXL_BASE_ALT] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,  KC_GRV,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
    KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, M_H_ALT,
    XXXXXXX, M_FN,    KC_LALT,                            KC_SPC,                             XXXXXXX, KC_LWIN, M_FN,    XXXXXXX
  ),

  [PXL_BASE_CMD] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,  KC_GRV,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
    KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, M_H_CMD,
    XXXXXXX, M_FN,    KC_LCMD,                            KC_SPC,                             XXXXXXX,   KC_LALT, M_FN,  XXXXXXX
  ),

  [PXL_HHKB] = LAYOUT(
    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP,   _______, _______,
    _______, KC_VOLU, KC_VOLD, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______, TGL_B,
    _______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, _______, KC_DOWN, _______, _______,
    _______, _______, _______,                            _______,                            _______, _______, _______, _______
  ),

  [PXL_HHKB_ALT] = LAYOUT(
    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP,   _______, _______,
    _______, KC_VOLU, KC_VOLD, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______, D_B_CMD,
    _______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, _______, KC_DOWN, _______, _______,
    _______, _______, _______,                            _______,                            _______, _______, _______, _______
  ),

  [PXL_HHKB_CMD] = LAYOUT(
    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP,   _______, _______,
    _______, KC_VOLU, KC_VOLD, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______, D_B_ALT,
    _______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, _______, KC_DOWN, _______, _______,
    _______, _______, _______,                            _______,                            _______, _______, _______, _______
  ),

  [PXL_FN] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BRID, KC_BRIU,
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, SE_AA,   _______, KC_DEL,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, SE_OE,   SE_AE,   _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MNXT, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                            KC_MPLY,                            _______, _______, _______, _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (!record->event.pressed) return true;
  switch (keycode)
  {
    case TOGGLE_BASE:
      switch (biton32(layer_state))
      {
        case PXL_BASE_ALT:
          set_single_persistent_default_layer(PXL_BASE_CMD);
          set_unicode_input_mode(UNICODE_MODE_MACOS);
          return false;
        case PXL_BASE_CMD:
          set_single_persistent_default_layer(PXL_BASE_ALT);
          set_unicode_input_mode(UNICODE_MODE_WINDOWS);
          return false;
        default:
          return false;
      }

    default:
      return true;
  }
}
