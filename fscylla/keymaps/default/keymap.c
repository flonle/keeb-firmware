#include QMK_KEYBOARD_H
#include <stdint.h>
#include "keymap.h"
#include "action.h"
#include "keycodes.h"
#include "print.h"


enum custom_keycodes {
    TBLFLIP = SAFE_RANGE,
    TBLDOWN,
    LENNY,
    SHRUG,
    GLASSES,
    FIGHTME,
    CUTEFCE,
};

enum keymap_layers {
    BASE_LAYER = 0,
    SECOND_LAYER,
    THIRD_LAYER,
};

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define MO_SCND MO(SECOND_LAYER)
#define MO_THRD MO(THIRD_LAYER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE_LAYER] = LAYOUT(
      // ╭──────────────────────────────────────────────────────╮       ╭─────────────────────────────────────────────────────╮
            KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PSCR,
      // ├──────────────────────────────────────────────────────┤       ├─────────────────────────────────────────────────────┤
            KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_EQL,
      // ├──────────────────────────────────────────────────────┤       ├─────────────────────────────────────────────────────┤
           KC_VOLU,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      // ├──────────────────────────────────────────────────────┤       ├─────────────────────────────────────────────────────┤
           KC_VOLD,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
      // ╰──────────────────────────────────────────────────────┤       ├─────────────────────────────────────────────────────╯
                                      KC_LSFT, CTL_ESC, KC_LGUI,         MO_SCND,  KC_SPC,  KC_ENT,
      //                             ╰──────────────────────────┤       ├──────────────────────────╯
                                               KC_LALT,  KC_TAB,         KC_BSPC,  KC_DEL
      //                                      ╰─────────────────╯       ╰─────────────────╯
    ),

    [SECOND_LAYER] = LAYOUT(
      // ╭──────────────────────────────────────────────────────╮       ╭─────────────────────────────────────────────────────╮
           _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
      // ├──────────────────────────────────────────────────────┤       ├─────────────────────────────────────────────────────┤
           KC_MUTE, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,         KC_CIRC, KC_AMPR, KC_UNDS, KC_HOME,  KC_END,  KC_F12,
      // ├──────────────────────────────────────────────────────┤       ├─────────────────────────────────────────────────────┤
           KC_MNXT, _______,  KC_GRV, KC_LCBR, KC_RCBR, _______,         KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT, KC_MINS,  KC_F13,
      // ├──────────────────────────────────────────────────────┤       ├─────────────────────────────────────────────────────┤
           KC_MPRV, KC_WBAK, KC_TILD, KC_LBRC, KC_RBRC, KC_ASTR,         KC_HOME, KC_LPRN, KC_RPRN,  KC_END, KC_WFWD,  KC_F14,
      // ╰──────────────────────────────────────────────────────┤       ├─────────────────────────────────────────────────────╯
                                      _______, _______, _______,         _______, _______, _______,
      //                             ╰──────────────────────────┤       ├──────────────────────────╯
                                               _______, MO_THRD,         _______, _______
      //                                      ╰─────────────────╯       ╰─────────────────╯
    ),

    [THIRD_LAYER] = LAYOUT(
      // ╭──────────────────────────────────────────────────────╮       ╭─────────────────────────────────────────────────────╮
           _______, _______, _______, _______,  AC_OFF,   AC_ON,         UC_NEXT, _______, _______, _______, _______, _______,
      // ├──────────────────────────────────────────────────────┤       ├─────────────────────────────────────────────────────┤
           _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
      // ├──────────────────────────────────────────────────────┤       ├─────────────────────────────────────────────────────┤
           _______, _______, _______,   LENNY,   SHRUG, GLASSES,         DM_PLY1, DM_REC1, DM_RSTP, _______, _______, _______,
      // ├──────────────────────────────────────────────────────┤       ├─────────────────────────────────────────────────────┤
           _______, _______, CUTEFCE, FIGHTME, TBLFLIP, TBLDOWN,         DM_PLY2, DM_REC2, DM_RSTP, _______, _______, _______,
      // ╰──────────────────────────────────────────────────────┤       ├─────────────────────────────────────────────────────╯
                                      _______, _______, _______,         _______, _______, _______,
      //                             ╰──────────────────────────┤       ├──────────────────────────╯
                                               _______, _______,         _______, _______
      //                                      ╰─────────────────╯       ╰─────────────────╯
    ),

};


// Handle all macros defined in this keymap.
static bool handle_macros(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TBLFLIP:
        if (record->event.pressed) {
            send_unicode_string("(╯°□°)╯︵ ┻━┻");
        }
        return false;
    case TBLDOWN:
        if (record->event.pressed) {
            send_unicode_string("┬─┬ノ( º _ ºノ)");
        }
        return false;
    case LENNY:
        if (record->event.pressed) {
            send_unicode_string("( ͡° ͜ʖ ͡°)");
        }
        return false;
    case SHRUG:
        if (record->event.pressed) {
            send_unicode_string("¯\\_(ツ)_/¯");
        }
        return false;
    case GLASSES:
        if (record->event.pressed) {
            send_unicode_string("( •_•)>⌐■-■  (⌐■_■)");
        }
        return false;
    case FIGHTME:
        if (record->event.pressed) {
            send_unicode_string("(ง •̀_•́)ง");
        }
        return false;
    case CUTEFCE:
        if (record->event.pressed) {
            send_unicode_string("(｡◕‿◕｡)");
        }
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!handle_macros(keycode, record)) return false;

    return true;
};
