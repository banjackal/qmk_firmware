    #include "banjackal.h"

    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_banjackal(
        U_NA,  KC_QUOT,         KC_COMM,      KC_DOT,       KC_P,           KC_Y,                   KC_F,    KC_G,          KC_C,         KC_R,         KC_L,         U_NA,
        U_NA,  KC_A,            KC_O,         KC_E,         KC_U,           KC_I,                   KC_D,    KC_H,          KC_T,         KC_N,         KC_S,         U_NA,
        U_NA,  LSFT_T(KC_SCLN), LCTL_T(KC_Q), LALT_T(KC_J), LGUI_T(KC_K),   KC_X,                   KC_B,    LGUI_T(KC_M),  LALT_T(KC_W), LCTL_T(KC_V), LSFT_T(KC_Z), U_NA,
        U_NP,  U_NP,  U_NP,         U_NA,     U_NA,         U_NA,                      LT(NUM,KC_BSPC),  LT(SYM,KC_SPC),  MO(FN),       U_NP,         U_NP,         U_NP
            ),
    [NUM] = LAYOUT_banjackal(
        U_NA,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,     KC_7,           KC_8,     KC_9,     KC_0, U_NA,
        U_NA,  U_NA,     U_NA,     U_NA,     U_NA,     U_NA,       KC_LEFT,  KC_DOWN,        KC_UP,    KC_RGHT,  U_NA, U_NA,
        U_NA,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  U_NA,       KC_HOME,  KC_PGDN,        KC_PGUP,  KC_END,   U_NA, U_NA,
        U_NP,  U_NP,     U_NP,     U_NA,     U_NA,     U_NA,       KC_TRNS,  U_NA, U_NA,   U_NP,     U_NP, U_NP
            ),
    [SYM] = LAYOUT_banjackal(
        U_NA, KC_EXLM,  KC_AT,    KC_LT,    KC_GT,    LAMBDA,       U_NA,     KC_LBRC,  KC_RBRC,      KC_UNDS,  KC_SLSH,  U_NA,
        U_NA, KC_BSLS,  KC_HASH,  KC_LPRN,  KC_RPRN,  KC_PIPE,      KC_PERC,  KC_LCBR,  KC_RCBR,      KC_EQL,   KC_MINS,  U_NA,
        U_NA, KC_QUES,  KC_GRV,   KC_ASTR,  KC_PLUS,  U_NA,         U_NA,     KC_AMPR,  KC_CIRC,      KC_TILD,  KC_DLR,   U_NA,
        U_NP, U_NP,     U_NP,     U_NA,     U_NA,     U_NA,         KC_TRNS,    U_NA,     U_NA,     U_NP,         U_NP,     U_NP
            ),
    [FN] = LAYOUT_banjackal(
        U_NA,   KC_F1,    KC_F2,    KC_F3,       KC_F4,     KC_F5,    KC_F6,  KC_F7,    KC_F8,    KC_F9,   KC_F10,    U_NA,
        U_NA,   KC__MUTE, U_NA,     KC__VOLDOWN, KC__VOLUP, KC_F11,   KC_F12, U_NA,     U_NA,     U_NA,    KC_PSCR,   U_NA,
        U_NA,   KC_LSFT,  KC_LCTL,  KC_LALT,     KC_LGUI,   U_NA,     U_NA,   KC_LGUI,  KC_LALT,  KC_LCTL, KC_LSFT,   U_NA,
        U_NP,   U_NP,     U_NP,     U_NA,        U_NA,      U_NA,       U_NA,   U_NA,  KC_TRNS,     U_NP,     U_NP,   U_NP
            ),
    [GAME] = LAYOUT_banjackal(
        U_NA,  KC_Z,    KC_Q,       KC_F,       KC_E,    KC_G,      U_NA, U_NA, U_NA,     U_NA, KC_1,     U_NA,
        U_NA,  KC_LSFT, KC_A,       KC_W,       KC_D,    KC_T,      U_NA, U_NA, U_NA,     U_NA, KC_2,     U_NA,
        U_NA,  KC_LCTL, KC_X,       KC_S,       KC_C,    KC_B,      U_NA, U_NA, U_NA,     U_NA, KC_3,     U_NA,
        U_NP,  U_NP,    U_NP,       KC_ESC,     KC_SPC,    KC_R,      KC_TRNS, KC_TRNS, KC_TRNS,     U_NP, U_NP,     U_NP
        ),
    };
