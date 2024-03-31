/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018-2022  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built on " __DATE__ " at " __TIME__
#endif

#include "Kaleidoscope.h"
//#include "Kaleidoscope-EEPROM-Settings.h"
//#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-Escape-OneShot.h"
//#include "Kaleidoscope-FirmwareVersion.h"
//#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-TapDance.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
//#include "Kaleidoscope-SpaceCadet.h"
//#include "Kaleidoscope-DynamicMacros.h"
//#include "Kaleidoscope-LayerNames.h"

#define SL(n) ShiftToLayer(n)
#define LL(n) LockLayer(n)
// ML is used in key_defs/keymaps.h
#define MTL(n) MoveToLayer(n)

enum {
  MACRO_PRIMARY,
  MACRO_VERSION_INFO
};

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At          LSHIFT(Key_2)
#define Key_Hash        LSHIFT(Key_3)
#define Key_Dollar      LSHIFT(Key_4)
#define Key_Percent     LSHIFT(Key_5)
#define Key_Caret       LSHIFT(Key_6)
#define Key_And         LSHIFT(Key_7)
#define Key_Star        LSHIFT(Key_8)
#define Key_Plus        LSHIFT(Key_Equals)

/**
  * To change your keyboard's layout from QWERTY to DVORAK or COLEMAK, comment out the line
  *
  * #define PRIMARY_KEYMAP_QWERTY
  *
  * by changing it to
  *
  * // #define PRIMARY_KEYMAP_QWERTY
  *
  * Then uncomment the line corresponding to the layout you want to use.
  *
  */

enum {
  COLEMAK_LAYER,
  QWERTY_LAYER,
  SYM_LAYER,
  NUM_LAYER,
  FUN_LAYER,
  NAV_LAYER,
  MOUSE_LAYER,
  MEDIA_LAYER
};

#define REDO LCTRL(LSHIFT(Key_Z))

#define KEY_ESC_MEDIA LT(MEDIA_LAYER, Esc)
#define KEY_SPC_NAV   LT(NAV_LAYER, Space)
#define KEY_TAB_MOUSE LT(MOUSE_LAYER, Tab)
#define KEY_ENT_SYM   LT(SYM_LAYER, Enter)
#define KEY_BSPC_NUM  LT(NUM_LAYER, Backspace)
#define KEY_DEL_FUN   LT(FUN_LAYER, Delete)


// tap dance key enum
enum {
  TD_CUR,
  TD_OPP,
  TD_BOOT,
  TD_TAP,
  TD_EXTRA,
  TD_BASE
};

