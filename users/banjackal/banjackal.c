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
    LAMBDA
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

        case LAMBDA:
        if (record->event.pressed) {
            SEND_STRING("=>");
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
    U_NA, U_NA,     KC_EXLM,  KC_LT,    KC_GT,          LAMBDA,     U_NA,     KC_LBRC,  KC_RBRC,      KC_UNDS,  U_NA,     U_NA,
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



#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_ln_P(PSTR("Dvorak"), false);
            break;
        case NUM:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case SYM:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case FN:
            oled_write_ln_P(PSTR("Function"), false);
            break;
        case MCRO:
            oled_write_ln_P(PSTR("Macro"), false);
            break;
        case GAME:
            oled_write_ln_P(PSTR("Gamepad"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
            break;
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("    "), false);
}



const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};


void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
}

#endif // OLED_DRIVER_ENABLE
