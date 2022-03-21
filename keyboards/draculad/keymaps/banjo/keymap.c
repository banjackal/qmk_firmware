#include QMK_KEYBOARD_H

    enum custom_keycodes {
        LAMBDA = SAFE_RANGE,
    };

    bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            case LAMBDA:
            if (record->event.pressed) {
                SEND_STRING("=>");
            } else {
            }
            break;
        }
        return true;
    };

    enum layer_number {
        _BASE,
        _COLEMAK,
        _NUM,
        _SYM,
        _FN,
        _GAME
    };

    enum combos {
        TAB,
        ESC,
        INS,
        DEL,
        CAPS,
        ENTER,
        R_ALT,
        R_CTL,
        GAME_LR,
        C_TAB,
        C_ESC,
        C_INS,
        C_DEL,
        C_CAPS,
        C_ENTER
    };

    const uint16_t PROGMEM tab_combo[] = {KC_QUOT, KC_COMM, COMBO_END};
    const uint16_t PROGMEM esc_combo[] = {KC_A, KC_O, COMBO_END};
    const uint16_t PROGMEM del_combo[] = {KC_R, KC_L, COMBO_END};
    const uint16_t PROGMEM ins_combo[] = {KC_G, KC_C, COMBO_END};
    const uint16_t PROGMEM enter_combo[] = {KC_N, KC_S, COMBO_END};
    const uint16_t PROGMEM caps_combo[] = {LSFT_T(KC_SCLN), LSFT_T(KC_Z), COMBO_END};
    const uint16_t PROGMEM r_alt_combo[] = {LALT_T(KC_J), LALT_T(KC_W), COMBO_END};
    const uint16_t PROGMEM r_ctl_combo[] = {LCTL_T(KC_Q), LCTL_T(KC_V), COMBO_END};
    const uint16_t PROGMEM g_lr_combo[] = {LT(_NUM,KC_BSPC),  LT(_SYM,KC_SPC),  MO(_FN), COMBO_END};
    const uint16_t PROGMEM c_tab_combo[] = {KC_Q, KC_W, COMBO_END};
    const uint16_t PROGMEM c_esc_combo[] = {KC_A, KC_R, COMBO_END};
    const uint16_t PROGMEM c_del_combo[] = {KC_Y, KC_SCLN, COMBO_END};
    const uint16_t PROGMEM c_ins_combo[] = {KC_L, KC_U, COMBO_END};
    const uint16_t PROGMEM c_enter_combo[] = {KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM c_caps_combo[] = {LSFT_T(KC_Z), LSFT_T(KC_QUOT), COMBO_END};

    combo_t key_combos[COMBO_COUNT] = {
        [TAB] = COMBO(tab_combo, KC_TAB),
        [ESC] = COMBO(esc_combo, KC_ESC),
        [DEL] = COMBO(del_combo, KC_DEL),
        [INS] = COMBO(ins_combo, KC_INS),
        [CAPS] = COMBO(caps_combo, KC_CAPS),
        [ENTER] = COMBO(enter_combo, KC_ENT),
        [R_ALT] = COMBO(r_alt_combo, KC_RALT),
        [R_CTL] = COMBO(r_ctl_combo, KC_RCTL),
        [GAME_LR] = COMBO(g_lr_combo, TG(_GAME)),
        [C_TAB] = COMBO(c_tab_combo, KC_TAB),
        [C_ESC] = COMBO(c_esc_combo, KC_ESC),
        [C_DEL] = COMBO(c_del_combo, KC_DEL),
        [C_INS] = COMBO(c_ins_combo, KC_INS),
        [C_CAPS] = COMBO(c_caps_combo, KC_CAPS),
        [C_ENTER] = COMBO(c_enter_combo, KC_ENT)
    };

    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_draculad(
        KC_QUOT,         KC_COMM,      KC_DOT,       KC_P,           KC_Y,                   KC_F,    KC_G,          KC_C,         KC_R,         KC_L,
        KC_A,            KC_O,         KC_E,         KC_U,           KC_I,                   KC_D,    KC_H,          KC_T,         KC_N,         KC_S,
        LSFT_T(KC_SCLN), LCTL_T(KC_Q), LALT_T(KC_J), LGUI_T(KC_K),   KC_X,                   KC_B,    LGUI_T(KC_M),  LALT_T(KC_W), LCTL_T(KC_V), LSFT_T(KC_Z),
                                                      TG(_COLEMAK),                                              KC_MUTE,
                                            XXXXXXX,     XXXXXXX,         XXXXXXX,                      LT(_NUM,KC_BSPC),  LT(_SYM,KC_SPC),  MO(_FN)
            ),
    [_COLEMAK] = LAYOUT_draculad(
        KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                   KC_J,    KC_L,          KC_U,            KC_Y,           KC_SCLN,
        KC_A,         KC_R,         KC_S,         KC_T,         KC_G,                   KC_M,    KC_N,          KC_E,            KC_I,           KC_O,
        LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C), LGUI_T(KC_D), KC_V,                   KC_K,    LGUI_T(KC_H),  LALT_T(KC_COMM), LCTL_T(KC_DOT), LSFT_T(KC_QUOT),
        KC_TRNS,                                              KC_MUTE,
                                            XXXXXXX,     XXXXXXX,         XXXXXXX,                      LT(_NUM,KC_BSPC),  LT(_SYM,KC_SPC),  MO(_FN)
            ),
    [_NUM] = LAYOUT_draculad(
          KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,     KC_7,           KC_8,     KC_9,     KC_0,
                    XXXXXXX,     XXXXXXX,XXXXXXX,     XXXXXXX,XXXXXXX,       KC_LEFT,  KC_DOWN,        KC_UP,    KC_RGHT,  XXXXXXX,
          KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXXXXXX,       KC_HOME,  KC_PGDN,        KC_PGUP,  KC_END,   XXXXXXX,
                  XXXXXXX,                                              XXXXXXX,
                    XXXXXXX,     XXXXXXX,     XXXXXXX,       KC_TRNS,  XXXXXXX, XXXXXXX
            ),
    [_SYM] = LAYOUT_draculad(
         KC_EXLM,  KC_AT,    KC_LT,    KC_GT,    LAMBDA,       XXXXXXX,     KC_LBRC,  KC_RBRC,      KC_UNDS,  KC_SLSH,
         KC_BSLS,  KC_HASH,  KC_LPRN,  KC_RPRN,  KC_PIPE,      KC_PERC,  KC_LCBR,  KC_RCBR,      KC_EQL,   KC_MINS,
         KC_QUES,  KC_GRV,   KC_ASTR,  KC_PLUS,  XXXXXXX,         XXXXXXX,     KC_AMPR,  KC_CIRC,      KC_TILD,  KC_DLR,
                                     XXXXXXX,                                              XXXXXXX,
XXXXXXX,     XXXXXXX,     XXXXXXX,         KC_TRNS,    XXXXXXX,     XXXXXXX
            ),
    [_FN] = LAYOUT_draculad(
           KC_F1,    KC_F2,    KC_F3,       KC_F4,     KC_F5,    KC_F6,  KC_F7,    KC_F8,    KC_F9,   KC_F10,
           XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_F11,   KC_F12, XXXXXXX,     XXXXXXX,     XXXXXXX,    KC_PSCR,
           KC_LSFT,  KC_LCTL,  KC_LALT,     KC_LGUI,   XXXXXXX,     XXXXXXX,   KC_LGUI,  KC_LALT,  KC_LCTL, KC_LSFT,
                  XXXXXXX,                                              XXXXXXX,
                     XXXXXXX,        XXXXXXX,      XXXXXXX,       XXXXXXX,   XXXXXXX,  KC_TRNS
            ),
    [_GAME] = LAYOUT_draculad(
          KC_Z,    KC_Q,       KC_F,       KC_E,    KC_G,      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_1,
          KC_LSFT, KC_A,       KC_W,       KC_D,    KC_T,      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_2,
          KC_LCTL, KC_X,       KC_S,       KC_C,    KC_B,      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_3,
                  XXXXXXX,                                              XXXXXXX,
                     KC_ESC,     KC_SPC,    KC_R,      KC_TRNS, KC_TRNS, KC_TRNS
        ),
    };
