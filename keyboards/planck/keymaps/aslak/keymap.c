/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "keymap_norwegian.h"
#include QMK_KEYBOARD_H
//#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _GAME,
  _LOWER,
  _RAISE,
  _FN,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
  EXT_PLV,
  KVM1,
  KVM2,
  KVM3,
  KVM4
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    NO_AA,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NO_OSLH, NO_AE,
    KC_BSPC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  NO_MINS, KC_ENT,
    MO(_FN), KC_RALT, KC_LCTRL,KC_LGUI, KC_LSFT, KC_SPC,  KC_SPC,  RAISE,   LOWER,   KC_LALT, KC_RSFT, DF(_GAME)
),
[_LOWER] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_F9,    KC_F10,  KC_F11,  KC_F12,
    _______, KVM1,    KVM2,    KVM3,    KVM4,    XXXXXXX, KC_LEFT, KC_DOWN,KC_UP,    KC_RGHT, KC_APP,  KC_PAUS,
    KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN,KC_PGUP,  KC_END,  KC_PSCR, KC_SLCK,
    KC_CAPS, _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______,_______,  _______, _______, XXXXXXX
),
[_RAISE] = LAYOUT_planck_grid(
    NO_SECT, KC_EXLM, NO_QUO2, KC_HASH, NO_BULT, KC_PERC, NO_AMPR, NO_SLSH, NO_LPRN, NO_RPRN, NO_EQL,  NO_QUES,
    NO_PIPE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    NO_PLUS,
    KC_DEL,  NO_LESS, NO_AT,   NO_PND,  NO_DLR,  NO_BSLS, NO_TILD, NO_LCBR, NO_LBRC, NO_RBRC, NO_RCBR, KC_BSLASH,
    NO_ACUT, NO_CIRC, _______, _______, _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______, XXXXXXX
),
[_GAME] = LAYOUT_planck_grid(
    KC_1,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_2,    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_3,    KC_6,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_4,    KC_5,    KC_LCTL, KC_LALT, KC_LSFT, KC_SPC,  KC_SPC,  KC_F5,   KC_F9,   KC_ENT,  KC_F3,   DF(_QWERTY)
),
[_FN] = LAYOUT_planck_grid(
    KC_VOLU, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    KC_MPLY, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U,  KC_WH_R, XXXXXXX, XXXXXXX,
    KC_VOLD, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_LCTRL,KC_LSFT, KC_BTN2, KC_BTN1, _______, _______, _______, _______,  _______, _______, XXXXXXX
),
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, XXXXXXX
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case KVM1:
      if (record->event.pressed) {
        tap_code(KC_SLCK);
        tap_code(KC_SLCK);
        SEND_STRING(SS_TAP(X_1));
      }
      break;
    case KVM2:
      if (record->event.pressed) {
        tap_code(KC_SLCK);
        tap_code(KC_SLCK);
        SEND_STRING(SS_TAP(X_2));
      }
      break;
    case KVM3:
      if (record->event.pressed) {
        tap_code(KC_SLCK);
        tap_code(KC_SLCK);
        SEND_STRING(SS_TAP(X_3));
      }
      break;
    case KVM4:
      if (record->event.pressed) {
        tap_code(KC_SLCK);
        tap_code(KC_SLCK);
        SEND_STRING(SS_TAP(X_4));
      }
      break;
  }
  return true;
}

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

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
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
