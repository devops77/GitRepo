
#ifndef GLOBAL_H
#define GLOBAL_H


#define TieFighterExplodesPin 3

#define END_OF_TIME 86400000    // 86400000 is one day


// Pins
#define ON_BOARD_LED_PIN 13     // will use in loop to notify we are alive

// lights output
#define NEOPIXEL_STRIP_PIN 22
#define NEOPIXEL_RING_PIN  24
  // save 24 25 incase we split or add lights
#define TIE_FIGHTER1_SHOOT_PIN  1    // Green LED on Target that lights up when it fires at player
#define TIE_FIGHTER2_SHOOT_PIN  2
#define TIE_FIGHTER3_SHOOT_PIN  3
#define TIE_FIGHTER4_SHOOT_PIN  4
#define TIE_FIGHTER5_SHOOT_PIN  5

// sensors
#define TIE_FIGHTER1_HIT_PIN  31    // tells us that
#define TIE_FIGHTER2_HIT_PIN  32
#define TIE_FIGHTER3_HIT_PIN  33
#define TIE_FIGHTER4_HIT_PIN  34
#define TIE_FIGHTER5_HIT_PIN  35
#define VENT_TARGET_HIT       36

// audio
#define TIE_FIGHTER_SHOOT_SOUND  40
#define TIE_FIGHTER_EXPLODE_PIN  41
#define DEATH_STAR_EXPLODE_PIN   42
// pin is used for interanl LED




#endif // GLOBAL_H
