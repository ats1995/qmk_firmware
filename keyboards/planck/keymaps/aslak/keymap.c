#include "planck.h" 
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define PREVENT_STUCK_MODIFIERS

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define _QW 0
#define _GAME 1
#define _RS 2
#define _US_QW 3
#define _US_RS 4
#define _LW 5
#define _FN 6
#define _RESET 7


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QW] = { /* Qwerty */
  {KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC},
  {KC_ESC,    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT},
  {KC_BSPC,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_ENT},
  {MO(_FN),   KC_RALT,   KC_LCTRL,  KC_LGUI,   KC_LSFT,   KC_SPC,    KC_SPC,    MO(_RS),   MO(_LW),   KC_LALT,   KC_RSFT,   DF(_GAME)}
},
[_GAME] = { // Game
  {KC_1,      KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P},
  {KC_2,      KC_ESC,    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN},
  {KC_3,      KC_6,      KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH},
  {KC_4,      KC_5,      KC_LCTL,   KC_LALT,   KC_LSFT,   KC_SPC,    KC_SPC,    KC_F5,     MO(_LW),   KC_ENT,    KC_F3,     DF(_QW)}
},
[_RS] = { /* RAISE, symbols */
  {S(KC_GRV), S(KC_1),   S(KC_2),   S(KC_3),   S(KC_4),   S(KC_5),   S(KC_6),   S(KC_7),   S(KC_8),   S(KC_9),   S(KC_0),   S(KC_MINUS)},
  {KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINUS},
  {KC_DEL,    KC_NUBS,   RALT(KC_2),RALT(KC_3),RALT(KC_4),KC_EQL, RALT(KC_RBRC),RALT(KC_7),RALT(KC_8),RALT(KC_9),RALT(KC_0),KC_BSLASH},
  {KC_TRNS,   S(KC_RBRC),KC_TRNS,   KC_TRNS,   KC_LSFT,   KC_SPC,    KC_SPC,    KC_TRNS,   KC_TRNS,   KC_LALT,   KC_TRNS,   KC_TRNS}
},
[_US_QW] = { /* US Qwerty */
  {KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLASH},
  {KC_ESC,    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT},
  {KC_BSPC,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_ENT},
  {MO(_FN),   KC_RALT,   KC_LCTRL,  KC_LGUI,   KC_LSFT,   KC_SPC,    KC_SPC,    MO(_US_RS),MO(_LW),   KC_LALT,   KC_RSFT,   DF(_GAME)}
},
[_US_RS] = { /* US RAISE, symbols */
  {S(KC_GRV), S(KC_1),   S(KC_2),   S(KC_3),    S(KC_4),  S(KC_5),   S(KC_6),   S(KC_7),  S(KC_8),    S(KC_9),   S(KC_0),   S(KC_MINUS)},
  {KC_GRV,    KC_1,      KC_2,      KC_3,       KC_4,     KC_5,      KC_6,      KC_7,     KC_8,       KC_9,      KC_0,      KC_MINUS},
  {KC_DEL,    KC_NO,     KC_NO,     KC_NO,      KC_NO,    KC_NO,     S(KC_EQL), S(KC_LBRC),S(KC_RBRC),KC_LBRC,   KC_RBRC,   KC_EQL},
  {KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_LSFT,  KC_SPC,    KC_SPC,    KC_TRNS,  KC_TRNS,    KC_LALT,   KC_TRNS,   KC_TRNS}
},
[_LW] = { /* LOWER, navigation */
  {KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,    KC_F9,      KC_F10,    KC_F11,    KC_F12},
  {KC_TRNS,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_LEFT,   KC_DOWN,  KC_UP,      KC_RGHT,   KC_APP,    KC_NO},
  {KC_INS,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_HOME,   KC_PGDN,  KC_PGUP,    KC_END,    KC_PSCR,   KC_SLCK},
  {KC_CAPS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_LSFT,   KC_SPC,    KC_SPC,    KC_TRNS,  KC_TRNS,    KC_LALT,   KC_NO,     KC_PAUS}
},
[_FN] = { /* FN */
  {KC_VOLU,   KC_TRNS,   KC_MS_U,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  DF(_US_QW), DF(_QW),   KC_TRNS,   DEBUG},
  {KC_MPLY,   KC_MS_L,   KC_MS_D,   KC_MS_R,   KC_TRNS,   KC_NO,     KC_WH_L,   KC_WH_D,  KC_WH_U,    KC_WH_R,   KC_TRNS,   KC_TRNS},
  {KC_VOLD,   KC_MPRV,   KC_MNXT,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS},
  {KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_MS_BTN2,KC_MS_BTN1,KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_TRNS,   MO(_RESET)}
},
[_RESET] = { /* RESET */
  {KC_NO,     KC_NO,     KC_NO,     KC_NO,      RESET,     KC_NO,    KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO},
  {KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,     KC_NO,    KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO},
  {KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,     KC_NO,    KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO},
  {KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,     KC_NO,    KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,     KC_NO}
}

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 1:
      if (record->event.pressed) {
        layer_on(1);
      } else {
        layer_off(1);
      }
      break;
    case 2:
      if (record->event.pressed) {
        layer_on(2);
      } else {
        layer_off(2);
      }
      break;
  }
  return MACRO_NONE;
};