#ifdef OLED_ENABLE


oled_rotation_t oled_init_user(oled_rotation_t rotation) {

 if (is_keyboard_master()) {
    if(is_keyboard_left()){
      return OLED_ROTATION_270;
      }
      else {
        return OLED_ROTATION_90;
      }
    } else {
	    return OLED_ROTATION_0;
    }
}
static void render_logo(void) {
  static const char PROGMEM drac_logo[] = {
    // drac_logo, 128x64px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x0c, 0x18, 0x78, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x07, 0x3e, 0xfc, 0xf0, 0x00, 0x00, 0x00,
    0xf0, 0xf0, 0x60, 0x30, 0x30, 0x30, 0x00, 0x00, 0xe0, 0xe0, 0x30, 0x30, 0x30, 0x30, 0x30, 0xe0,
    0xe0, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x30, 0x30, 0x30, 0x70, 0xe0, 0xc0, 0x00, 0x00,
    0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0,
    0x80, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xf0, 0x80, 0xc0, 0xe0, 0xf0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0x7c, 0x3f, 0x0f, 0x00, 0x00, 0x00,
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xf8, 0xcc, 0x8c, 0x84, 0x86, 0x86, 0xc6, 0xff,
    0xff, 0x80, 0x80, 0x00, 0x3f, 0x7f, 0xe0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xf0, 0x71, 0x00, 0x00,
    0x1f, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xf8, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x1f,
    0x7f, 0x7f, 0x3e, 0x3e, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf8, 0xfc,
    0xfc, 0xfe, 0xfe, 0x7e, 0x7c, 0x78, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x60, 0x60,
    0x60, 0x60, 0x60, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xe0, 0x60, 0x60, 0x60, 0xc0,
    0xc0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07,
    0x0f, 0x3e, 0x7c, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf8,
    0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf1, 0x99, 0x18, 0x08,
    0x0c, 0x0c, 0x8c, 0xff, 0xff, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xc3, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x01, 0x01, 0x03, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01,
    0x01, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
  oled_write_raw_P(drac_logo, sizeof(drac_logo));
}

static void render_status(void) {
    oled_write_P(PSTR("This is\n~~~~~~~~~\nDracu\nLad\n~~~~~~~~~\nv1.0\n~~~~~~~~~\n"), false);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("lower"), false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("Layer:\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base    "), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("Colemak "), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Numbers "), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbols "), false);
            break;
        case _FN:
            oled_write_P(PSTR("Function"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game    "), false);
            break;
        default:
            oled_write_P(PSTR("        "), false);
            break;
    }
}

bool oled_task_user(void) {
      if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();
    }
    return false;
}

#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(C(KC_Y));
        } else {
            tap_code16(C(KC_Z));
        }
    }
    else if (index == 2) {
      if(clockwise) {
        tap_code(KC_VOLD);
      }
      else{
        tap_code(KC_VOLU);
      }
    }
    return true;
}
#endif
