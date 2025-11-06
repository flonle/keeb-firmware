#pragma once

bool oled_task_user(void);
oled_rotation_t oled_init_user(oled_rotation_t);
void bongo_hook(uint16_t keycode, keyrecord_t *record);
bool apply_autocorrect(uint8_t backspaces, const char *str, char *typo, char *correct);

enum keymap_layers {
    BASE_LAYER = 0,
    LOWER_LAYER,
    UPPER_LAYER,
    CONTROL_LAYER,
};
