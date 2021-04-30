#include QMK_KEYBOARD_H
#include "version.h"

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
	[0] = LAYOUT_ergodox_pretty(
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    //,------------------------------------------------------------------------------.                         ,-------------------------------------------------------------------------------.
        KC_EXLM,      KC_SCLN,      KC_COMM,       KC_DOT,         KC_P,         KC_Y,KC_TRNS,          KC_TRNS,          KC_F,         KC_G,         KC_C,         KC_R,         KC_L, KC_SLSH,
    //|--------+-------------+-------------+-------------+-------------+-------------|                         |--------------+-------------+-------------+-------------+-------------+--------|
         KC_ESC, LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U),         KC_I,                                    KC_D, LSFT_T(KC_H), LCTL_T(KC_T), LALT_T(KC_N), LGUI_T(KC_S), KC_MINS,
    //|--------+-------------+-------------+-------------+-------------+-------------|                         |--------------+-------------+-------------+-------------+-------------+--------|
          KC_AT,      KC_QUOT, RALT_T(KC_Q),         KC_J,         KC_K,         KC_X,KC_TRNS,          KC_TRNS,          KC_B,         KC_M,         KC_W, RALT_T(KC_V),         KC_Z,  KC_DLR,
    //|--------+-------------+-------------+-------------+-------------+-------------+-------------|  |--------+--------------+-------------+-------------+-------------+-------------+--------|
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                         KC_INS,                                                              KC_DEL,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                 //`---------------------------------------'  `-------------------------------------'
        //thumb clusters
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,              LT(1,KC_SPC), LT(4,KC_TAB),
        KC_TRNS,KC_TRNS,                                                                                KC_ENT, LT(2,KC_BSPC)
        ),
	[1] = LAYOUT_ergodox_pretty(
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    //,------------------------------------------------------------------------------.                         ,-------------------------------------------------------------------------------.
         KC_NO,          KC_1,         KC_2,         KC_3,         KC_4,         KC_5,KC_TRNS,          KC_TRNS,          KC_6,         KC_7,         KC_8,         KC_9,         KC_0,   KC_NO,
    //|--------+-------------+-------------+-------------+-------------+-------------|                         |--------------+-------------+-------------+-------------+-------------+--------|
        KC_PSCR,      KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,      KC_CAPS,                                 KC_LEFT,      KC_DOWN,        KC_UP,      KC_RGHT,        KC_NO,   KC_NO,
    //|--------+-------------+-------------+-------------+-------------+-------------|                         |--------------+-------------+-------------+-------------+-------------+--------|
          KC_NO,        KC_NO,      KC_RALT,        KC_NO,        KC_NO,        KC_NO,KC_TRNS,          KC_TRNS,       KC_HOME,      KC_PGDN,      KC_PGUP,       KC_END,        KC_NO,   KC_NO,
    //|--------+-------------+-------------+-------------+-------------+-------------+-------------|  |--------+--------------+-------------+-------------+-------------+-------------+--------|
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                         KC_INS,                                                              KC_DEL,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                 //`---------------------------------------'  `-------------------------------------'
        //thumb clusters
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                      KC_TRNS,       KC_TAB,
        KC_TRNS,KC_TRNS,                                                                                KC_ENT, LT(3,KC_BSPC)
        ),
	[2] = LAYOUT_ergodox_pretty(
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    //,------------------------------------------------------------------------------.                         ,-------------------------------------------------------------------------------.
          KC_NO,        KC_NO,      KC_EXLM,        KC_LT,        KC_GT,        KC_NO,KC_TRNS,          KC_TRNS,         KC_NO,      KC_LBRC,      KC_RBRC,      KC_UNDS,        KC_NO,   KC_NO,
    //|--------+-------------+-------------+-------------+-------------+-------------|                         |--------------+-------------+-------------+-------------+-------------+--------|
          KC_NO,      KC_BSLS,      KC_HASH,      KC_LPRN,      KC_RPRN,      KC_PIPE,                                 KC_PERC,      KC_LCBR,      KC_RCBR,       KC_EQL,      KC_BSLS,   KC_NO,
    //|--------+-------------+-------------+-------------+-------------+-------------|                         |--------------+-------------+-------------+-------------+-------------+--------|
          KC_NO,        KC_NO,       KC_GRV,      KC_ASTR,      KC_PLUS,        KC_NO,KC_TRNS,          KC_TRNS,         KC_NO,      KC_AMPR,      KC_CIRC,      KC_TILD,        KC_NO,   KC_NO,
    //|--------+-------------+-------------+-------------+-------------+-------------+-------------|  |--------+--------------+-------------+-------------+-------------+-------------+--------|
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                          KC_NO,                                                               KC_NO,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                 //`---------------------------------------'  `-------------------------------------'
        //thumb clusters
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                 LT(3,KC_SPC),        KC_NO,
        KC_TRNS,KC_TRNS,                                                                                KC_TRNS,         KC_NO
        ),
	[3] = LAYOUT_ergodox_pretty(
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    //,------------------------------------------------------------------------------.                         ,-------------------------------------------------------------------------------.
         KC_F11,        KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,KC_TRNS,          KC_TRNS,         KC_F6,        KC_F7,        KC_F8,        KC_F9,       KC_F10,  KC_F12,
    //|--------+-------------+-------------+-------------+-------------+-------------|                         |--------------+-------------+-------------+-------------+-------------+--------|
          KC_NO,      KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,        KC_NO,                                   KC_NO,      KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,   KC_NO,
    //|--------+-------------+-------------+-------------+-------------+-------------|                         |--------------+-------------+-------------+-------------+-------------+--------|
          KC_NO,        KC_NO,      KC_RALT,        KC_NO,        KC_NO,        KC_NO,KC_TRNS,          KC_TRNS,         KC_NO,        KC_NO,        KC_NO,      KC_RALT,        KC_NO,   RESET,
    //|--------+-------------+-------------+-------------+-------------+-------------+-------------|  |--------+--------------+-------------+-------------+-------------+-------------+--------|
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                          KC_NO,                                                               KC_NO,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                 //`---------------------------------------'  `-------------------------------------'
        //thumb clusters
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                 KC_TRNS,        KC_NO,      
        KC_TRNS,KC_TRNS,                                                                                KC_NO,       KC_TRNS
        ),
	[4] = LAYOUT_ergodox_pretty(
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    //,------------------------------------------------------------------------------.                         ,-------------------------------------------------------------------------------.
          KVM_1,        KC_NO,        KC_NO,    UNCOMMENT,      COMMENT,        KC_NO,KC_TRNS,          KC_TRNS,         KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,   KC_NO,
    //|--------+-------------+-------------+-------------+-------------+-------------|                         |--------------+-------------+-------------+-------------+-------------+--------|
          KVM_2,        KC_NO,   LCTL(KC_X),   LCTL(KC_C),   LCTL(KC_V),        KC_NO,                                   KC_NO,        KC_NO,     WIN_TERM,        KC_NO,        KC_NO,   KC_NO,
    //|--------+-------------+-------------+-------------+-------------+-------------|                         |--------------+-------------+-------------+-------------+-------------+--------|
          KC_NO,        KC_NO,    COVER_ALL,       FORMAT,     RUNTESTS,        KC_NO,KC_TRNS,          KC_TRNS,         KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,   TO(5),
    //|--------+-------------+-------------+-------------+-------------+-------------+-------------|  |--------+--------------+-------------+-------------+-------------+-------------+--------|
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                          KC_NO,                                                               KC_NO,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                 //`---------------------------------------'  `-------------------------------------'
        //thumb clusters
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                        KC_NO,      KC_TRNS,   
        KC_TRNS,KC_TRNS,                                                                                KC_NO,         KC_NO
        ),
	[5] = LAYOUT_ergodox_pretty(
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    //,------------------------------------------------------------------------------.                         ,-------------------------------------------------------------------------------.
         KC_ESC,         KC_Z,         KC_Q,         KC_F,         KC_E,         KC_G,KC_TRNS,          KC_TRNS,         KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,   KC_NO,
    //|--------+-------------+-------------+-------------+-------------+-------------|                         |--------------+-------------+-------------+-------------+-------------+--------|
           KC_1,      KC_LSFT,         KC_A,         KC_W,         KC_D,         KC_T,                                   KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,   KC_NO,
    //|--------+-------------+-------------+-------------+-------------+-------------|                         |--------------+-------------+-------------+-------------+-------------+--------|
           KC_2,      KC_LCTL,         KC_X,         KC_S,         KC_C,         KC_B,KC_TRNS,          KC_TRNS,         KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,   TO(0),
    //|--------+-------------+-------------+-------------+-------------+-------------+-------------|  |--------+--------------+-------------+-------------+-------------+-------------+--------|
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                           KC_3,                                                              KC_TAB,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                 //`---------------------------------------'  `-------------------------------------'
        //thumb clusters
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                    KC_SPC,         KC_R,   
        KC_TRNS,KC_TRNS,                                                                                KC_ESC,      KC_LALT
        )
};

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
