#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ORYX_CONFIGURATOR
#define PLANCK_EZ_LED_LOWER 1
#define PLANCK_EZ_LED_RAISE 2
#define PLANCK_EZ_LED_ADJUST 3

#define ENCODER_RESOLUTION 4

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 13

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 9

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 50

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 8

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#define IGNORE_MOD_TAP_INTERRUPT

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 10

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0

#undef MOUSEKEY_WHEEL_DELTA
#define MOUSEKEY_WHEEL_DELTA 1
//|`MOUSEKEY_WHEEL_DELAY`      |300    |Delay between pressing a wheel key and wheel movement    |
//|`MOUSEKEY_WHEEL_INTERVAL`   |100    |Time between wheel movements                             |
//|`MOUSEKEY_WHEEL_MAX_SPEED`  |8      |Maximum number of scroll steps per scroll action         |
//|`MOUSEKEY_WHEEL_TIME_TO_MAX`|40     |Time until maximum scroll speed is reached               |


// Audio
// 
#undef  TEMPO_DEFAULT
#define TEMPO_DEFAULT 200
// #undef  PITCH_STANDARD_A
// #define PITCH_STANDARD_A 1720.0f
//
//#define AUDIO_PIN A5
//#define AUDIO_PIN_ALT A4
//#define AUDIO_PIN_ALT_AS_NEGATIVE
//#define AUDIO_DAC_SAMPLE_MAX 3072U

#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_MAX 2500.0f
#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.05f

