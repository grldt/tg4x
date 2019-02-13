/* Copyright 2018 u/mythosmann
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
#include QMK_KEYBOARD_H
#define _BL 0
#define _FL 1
#define _ADJUST 2
#define KC_X0 RGB_TOG
#define KC_X1 RGB_MOD
// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};
//Tap Dance Declarations
enum {
  TD_1 = 9,
  TD_2
};
/*
The code for using the rgb lights to indicate caps lock and function layer.
*/
uint8_t prev = _QWERTY;
uint32_t desired = 1;
uint16_t hue = 120;
uint16_t sat = 255;
uint16_t val = 255;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
,-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.
|  Tab  |   q   |   w   |   e   |   r   |   t   |   y   |   u   |   i   |   o   |   p   |   '   | Bspc  |
|-------'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-------|
|  Caps   |   a   |   s   |   d   |   f   |   g   |   h   |   j   |   k   |   l   |   ;   |    Enter    |
|---------'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----------|
|  Shift     |   z   |   x   |   c   |   v   |   b   |   n   |   m   |   ,   |   .   |   /   |   Shift  |
|-------,----'--,----'--,----'-------'-------'-------'-------'-------'--,----'--,----'--,----'--,-------|
|  Ctl  |  Alt  |  Win  |                                               |  Fn   | Left  |  Up   | Right |
`-------'-------'-------'-----------------------------------------------'-------'-------'-------'-------'
*/
  [_BL] = LAYOUT( /* Base */
//,-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.
   KC_ESC , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  , KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_CAPS,KC_X0   , \
//|-------'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-------------|
   TD(TD_1)  , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  , KC_H  , KC_J  , KC_K  , KC_L  ,KC_QUOT,    KC_ENT   , \
//|---------'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'-----,-'-------------|
    KC_LSFT    , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  , KC_N  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH, KC_RSFT  , \
//|-------,----'--,----'--,----'-------'-------'-------'-------'-------'--,----'--,----'--,----'--,-------|
   KC_LCTL,TD(TD_2),MO(_FL),        KC_SPC                                ,TG(_FL),KC_LEFT, KC_UP ,KC_RGHT   \
//`-------'-------'-------'-----------------------------------------------'-------'-------'-------'-------'
),

/*
,-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.
|   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |  Del  |
|-------'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-------|
|  Caps   | Home  | PgUp  |       |       | MsUp  |       |   [   |   ]   |   =   |   \   |    Enter    |
|---------'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----------|
|  Shift     |  End  | PgDn  |  MsL  | MsDn  |  MsR  |       |       |       |       |       |   Shift  |
|-------,----'--,----'--,----'-------'-------'-------'-------'-------'--,----'--,----'--,----'--,-------|
|  Ctl  |  Alt  |  Win  |                                               |  Fn   | Left  | Down  | Right |
`-------'-------'-------'-----------------------------------------------'-------'-------'-------'-------'
*/
  [_FL] = LAYOUT( /* Function */
//,-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.
   KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,KC_DEL , \
//|-------'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-------------|
   KC_TRNS  ,KC_HOME,KC_PGUP,KC_TRNS,KC_BTN1,KC_MS_U,KC_BTN2,KC_LBRC,KC_RBRC,KC_EQL ,KC_BSLS,    KC_ENT   , \
//|---------'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----------|
    KC_LSFT    ,KC_END ,KC_PGDN,KC_MS_L,KC_MS_D,KC_MS_R,KC_ACL0,KC_ACL1,KC_TRNS,KC_TRNS,KC_TRNS, KC_RSFT  , \
//|-------,----'--,----'--,----'-------'-------'-------'-------'-------'--,----'--,----'--,----'--,-------|
   KC_TRNS,KC_TRNS,KC_TRNS,         KC_SPC                                ,KC_TRNS,KC_LEFT,KC_DOWN,KC_RGHT  \
//`-------'-------'-------'-----------------------------------------------'-------'-------'-------'-------'
),
/*
,-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.
|   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |  Del  |
|-------'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-------|
|  Caps   | Home  | PgUp  |       |       | MsUp  |       |   [   |   ]   |   =   |   \   |    Enter    |
|---------'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----------|
|  Shift     |  End  | PgDn  |  MsL  | MsDn  |  MsR  |       |       |       |       |       |   Shift  |
|-------,----'--,----'--,----'-------'-------'-------'-------'-------'--,----'--,----'--,----'--,-------|
|  Ctl  |  Alt  |  Win  |                                               |  Fn   | Left  | Down  | Right |
`-------'-------'-------'-----------------------------------------------'-------'-------'-------'-------'
*/
  [_ADJUST] = LAYOUT( /* Function */
//,-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.-------.
   KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,KC_DEL , \
//|-------'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-----'-,-------------|
   KC_TRNS  ,KC_HOME,KC_PGUP,KC_TRNS,KC_BTN1,KC_MS_U,KC_BTN2,KC_LBRC,KC_RBRC,KC_EQL ,KC_BSLS,    KC_ENT   , \
//|---------'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----'--,----------|
    KC_LSFT    ,KC_END ,KC_PGDN,KC_MS_L,KC_MS_D,KC_MS_R,KC_ACL0,KC_ACL1,KC_TRNS,KC_TRNS,KC_TRNS, KC_RSFT  , \
//|-------,----'--,----'--,----'-------'-------'-------'-------'-------'--,----'--,----'--,----'--,-------|
   KC_TRNS,KC_TRNS,KC_TRNS,         KC_SPC                                ,KC_TRNS,KC_LEFT,KC_DOWN,KC_RGHT  \
//`-------'-------'-------'-----------------------------------------------'-------'-------'-------'-------'
),
};

/*
Tap dance stuff.
td_1 is tab when hit, but caps lock when double tapped.
td_2 is alt when hit, but windows key when double tapped
*/
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_1]  = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_CAPS),
  [TD_2]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LGUI)
// Other declarations would go here, separated by commas, if you have them
};

/*
Custom Macro stuff
These are just the example macros used by qmk.
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {
  /*
  The code for using the rgb lights to indicate caps lock and function layer.
  */
void get_hsv(void) {
  	hue = rgblight_get_hue();
  	sat = rgblight_get_sat();
  	val = rgblight_get_val();
  }

  void reset_hsv(void) {
  	rgblight_sethsv(hue, sat, val);
  }

  void matrix_init_user() {
  	rgblight_mode(desired);
  	rgblight_enable();
  	reset_hsv();
  }

  uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    if (prev!=_ADJUST) {
  	  switch (layer) {
  		case _BL:
  		  rgblight_mode(desired);
  		  if(desired < 6 || (desired > 14 && desired < 25)) { // Skip in rainbow modes.
  			reset_hsv();
  		  }
  		  break;

  		case _FL:
  		  rgblight_mode(5);
  		  rgblight_sethsv(0, 255, 255);
  		  break;

  	  }
    } else {
  	  desired = rgblight_get_mode();
  	  get_hsv();
    }
    prev = layer;
    return state;
  }