// Note that XXX = No key, and ___ = Transparent key, which means the one in the stack below is available.
// clang-format off
KEYMAPS(


  [COLEMAK_LAYER] = KEYMAP_STACKED
  (
       Key_Q         ,Key_W           ,Key_F        ,Key_P         ,Key_B
      ,GUI_T(A)      ,ALT_T(R)        ,CTL_T(S)     ,SFT_T(T)      ,Key_G
      ,Key_Z         ,MT(RightAlt, X) ,Key_C        ,Key_D         ,Key_V                ,XXX
      ,XXX           ,XXX             ,XXX          ,KEY_ESC_MEDIA ,KEY_SPC_NAV          ,KEY_TAB_MOUSE

                     ,Key_J           ,Key_L        ,Key_U         ,Key_Y                ,Key_Semicolon
                     ,Key_M           ,SFT_T(N)     ,CTL_T(E)      ,ALT_T(I)             ,GUI_T(O)
      ,XXX           ,Key_K           ,Key_H        ,Key_Comma     ,MT(RightAlt, Period) ,Key_Slash
      ,KEY_ENT_SYM   ,KEY_BSPC_NUM    ,KEY_DEL_FUN  ,XXX           ,XXX                  ,XXX
  ),

  [QWERTY_LAYER] = KEYMAP_STACKED
  (
       Key_Q         ,Key_W           ,Key_E        ,Key_R         ,Key_T
      ,GUI_T(A)      ,ALT_T(S)        ,CTL_T(D)     ,SFT_T(F)      ,Key_G
      ,Key_Z         ,MT(RightAlt, X) ,Key_C        ,Key_V         ,Key_B                ,XXX
      ,XXX           ,XXX             ,XXX          ,KEY_ESC_MEDIA ,KEY_SPC_NAV          ,KEY_TAB_MOUSE

                     ,Key_Y           ,Key_U        ,Key_I         ,Key_O                ,Key_P
                     ,Key_H           ,SFT_T(J)     ,CTL_T(K)      ,ALT_T(L)             ,GUI_T(Semicolon)
      ,XXX           ,Key_N           ,Key_M        ,Key_Comma     ,MT(RightAlt, Period) ,Key_Slash
      ,KEY_ENT_SYM   ,KEY_BSPC_NUM    ,KEY_DEL_FUN  ,XXX           ,XXX                  ,XXX
  ),

  [SYM_LAYER] = KEYMAP_STACKED
  (
       Key_LeftCurlyBracket   ,Key_And                  ,Key_Star       ,Key_LeftParen        ,Key_RightCurlyBracket
      ,LSHIFT(Key_Semicolon)  ,Key_Dollar               ,Key_Percent    ,Key_Caret            ,Key_Plus
      ,LSHIFT(Key_NonUsPound) ,Key_Exclamation          ,Key_At         ,Key_Hash             ,Key_Pipe              ,XXX
      ,XXX                    ,XXX                      ,XXX            ,Key_LeftParen        ,Key_RightParen        ,LSHIFT(Key_Minus)

                              ,XXX                      ,TD(TD_BASE)    ,TD(TD_EXTRA)         ,TD(TD_TAP)            ,TD(TD_BOOT)
                              ,XXX                      ,Key_RightShift ,Key_RightControl     ,Key_RightAlt          ,Key_RightGui
      ,XXX                    ,XXX                      ,TD(TD_CUR)     ,TD(TD_OPP)           ,XXX                   ,XXX
      ,___                    ,XXX                      ,XXX            ,XXX                  ,XXX                   ,XXX
  ),

  [NUM_LAYER] = KEYMAP_STACKED
  (
       Key_LeftBracket      ,Key_7                    ,Key_8          ,Key_9                ,Key_RightBracket
      ,Key_Semicolon        ,Key_4                    ,Key_5          ,Key_6                ,Key_Equals
      ,Key_Backtick         ,Key_1                    ,Key_2          ,Key_3                ,Key_Backslash         ,XXX
      ,XXX                  ,XXX                      ,XXX            ,Key_Period           ,Key_0                 ,Key_Minus

                            ,XXX                      ,TD(TD_BASE)    ,TD(TD_EXTRA)         ,TD(TD_TAP)            ,TD(TD_BOOT)
                            ,XXX                      ,Key_RightShift ,Key_RightControl     ,Key_RightAlt          ,Key_RightGui
      ,XXX                  ,XXX                      ,TD(TD_CUR)     ,TD(TD_OPP)           ,XXX                   ,XXX
      ,XXX                  ,___                      ,XXX            ,XXX                  ,XXX                   ,XXX
  ),

  [FUN_LAYER] = KEYMAP_STACKED
  (
       Key_F12              ,Key_F7                   ,Key_F8         ,Key_F9               ,Key_PrintScreen
      ,Key_F11              ,Key_F4                   ,Key_F5         ,Key_F6               ,Key_ScrollLock
      ,Key_F10              ,Key_F1                   ,Key_F2         ,Key_F3               ,Key_Pause             ,XXX
      ,XXX                  ,XXX                      ,XXX            ,Key_Menu             ,Key_Space             ,Key_Tab

                            ,XXX                      ,TD(TD_BASE)    ,TD(TD_EXTRA)         ,TD(TD_TAP)            ,TD(TD_BOOT)
                            ,XXX                      ,Key_RightShift ,Key_RightControl     ,Key_RightAlt          ,Key_RightGui
      ,XXX                  ,XXX                      ,TD(TD_CUR)     ,TD(TD_OPP)           ,XXX                   ,XXX
      ,XXX                  ,XXX                      ,___            ,XXX                  ,XXX                   ,XXX
  ),

  [NAV_LAYER] = KEYMAP_STACKED
  (
       TD(TD_BOOT)          ,TD(TD_TAP)               ,TD(TD_EXTRA)    ,TD(TD_BASE)          ,XXX
      ,Key_LeftGui          ,Key_LeftAlt              ,Key_LeftControl ,Key_LeftShift        ,XXX
      ,XXX                  ,XXX                      ,TD(TD_OPP)      ,TD(TD_CUR)           ,XXX                   ,XXX
      ,XXX                  ,XXX                      ,XXX             ,XXX                  ,___                   ,XXX

                            ,REDO                     ,Key_Paste       ,Key_Copy             ,Key_Cut               ,Key_Undo
                            ,Key_LeftArrow            ,Key_DownArrow   ,Key_UpArrow          ,Key_RightArrow        ,Key_CapsLock
      ,XXX                  ,Key_Home                 ,Key_PageDown    ,Key_PageUp           ,Key_End               ,Key_Insert
      ,Key_Enter            ,Key_Backspace            ,Key_Delete      ,XXX                  ,XXX                   ,XXX
  ),

  [MOUSE_LAYER] = KEYMAP_STACKED
  (
       TD(TD_BOOT)          ,TD(TD_TAP)               ,TD(TD_EXTRA)    ,TD(TD_BASE)          ,XXX
      ,Key_LeftGui          ,Key_LeftAlt              ,Key_LeftControl ,Key_LeftShift        ,XXX
      ,XXX                  ,XXX                      ,TD(TD_OPP)      ,TD(TD_CUR)           ,XXX                   ,XXX
      ,XXX                  ,XXX                      ,XXX             ,XXX                  ,XXX                   ,___

                            ,REDO                     ,Key_Paste       ,Key_Copy             ,Key_Cut               ,Key_Undo
                            ,Key_mouseL               ,Key_mouseDn     ,Key_mouseUp          ,Key_mouseR            ,Key_mouseScrollUp
      ,XXX                  ,Key_mouseWarpW           ,Key_mouseWarpS  ,Key_mouseWarpN       ,Key_mouseWarpE        ,Key_mouseScrollDn
      ,Key_mouseBtnR        ,Key_mouseBtnL            ,Key_mouseBtnM   ,XXX                  ,XXX                   ,XXX
  ),

  [MEDIA_LAYER] = KEYMAP_STACKED
  (
       TD(TD_BOOT)          ,TD(TD_TAP)               ,TD(TD_EXTRA)    ,TD(TD_BASE)          ,XXX
      ,Key_LeftGui          ,Key_LeftAlt              ,Key_LeftControl ,Key_LeftShift        ,XXX
      ,XXX                  ,XXX                      ,TD(TD_OPP)      ,TD(TD_CUR)           ,XXX                   ,XXX
      ,XXX                  ,XXX                      ,XXX             ,___                  ,XXX                   ,XXX

                            ,REDO                     ,Key_Paste       ,Key_Copy             ,Key_Cut               ,Key_Undo
                            ,Key_LeftArrow            ,Key_DownArrow   ,Key_UpArrow          ,Key_RightArrow        ,Key_CapsLock
      ,XXX                  ,Key_Home                 ,Key_PageDown    ,Key_PageUp           ,Key_End               ,Key_Insert
      ,Key_Enter            ,Key_Backspace            ,Key_Delete      ,XXX                  ,XXX                   ,XXX
  )

)

