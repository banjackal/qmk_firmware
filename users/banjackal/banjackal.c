// generated from users/manna-harbour_miryoku/miryoku.org  -*- buffer-read-only: t -*-

#include "banjackal.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
    KC_EXLM,  KC_SCLN,      KC_COMM,      KC_DOT,       KC_P,           KC_Y,                KC_F,    KC_G,             KC_C,         KC_R,         KC_L,         KC_SLSH, 
    KC_ESC,   LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U),   KC_I,                KC_D,    LSFT_T(KC_H),     LCTL_T(KC_T), LALT_T(KC_N), LGUI_T(KC_S), KC_MINS,
    KC_AT,    KC_QUOT,      RALT_T(KC_Q), KC(J),        KC_K,           KC_X,                KC_B,    KC_M,             KC_W,         RALT_T(KC_V), KC_Z,         KC_DLR, 
    U_NO,     U_NO,         U_NO,         KC_INS,       LT(NUM,KC_SPC), LT(MCRO,KC_TAB),     KC_ENT,  LT(SYM,KC_BSPC),  KC_DEL,       U_NO,         U_NO,         U_NO
        ),
	[NUM] = LAYOUT_split_3x6_3(
    U_NA,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,     KC_7,           KC_8,     KC_9,     KC_0, U_NA,
    KC_PSCR,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_CAPS,    KC_LEFT,  KC_DOWN,        KC_UP,    KC_RGHT,  U_NA, U_NA,
    U_NA,     U_NA,     KC_RALT,  U_NA,     U_NA,     U_NA,       KC_HOME,  KC_PGDN,        KC_PGUP,  KC_END,   U_NA, U_NA,
    U_NO,     U_NO,     U_NO,     KC_INS,   KC_TRNS,  KC_TAB,     KC_ENT,   LT(FN,KC_BSPC), KC_DEL,   U_NO,     U_NO, U_NO
        ),
	[SYM] = LAYOUT_split_3x6_3(
    U_NA, U_NA,     KC_EXLM,  KC_LT,    KC_GT,          U_NA,       U_NA,     KC_LBRC,  KC_RBRC,      KC_UNDS,  U_NA,     U_NA,
    U_NA, KC_BSLS,  KC_HASH,  KC_LPRN,  KC_RPRN,        KC_PIPE,    KC_PERC,  KC_LCBR,  KC_RCBR,      KC_EQL,   KC_BSLS,  U_NA,
    U_NA, U_NA,     KC_GRV,   KC_ASTR,  KC_PLUS,        U_NA,       U_NA,     KC_AMPR,  KC_CIRC,      KC_TILD,  U_NA,     U_NA,
    U_NO, U_NO,     U_NO,     U_NA,     LT(FN,KC_SPC),  U_NA,       KC_TRNS,  U_NA,     U_NA,         U_NO,     U_NO,     U_NO
        ),
	[FN] = LAYOUT_split_3x6_3(
    KC_F11, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,
    U_NA,   KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  U_NA,     U_NA,   KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  U_NA,
    U_NA,   U_NA,     KC_RALT,  U_NA,     U_NA,     U_NA,     U_NA,   U_NA,     U_NA,     KC_RALT,  U_NA,     RESET,
    U_NO,   U_NO,     U_NO,     U_NA,     KC_TRNS,  U_NA,     U_NA,   KC_TRNS,  U_NA,     U_NO,     U_NO,     U_NO
        ),
	[MCRO] = LAYOUT_split_3x6_3(
    KVM_1,  U_NA, U_NA,       UNCOMMENT,  COMMENT,    U_NA,       U_NA, U_NA, U_NA,     U_NA, U_NA, U_NA,
    KVM_2,  U_NA, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), U_NA,       U_NA, U_NA, WIN_TERM, U_NA, U_NA, U_NA,
    U_NA,   U_NA, COVER_ALL,  FORMAT,     RUNTESTS,   U_NA,       U_NA, U_NA, U_NA,     U_NA, U_NA, TO(GAME),
    U_NO,   U_NO, U_NO,       U_NA,       U_NA,       KC_TRNS,    U_NA, U_NA, U_NA,     U_NO, U_NO, U_NO
    ),
	[GAME] = LAYOUT_split_3x6_3(
    KC_ESC, KC_Z,     KC_Q, KC_F, KC_E,   KC_G,   U_NA,   U_NA,     U_NA,   U_NA, U_NA, U_NA,
    KC_1,   KC_LSFT,  KC_A, KC_W, KC_D,   KC_T,   U_NA,   U_NA,     U_NA,   U_NA, U_NA, U_NA,
    KC_2,   KC_LCTL,  KC_X, KC_S, KC_C,   KC_B,   U_NA,   U_NA,     U_NA,   U_NA, U_NA, TO(BASE),
    U_NO,   U_NO,     U_NO, KC_3, KC_SPC, KC_R,   KC_ESC, KC_LALT,  KC_TAB, U_NO, U_NO, U_NO
    )
};
