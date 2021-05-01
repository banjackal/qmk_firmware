#include "banjackal.h"

enum custom_keycodes {
    RUNTESTS = SAFE_RANGE,
	FORMAT,
	COVER_ALL,
	COMMENT,
	UNCOMMENT,
	KVM_1,
	KVM_2,
    WIN_TERM,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RUNTESTS:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("ul"));
        } else {
        }
        break;

		case FORMAT:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("kd"));
        } else {
        }
        break;

		case COVER_ALL:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("uk"));
        } else {
        }
        break;

		case COMMENT:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("kc"));
        } else {
        }
        break;

		case UNCOMMENT:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("ku"));
        } else {
        }
        break;

		case KVM_1:
        if (record->event.pressed) {
            tap_code(KC_LCTL);
			tap_code(KC_LCTL);
			tap_code(KC_1);
        } else {
        }
        break;

		case KVM_2:
        if (record->event.pressed) {
			tap_code(KC_LCTL);
			tap_code(KC_LCTL);
			tap_code(KC_2);
        } else {
        }
        break;

        case WIN_TERM:
        if (record->event.pressed) {
			SEND_STRING(SS_LGUI("r") SS_DELAY(200) "wt");
			tap_code(KC_ENT);
        } else {
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_banjackal(
    KC_AT,    KC_QUOT,      KC_COMM,      KC_DOT,       KC_P,           KC_Y,                KC_F,    KC_G,             KC_C,         KC_R,         KC_L,         KC_SLSH, 
    KC_ESC,   LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U),   KC_I,                KC_D,    LSFT_T(KC_H),     LCTL_T(KC_T), LALT_T(KC_N), LGUI_T(KC_S), KC_MINS,
    KC_EXLM,  KC_SCLN,      RALT_T(KC_Q), KC_J,         KC_K,           KC_X,                KC_B,    KC_M,             KC_W,         RALT_T(KC_V), KC_Z,         KC_DLR, 
    U_NP,     U_NP,         U_NP,         KC_INS,       LT(NUM,KC_SPC), LT(MCRO,KC_TAB),     KC_ENT,  LT(SYM,KC_BSPC),  KC_DEL,       U_NP,         U_NP,         U_NP
        ),
  [NUM] = LAYOUT_banjackal(
    U_NA,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,     KC_7,           KC_8,     KC_9,     KC_0, U_NA,
    KC_PSCR,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_CAPS,    KC_LEFT,  KC_DOWN,        KC_UP,    KC_RGHT,  U_NA, U_NA,
    U_NA,     U_NA,     KC_RALT,  U_NA,     U_NA,     U_NA,       KC_HOME,  KC_PGDN,        KC_PGUP,  KC_END,   U_NA, U_NA,
    U_NP,     U_NP,     U_NP,     KC_INS,   KC_TRNS,  KC_TAB,     KC_ENT,   LT(FN,KC_BSPC), KC_DEL,   U_NP,     U_NP, U_NP
        ),
  [SYM] = LAYOUT_banjackal(
    U_NA, U_NA,     KC_EXLM,  KC_LT,    KC_GT,          U_NA,       U_NA,     KC_LBRC,  KC_RBRC,      KC_UNDS,  U_NA,     U_NA,
    U_NA, KC_BSLS,  KC_HASH,  KC_LPRN,  KC_RPRN,        KC_PIPE,    KC_PERC,  KC_LCBR,  KC_RCBR,      KC_EQL,   KC_BSLS,  U_NA,
    U_NA, U_NA,     KC_GRV,   KC_ASTR,  KC_PLUS,        U_NA,       U_NA,     KC_AMPR,  KC_CIRC,      KC_TILD,  U_NA,     U_NA,
    U_NP, U_NP,     U_NP,     U_NA,     LT(FN,KC_SPC),  U_NA,       KC_TRNS,  U_NA,     U_NA,         U_NP,     U_NP,     U_NP
        ),
  [FN] = LAYOUT_banjackal(
    KC_F11, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,
    U_NA,   KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  U_NA,     U_NA,   KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  U_NA,
    U_NA,   U_NA,     KC_RALT,  U_NA,     U_NA,     U_NA,     U_NA,   U_NA,     U_NA,     KC_RALT,  U_NA,     RESET,
    U_NP,   U_NP,     U_NP,     U_NA,     KC_TRNS,  U_NA,     U_NA,   KC_TRNS,  U_NA,     U_NP,     U_NP,     U_NP
        ),
  [MCRO] = LAYOUT_banjackal(
    KVM_1,  U_NA, U_NA,       UNCOMMENT,  COMMENT,    U_NA,       U_NA, U_NA, U_NA,     U_NA, U_NA, U_NA,
    KVM_2,  U_NA, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), U_NA,       U_NA, U_NA, WIN_TERM, U_NA, U_NA, U_NA,
    U_NA,   U_NA, COVER_ALL,  FORMAT,     RUNTESTS,   U_NA,       U_NA, U_NA, U_NA,     U_NA, U_NA, TO(GAME),
    U_NP,   U_NP, U_NP,       U_NA,       U_NA,       KC_TRNS,    U_NA, U_NA, U_NA,     U_NP, U_NP, U_NP
    ),
  [GAME] = LAYOUT_banjackal(
    KC_ESC, KC_Z,     KC_Q, KC_F, KC_E,   KC_G,   U_NA,   U_NA,     U_NA,   U_NA, U_NA, U_NA,
    KC_1,   KC_LSFT,  KC_A, KC_W, KC_D,   KC_T,   U_NA,   U_NA,     U_NA,   U_NA, U_NA, U_NA,
    KC_2,   KC_LCTL,  KC_X, KC_S, KC_C,   KC_B,   U_NA,   U_NA,     U_NA,   U_NA, U_NA, TO(BASE),
    U_NP,   U_NP,     U_NP, KC_3, KC_SPC, KC_R,   KC_ESC, KC_LALT,  KC_TAB, U_NP, U_NP, U_NP
    )
};
