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

#define CTL_ESC MT(MOD_LCTL, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE_LAYER] = LAYOUT(
      //           ╭────────────────────────────────────────────╮                    ╭────────────────────────────────────────────╮
                       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
      // ╭──────────────────────────────────────────────────────┤                    ├─────────────────────────────────────────────────────╮
            KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      // ├──────────────────────────────────────────────────────╭────────╮ ╭─────────╮─────────────────────────────────────────────────────┤
           KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    KC_MPLY,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
      // ╰───────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────╯
                                      TL_LOWR, KC_LSFT, CTL_ESC, KC_LGUI,    KC_BSPC, TL_UPPR,  KC_SPC,  KC_ENT
      //                             ╰───────────────────────────────────╯ ╰────────────────────────────────────╯
    ),

    [UPPER_LAYER] = LAYOUT(
      //           ╭────────────────────────────────────────────╮                    ╭────────────────────────────────────────────╮
                    KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_UNDS,  KC_EQL, KC_PLUS,
      // ╭──────────────────────────────────────────────────────┤                    ├─────────────────────────────────────────────────────╮
           _______, _______,  KC_GRV, KC_LCBR, KC_RCBR, _______,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_MINS, _______,
      // ├──────────────────────────────────────────────────────╭────────╮ ╭─────────╮─────────────────────────────────────────────────────┤
           _______, _______, KC_TILD, KC_LBRC, KC_RBRC, KC_ASTR, _______,    _______, KC_HOME, KC_LPRN, KC_RPRN,  KC_END, _______, _______,
      // ╰───────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────╯
                                      _______, _______, _______, _______,    _______, _______, _______, _______
      //                             ╰───────────────────────────────────╯ ╰────────────────────────────────────╯
    ),

    [LOWER_LAYER] = LAYOUT(
      //           ╭────────────────────────────────────────────╮                    ╭────────────────────────────────────────────╮
                       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
      // ╭──────────────────────────────────────────────────────┤                    ├─────────────────────────────────────────────────────╮
           _______, _______, _______,   LENNY,   SHRUG, GLASSES,                      KC_MPRV, KC_MNXT, DM_PLY1, _______, DM_RSTP, DM_REC1,
      // ├──────────────────────────────────────────────────────╭────────╮ ╭─────────╮─────────────────────────────────────────────────────┤
           _______, _______, CUTEFCE, FIGHTME, TBLFLIP, TBLDOWN, _______,    _______, KC_WBAK, KC_WFWD, DM_PLY2, _______, DM_RSTP, DM_REC2,
      // ╰───────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────╯
                                      _______, _______, _______, _______,     KC_DEL, _______, KC_PSCR, _______
      //                             ╰───────────────────────────────────╯ ╰────────────────────────────────────╯
    ),

    [CONTROL_LAYER] = LAYOUT(
      //           ╭────────────────────────────────────────────╮                    ╭────────────────────────────────────────────╮
                      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
      // ╭──────────────────────────────────────────────────────┤                    ├─────────────────────────────────────────────────────╮
           _______,  KC_F11,  KC_F12, _______,  AC_OFF,   AC_ON,                      DB_TOGG, _______, _______, _______, _______, QK_BOOT,
      // ├──────────────────────────────────────────────────────╭────────╮ ╭─────────╮─────────────────────────────────────────────────────┤
           _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,  QK_RBT,
      // ╰───────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────╯
                                      _______, _______, _______, _______,    _______, _______, _______, _______
      //                             ╰───────────────────────────────────╯ ╰────────────────────────────────────╯
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
    bongo_hook(keycode, record);

    if (!handle_macros(keycode, record)) return false;

    return true;
};

// bool dynamic_macro_record_start_user(int8_t direction) {
//     dprint("dynamic_macro_record_start_user");

//     switch (direction) {
//     case 1:
//         oled_write_P(PSTR("Recording Macro 1...\n"), false);
//     case -1:
//         oled_write_P(PSTR("Recording Macro 2...\n"), false);
//     }
//     return true;
// }

// bool dynamic_macro_play_user(int8_t direction) {
//     dprint("dynamic_macro_play_user");

//     switch (direction) {
//     case 1:
//         oled_write_P(PSTR("Playing Macro 1\n"), false);
//     case -1:
//         oled_write_P(PSTR("Playing Macro 2\n"), false);
//     }
//     return true;
// }

// bool dynamic_macro_record_end_user(int8_t direction) {
//     dprint("dynamic_macro_record_end_user");

//     switch (direction) {
//     case 1:
//         oled_write_P(PSTR("Stopped Recording Macro 1\n"), false);
//     case -1:
//         oled_write_P(PSTR("Stopped Recording Macro 2\n"), false);
//     }
//     return true;
// }


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE_LAYER] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [UPPER_LAYER] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),  ENCODER_CCW_CW(KC_BRIU, KC_BRID)  },
    [LOWER_LAYER] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),  ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [CONTROL_LAYER] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),  ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
};
#endif


#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C