// clang-format on

/* for QuKeys, the following addresses are for the Atreus:

  R0C0, R0C1, R0C2, R0C3, R0C4, XXX,  XXX,  R0C7, R0C8, R0C9, R0C10, R0C11, \
  R1C0, R1C1, R1C2, R1C3, R1C4, XXX,  XXX,  R1C7, R1C8, R1C9, R1C10, R1C11, \
  R2C0, R2C1, R2C2, R2C3, R2C4, R2C5, R2C6, R2C7, R2C8, R2C9, R2C10, R2C11, \
  R3C0, R3C1, R3C2, R3C3, R3C4, R3C5, R3C6, R3C7, R3C8, R3C9, R3C10, R3C11

*/

KALEIDOSCOPE_INIT_PLUGINS(
  // ----------------------------------------------------------------------
  // Chrysalis plugins

  // The EEPROMSettings & EEPROMKeymap plugins make it possible to have an
  // editable keymap in EEPROM.
  //EEPROMSettings,
  //EEPROMKeymap,

  // Focus allows bi-directional communication with the host, and is the
  // interface through which the keymap in EEPROM can be edited.
  //Focus,

  // FocusSettingsCommand adds a few Focus commands, intended to aid in
  // changing some settings of the keyboard, such as the default layer (via the
  // `settings.defaultLayer` command)
  //FocusSettingsCommand,

  // FocusEEPROMCommand adds a set of Focus commands, which are very helpful in
  // both debugging, and in backing up one's EEPROM contents.
  //FocusEEPROMCommand,

  // The FirmwareVersion plugin lets Chrysalis query the version of the firmware
  // programmatically.
  //FirmwareVersion,

  // The LayerNames plugin allows Chrysalis to display - and edit - custom layer
  // names, to be shown instead of the default indexes.
  //LayerNames,

  // ----------------------------------------------------------------------
  // Keystroke-handling plugins

  // The Qukeys plugin enables the "Secondary action" functionality in
  // Chrysalis. Keys with secondary actions will have their primary action
  // performed when tapped, but the secondary action when held.
  Qukeys,

  // Tap-dance keys are general purpose, multi-use keys, which trigger a different action based on the number of times they were tapped in
  // sequence. As an example to make this clearer, one can have a key that inputs A when tapped once, inputs B when tapped twice, and
  // lights up the keyboard in Christmas colors when tapped a third time
  TapDance,

  // SpaceCadet can turn your shifts into parens on tap, while keeping them as
  // Shifts when held. SpaceCadetConfig lets Chrysalis configure some aspects of
  // the plugin.
  //SpaceCadet,
  //SpaceCadetConfig,

  // Enables the "Sticky" behavior for modifiers, and the "Layer shift when
  // held" functionality for layer keys.
  OneShot,
  OneShotConfig,
  EscapeOneShot,
  EscapeOneShotConfig,

  // The macros plugin adds support for macros
  Macros,

  // Enables dynamic, Chrysalis-editable macros.
  //DynamicMacros,

  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
  MouseKeys,
  MouseKeysConfig  //,

  // The MagicCombo plugin lets you use key combinations to trigger custom
  // actions - a bit like Macros, but triggered by pressing multiple keys at the
  // same time.
  // MagicCombo,

);

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
  if (keyToggledOn(event.state)) {
    switch (macro_id) {
    case MACRO_PRIMARY:
      // This macro is currently unused, but is kept around for compatibility
      // reasons. We used to use it in place of `MoveToLayer(PRIMARY)`, but no
      // longer do. We keep it so that if someone still has the old layout with
      // the macro in EEPROM, it will keep working after a firmware update.
      Layer.move(COLEMAK_LAYER);
      break;
    case MACRO_VERSION_INFO:
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
      break;
    default:
      break;
    }
  }
  return MACRO_NONE;
}

