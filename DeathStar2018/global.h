
#ifndef GLOBAL_H
#define GLOBAL_H


#define TieFighterExplodesPin 3

#define END_OF_TIME 86400000    // 86400000 is one day


// Pins
#define ON_BOARD_LED_PIN 13     // will use in loop to notify we are alive

// lights output
#define NEOPIXEL_STRIP_PIN 30
#define NEOPIXEL_Ring_PIN  9
#define TIE_FIGHTER1_SHOOT_PIN  1    // Green LED on Target that lights up when it fires at player
#define TIE_FIGHTER2_SHOOT_PIN  2
#define TIE_FIGHTER3_SHOOT_PIN  3
#define TIE_FIGHTER4_SHOOT_PIN  4
#define TIE_FIGHTER5_SHOOT_PIN  5

// sensors
#define TIE_FIGHTER1_HIT_PIN  21    // tells us that
#define TIE_FIGHTER2_HIT_PIN  22
#define TIE_FIGHTER3_HIT_PIN  23
#define TIE_FIGHTER4_HIT_PIN  24
#define TIE_FIGHTER5_HIT_PIN  25
#define VENT_TARGET_HIT

// audio
#define TIE_FIGHTER_SHOOT_SOUND  10
#define TIE_FIGHTER_EXPLODE_PIN  11
#define DEATH_STAR_EXPLODE_PIN   12
// pin is used for interanl LED




#endif // GLOBAL_H
