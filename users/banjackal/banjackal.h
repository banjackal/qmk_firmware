#pragma once

#include QMK_KEYBOARD_H

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

enum layers { BASE, NUM, SYM, FN, GAME };

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

enum combos {
    TAB,
    ESC,
    INS,
    DEL,
    CAPS,
    ENTER,
    R_ALT,
    R_CTL,
    GAME_LR
};

const uint16_t PROGMEM tab_combo[] = {KC_QUOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_A, KC_O, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_R, KC_L, COMBO_END};
const uint16_t PROGMEM ins_combo[] = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_N, KC_S, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {LSFT_T(KC_SCLN), LSFT_T(KC_Z), COMBO_END};
const uint16_t PROGMEM r_alt_combo[] = {LALT_T(KC_J), LALT_T(KC_W), COMBO_END};
const uint16_t PROGMEM g_lr_combo[] = {LT(NUM,KC_BSPC),  LT(SYM,KC_SPC),  MO(FN), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [TAB] = COMBO (tab_combo, KC_TAB),
    [ESC] = COMBO(esc_combo, KC_ESC),
    [DEL] = COMBO(del_combo, KC_DEL),
    [INS] = COMBO(ins_combo, KC_INS),
    [CAPS] = COMBO(caps_combo, KC_CAPS),
    [ENTER] = COMBO(enter_combo, KC_ENT),
    [R_ALT] = COMBO(r_alt_combo, KC_RALT),
    [GAME_LR] = COMBO(g_lr_combo, TG(GAME))
};
