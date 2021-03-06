#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,  // can always be here
  EPRM,
  RGB_SLD,
  HSV_240_255_255,
  HSV_120_255_128,
  HSV_38_255_255,
  HSV_300_255_128,
  HSV_0_255_255,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox(
      KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_PGDOWN, //7 (top left row)
      LCTL_T(KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, G(KC_C), //7 (second left row and big button)
      LCTL_T(KC_ESCAPE), KC_A, KC_S, KC_D, KC_F, KC_G, //6 (third left row)
      LSFT_T(KC_LPRN), KC_Z, KC_X, KC_C, KC_V, KC_B, G(KC_V), //7 (fourth left row and big button)
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(3), MO(2), //5 (bottom left row)
      KC_LSHIFT, KC_LCTRL, KC_LALT, KC_LGUI, KC_BSPACE, KC_ESCAPE, //6 (left cluster)

      KC_PGUP, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, //7 (top right row)
      KC_RBRACKET, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLASH, //7 (second right row and big button)
      KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, //6 (third right row)
      KC_RCBR, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, RSFT_T(KC_RPRN), //7 (fourth right row with big button)
      MO(1), MO(2), KC_TRANSPARENT, KC_TRANSPARENT, KC_HYPR, //5 (bottom right row)
      KC_KP_MINUS, KC_KP_ASTERISK, KC_KP_PLUS, KC_EQUAL, KC_ENTER, KC_SPACE //6 (right cluster)
    ),

    [1] = LAYOUT_ergodox(
      KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRANSPARENT,  //7 (top left row)
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, //7 (second left row and big button)
      KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRANSPARENT, //6 (third left row)
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, //7 (fourth left row and big button)
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, //5 (bottom left row)
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1, KC_MS_BTN2, KC_TRANSPARENT, //6 (left cluster)

      KC_TRANSPARENT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_MEDIA_PLAY_PAUSE, //7 (top right row)
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_AUDIO_VOL_UP, //7 (second right row and big button)
      KC_TRANSPARENT, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN, //6 (third right row)
      KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_TRANSPARENT, KC_AUDIO_MUTE, //7 (fourth right row with big button)
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, //5 (bottom right row)
      KC_TRANSPARENT, LCAG(KC_M), LCAG(KC_UP), LCAG(KC_DOWN), LCAG(KC_LEFT), LCAG(KC_RIGHT) //6 (right cluster)
    ),

    [2] = LAYOUT_ergodox(
      KC_TRANSPARENT, KC_TRANSPARENT, HSV_240_255_255, HSV_120_255_128, HSV_38_255_255, HSV_300_255_128, HSV_0_255_255,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      RGB_MOD, RGB_SLD, KC_TRANSPARENT, RGB_VAD, RGB_VAI, KC_TRANSPARENT,

      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME, KC_UP, KC_END, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP, KC_TRANSPARENT, KC_PGDOWN, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
      RGB_TOG, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_HUD, RGB_HUI
    ),

    [3] = LAYOUT_ergodox(
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, //7
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_HYPR, KC_KP_PLUS), KC_TRANSPARENT, //7
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_HYPR, KC_KP_MINUS), //6
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, //7
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, //5
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, //6

      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, //7
      KC_TRANSPARENT, KC_LABK, KC_AT, KC_LPRN, KC_RPRN, KC_HASH, KC_TRANSPARENT, //7
      KC_RABK, KC_EQUAL, KC_LCBR, KC_RCBR, KC_DLR, KC_TRANSPARENT, //6
      KC_TRANSPARENT, KC_TILD, KC_GRAVE, KC_LBRACKET, KC_RBRACKET, KC_PIPE, KC_TRANSPARENT, //7
      KC_KP_PLUS, KC_KP_MINUS, KC_KP_ASTERISK, KC_KP_SLASH, KC_TRANSPARENT, //5
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT //6
    ),
};

bool           suspended            = false;
const uint16_t PROGMEM fn_actions[] = {[1] = ACTION_LAYER_TAP_TOGGLE(1)};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    case HSV_240_255_255:
      if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
        rgblight_enable();
        rgblight_mode(1);
        rgblight_sethsv(240, 255, 255);
#endif
      }
      return false;
      break;
    case HSV_120_255_128:
      if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
        rgblight_enable();
        rgblight_mode(1);
        rgblight_sethsv(120, 255, 128);
#endif
      }
      return false;
      break;
    case HSV_38_255_255:
      if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
        rgblight_enable();
        rgblight_mode(1);
        rgblight_sethsv(38, 255, 255);
#endif
      }
      return false;
      break;
    case HSV_300_255_128:
      if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
        rgblight_enable();
        rgblight_mode(1);
        rgblight_sethsv(300, 255, 128);
#endif
      }
      return false;
      break;
    case HSV_0_255_255:
      if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
        rgblight_enable();
        rgblight_mode(1);
        rgblight_sethsv(0, 255, 255);
#endif
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
