
#ifndef GLOBAL_H
#define GLOBAL_H


//#define TieFighterExplodesPin 3

#define END_OF_TIME 86400000    // 86400000 is one day

#define FaceNumberOfLights 94

// Pins
#define ON_BOARD_LED_PIN 13     // will use in loop to notify we are alive

// lights output
#define NEOPIXEL_DS_FACE_PIN 40
#define NEOPIXEL_STRIP_PIN   41  //tie taget back ground
#define NEOPIXEL_RING_PIN    42  // vent port
  // save 24 25 incase we split or add lights
#define TIE_FIGHTER1_SHOOT_PIN  34    // Green LED on Target that lights up when it fires at player
#define TIE_FIGHTER2_SHOOT_PIN  35
#define TIE_FIGHTER3_SHOOT_PIN  36
#define TIE_FIGHTER4_SHOOT_PIN  37
#define TIE_FIGHTER5_SHOOT_PIN  38

// sensors
#define TIE_FIGHTER1_HIT_PIN  26    // tells us that
#define TIE_FIGHTER2_HIT_PIN  27
#define TIE_FIGHTER3_HIT_PIN  28
#define TIE_FIGHTER4_HIT_PIN  29
#define TIE_FIGHTER5_HIT_PIN  30
#define VENT_TARGET_HIT       31

// audio
#define TIE_FIGHTER_SHOOT_SOUND  0
#define TIE_FIGHTER_EXPLODE_PIN  1
#define DEATH_STAR_EXPLODE_PIN   2
// pin is used for interanl LED


extern int numberOfTargetsDown;

#endif // GLOBAL_H