// calculate the opposite layer for the OPP tapDance key when on a layer.
// relies on holding and shifting to the layer, and then doing the tapdance.
uint8_t oppLayer(uint8_t cur_layer) {
  switch (cur_layer) {
    case COLEMAK_LAYER:
      return QWERTY_LAYER;
    case QWERTY_LAYER:
      return COLEMAK_LAYER;
    case SYM_LAYER:
      return MOUSE_LAYER;
    case MOUSE_LAYER:
      return SYM_LAYER;
    case NUM_LAYER:
      return NAV_LAYER;
    case NAV_LAYER:
      return NUM_LAYER;
    case FUN_LAYER:
      return MEDIA_LAYER;
    case MEDIA_LAYER:
      return FUN_LAYER;
  }
  return cur_layer;
}

// we use tap-dance for the double tap requirements for the CUR, OPP, BASE, EXTRA, TAP and BOOT function keys in the keymap.
// They are represented as TD(TD_CUR), etc.
void tapDanceDouble(uint8_t tap_dance_index, KeyAddr key_addr, uint8_t tap_count, kaleidoscope::plugin::TapDance::ActionType tap_dance_action) {
  if (tap_count != 2) {
    return;
  }
  switch (tap_dance_index) {
    case TD_CUR:
      // Move to the current layer; this is a one way opp, and TD_BASE, or TD_EXTRA is needed to get 'out'.
      Layer.move(Layer.mostRecent());
      break;
    case TD_OPP:
      // Move to the opposite thumb layer; this is a one way operation, and TD_BASE or TD_EXTRA is need to get 'out'
      Layer.move(oppLayer(Layer.mostRecent()));
      break;
    case TD_BOOT:
      Kaleidoscope.device().rebootBootloader();
      break;  // not really necessary as rebootBootloader() doesn't return.
    case TD_TAP:
      // Tap is about disabling the dual function keys for the primary alpha; we'll ignore this for the moment.
      break;
    case TD_EXTRA:
      Layer.move(QWERTY_LAYER);
      break;
    case TD_BASE:
      Layer.move(COLEMAK_LAYER);
      break;
  }
}

void tapDanceAction(uint8_t tap_dance_index, KeyAddr key_addr, uint8_t tap_count, kaleidoscope::plugin::TapDance::ActionType tap_dance_action) {
  tapDanceDouble(tap_dance_index, key_addr, tap_count, tap_dance_action);
}


void setup() {
  // set up qukeys before the kaleidoscope.setup() call.
  // Note that these are default values.

  Qukeys.setHoldTimeout(250);
  Qukeys.setMaxIntervalForTapRepeat(200);
  Qukeys.setOverlapThreshold(80);
  Qukeys.setMinimumHoldTime(50);
  Qukeys.setMinimumPriorInterval(75);

  Kaleidoscope.setup();

  //EEPROMKeymap.setup(9);

  //DynamicMacros.reserve_storage(48);

  //LayerNames.reserve_storage(63);

  //Layer.move(EEPROMSettings.default_layer());

  // Disable space cadet as we don't have shift keys on each side.
  // To avoid any surprises, SpaceCadet is turned off by default. However, it
  // can be permanently enabled via Chrysalis, so we should only disable it if
  // no configuration exists.
  //SpaceCadetConfig.disableSpaceCadetIfUnconfigured();

  // TODO[ajkavanagh]:
  // * TapDance actions for TD_CUR, TD_OPP, TD_EXTRA, TD_TAP, TD_BASE, TD_BOOT

}

void loop() {
  Kaleidoscope.loop();
}

// # vim: filetype=arduino tabstop=2 softtabstop=2 shiftwidth=2 textwidth=140 expandtab autoindent :
