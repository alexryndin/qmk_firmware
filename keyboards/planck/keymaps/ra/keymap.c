/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.    If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _LAYER4,
};

enum planck_keycodes {
    RGB_SLD = SAFE_RANGE,
    ST_MACRO_0,
    ST_MACRO_1,
    PLAY_A4,
    PLAY_NOCTURNE,
    MT_1,
    MT_2,
    MT_3,
    MT_4,
};

float basic_a[][2] = SONG(BASIC_A);
float nocturne[][2] = SONG(NOCTURNE_OP_9_NO_1);

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_planck_grid(
                    KC_ESCAPE,                KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE,
                    KC_LCTRL,                 KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(4, KC_SCOLON),
                    LALT_T(KC_QUOTE), KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH,
                    KC_RSHIFT,                KC_CAPSLOCK, KC_TAB, KC_LALT, KC_LGUI, LOWER, KC_SPACE, KC_SPACE, RAISE, KC_ENTER, KC_RALT, KC_TAB, KC_TAB
),

[_LOWER] = LAYOUT_planck_grid(
                    KC_TILD, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_PLUS, KC_LABK, KC_RABK, KC_MINUS, KC_ASTR, KC_DELETE,
                    KC_LCTRL, KC_HASH, KC_DLR, KC_LBRACKET, KC_RBRACKET, KC_GRAVE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_ASTR, KC_ASTR,
                    KC_RSHIFT, KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, KC_TILD, KC_AMPR, KC_PLUS, KC_EQUAL, KC_MINUS, KC_BSLASH, KC_RSHIFT,
                    KC_CAPSLOCK, KC_TRANSPARENT, KC_LALT, KC_LGUI, KC_TRANSPARENT, KC_ENTER, KC_ENTER, KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE
),

[_RAISE] = LAYOUT_planck_grid(
                    KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DELETE,
                    KC_LCTRL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINUS, KC_EQUAL, KC_PGUP, KC_PGDOWN, KC_BSLASH,
                    KC_LSHIFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCREEN, KC_NONUS_BSLASH, KC_PGUP, KC_PGDOWN, KC_RSHIFT,
                    KC_CAPSLOCK, KC_TRANSPARENT, KC_LALT, KC_LGUI, KC_TRANSPARENT, KC_SPACE, KC_SPACE, KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE
),

[_ADJUST] = LAYOUT_planck_grid(
                CK_UP, CK_DOWN, CK_TOGG, KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                KC_DELETE, KC_TRANSPARENT, AU_ON, AU_OFF, AU_TOG, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                PLAY_NOCTURNE, KC_TRANSPARENT, MU_ON, MU_OFF, MU_TOG, MU_MOD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                PLAY_A4, MT_1, MT_2, MT_3, MT_4, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

[_LAYER4] = LAYOUT_planck_grid(
                KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP, KC_MS_UP, KC_MS_WH_DOWN, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_0, ST_MACRO_1, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1, KC_MS_BTN2, KC_TRANSPARENT, KC_NO, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

};

#ifdef AUDIO_ENABLE
    float plover_song[][2]         = SONG(PLOVER_SOUND);
    float plover_gb_song[][2]    = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ST_MACRO_0:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_TAB)));
            }
            break;
        case ST_MACRO_1:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_RSFT(SS_TAP(X_TAB))));
            }
            break;
#ifdef AUDIO_ENABLE
        case PLAY_A4:
            if (record->event.pressed) {
                PLAY_SONG(basic_a);
            }
            break;
        case PLAY_NOCTURNE:
            if (record->event.pressed) {
                PLAY_SONG(nocturne);
            }
            break;
        case MT_1:
            if (record->event.pressed) set_timbre(TIMBRE_12);
            break;

        case MT_2:
            if (record->event.pressed) set_timbre(TIMBRE_25);
            break;

        case MT_3:
            if (record->event.pressed) set_timbre(TIMBRE_50);
            break;

        case MT_4:
            if (record->event.pressed) set_timbre(TIMBRE_75);
            break;
#endif /* AUDIO_ENABLE */
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}
// PLAY_SONG(SONG(BASIC_A))

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
            #ifdef MOUSEKEY_ENABLE
                tap_code(KC_MS_WH_DOWN);
            #else
                tap_code(KC_PGDN);
            #endif
        } else {
            #ifdef MOUSEKEY_ENABLE
                tap_code(KC_MS_WH_UP);
            #else
                tap_code(KC_PGUP);
            #endif
        }
    }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
    if (muse_counter) {
        stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
