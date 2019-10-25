// Chase LEDs in two groups
// LEDs connected to pins 1.4, 1.5, 1.6, 1.7, 3.0, 3.1, 3.2, 3.3
// Tactile switch connected to pin 1.1

#include <ch554.h>
#include <debug.h>

#define LED30_PIN 0
#define LED31_PIN 1
#define LED32_PIN 2
#define LED33_PIN 3
#define LED14_PIN 4
#define LED15_PIN 5
#define LED16_PIN 6
#define LED17_PIN 7

#define BUTTON11_PIN 1

// P1 = 0x90 P3 = 0xB0
SBIT(LED30, 0xB0, LED30_PIN);
SBIT(LED31, 0xB0, LED31_PIN);
SBIT(LED32, 0xB0, LED32_PIN);
SBIT(LED33, 0xB0, LED33_PIN);
SBIT(LED14, 0x90, LED14_PIN);
SBIT(LED15, 0x90, LED15_PIN);
SBIT(LED16, 0x90, LED16_PIN);
SBIT(LED17, 0x90, LED17_PIN);

SBIT(BUTTON11, 0x90, BUTTON11_PIN);

// 1 byte integer for putton push flag - no bool type available
uint8_t button11push=0;
// 1 byte integer for LED Mode (controlled by button)
// Modes 1 thru 4 are chase at different speeds, Mode 5 is cryto challenge
uint8_t ledmode=1;


void main() {
    CfgFsys();

    // Configure pin 3.0 as GPIO output
    P3_MOD_OC = P3_MOD_OC & ~(1<<LED30_PIN);
    P3_DIR_PU = P3_DIR_PU |	(1<<LED30_PIN);
    // Configure pin 3.1 as GPIO output
    P3_MOD_OC = P3_MOD_OC & ~(1<<LED31_PIN);
    P3_DIR_PU = P3_DIR_PU |	(1<<LED31_PIN);
    // Configure pin 3.0 as GPIO output
    P3_MOD_OC = P3_MOD_OC & ~(1<<LED32_PIN);
    P3_DIR_PU = P3_DIR_PU |	(1<<LED32_PIN);
    // Configure pin 3.1 as GPIO output
    P3_MOD_OC = P3_MOD_OC & ~(1<<LED33_PIN);
    P3_DIR_PU = P3_DIR_PU |	(1<<LED33_PIN);

    // Configure pin 1.4 as GPIO output
    P1_MOD_OC = P1_MOD_OC & ~(1<<LED14_PIN);
    P1_DIR_PU = P1_DIR_PU |	(1<<LED14_PIN);
    // Configure pin 1.5 as GPIO output
    P1_MOD_OC = P1_MOD_OC & ~(1<<LED15_PIN);
    P1_DIR_PU = P1_DIR_PU |	(1<<LED15_PIN);
    // Configure pin 1.6 as GPIO output
    P1_MOD_OC = P1_MOD_OC & ~(1<<LED16_PIN);
    P1_DIR_PU = P1_DIR_PU |	(1<<LED16_PIN);
    // Configure pin 1.7 as GPIO output
    P1_MOD_OC = P1_MOD_OC & ~(1<<LED17_PIN);
    P1_DIR_PU = P1_DIR_PU |	(1<<LED17_PIN);

    // All LEDs start with a value of 1 which is ON
    // Turn ALL OFF to start
    LED30 = 0;  // OFF
    LED31 = 0;  // OFF
    LED32 = 0;  // OFF
    LED33 = 0;  // OFF
    LED14 = 0;  // OFF
    LED15 = 0;  // OFF
    LED16 = 0;  // OFF
    LED17 = 0;  // OFF

    while (1) {

      if (ledmode < 5)
      {
        // Delay controls speed
        mDelaymS(40 * ledmode);
        // Button starts as TRUE 1 and pulls down to FALSE 0 when pushed
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Turn off previous two, turn on next two
        LED33 = 0;  // OFF
        LED30 = 1;  // ON
        LED17 = 0;  // OFF
        LED14 = 1;  // ON
        // Delay controls speed
      	mDelaymS(40 * ledmode);
        // Button starts as TRUE 1 and pulls down to FALSE 0 when pushed
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Turn off previous two, turn on next two
        LED30 = 0;  // OFF
        LED31 = 1;  // ON
        LED14 = 0;  // OFF
        LED15 = 1;  // ON
        // Delay controls speed
        mDelaymS(40 * ledmode);
        // Button starts as TRUE 1 and pulls down to FALSE 0 when pushed
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Turn off previous two, turn on next two
        LED31 = 0;  // OFF
        LED32 = 1;  // ON
        LED15 = 0;  // OFF
        LED16 = 1;  // ON
        // Delay controls speed
        mDelaymS(40 * ledmode);
        // Button starts as TRUE 1 and pulls down to FALSE 0 when pushed
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Turn off previous two, turn on next two
        LED32 = 0;  // OFF
        LED33 = 1;  // ON
        LED16 = 0;  // OFF
        LED17 = 1;  // ON
      }

      if (ledmode == 5)
      {
        // -------------------------------------- 01
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 1, LED33 = 1;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 02
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 1, LED33 = 0;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 03
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 0, LED31 = 1, LED32 = 1, LED33 = 1;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 04
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 0, LED31 = 1, LED32 = 1, LED33 = 1;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 05
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 1, LED30 = 0, LED31 = 1, LED32 = 0, LED33 = 0;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 06
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 1, LED31 = 1, LED32 = 1, LED33 = 1;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 07
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 0, LED16 = 1, LED17 = 0, LED30 = 1, LED31 = 1, LED32 = 1, LED33 = 0;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 08
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 1, LED31 = 0, LED32 = 1, LED33 = 1;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 09
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 1, LED30 = 0, LED31 = 0, LED32 = 1, LED33 = 1;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 10
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 1, LED30 = 1, LED31 = 0, LED32 = 1, LED33 = 0;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 11
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 1, LED30 = 0, LED31 = 0, LED32 = 1, LED33 = 0;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 12
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 1;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 13
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 1, LED31 = 1, LED32 = 0, LED33 = 0;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 14
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 1, LED31 = 0, LED32 = 0, LED33 = 1;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 15
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 1, LED30 = 0, LED31 = 1, LED32 = 0, LED33 = 1;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 16
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 0, LED31 = 1, LED32 = 1, LED33 = 1;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 17
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 0, LED31 = 1, LED32 = 0, LED33 = 1;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 18
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 0, LED16 = 1, LED17 = 0, LED30 = 1, LED31 = 1, LED32 = 1, LED33 = 0;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 19
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 1, LED31 = 1, LED32 = 0, LED33 = 1;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 20
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 1, LED30 = 0, LED31 = 1, LED32 = 1, LED33 = 1;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 21
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 0, LED31 = 1, LED32 = 0, LED33 = 0;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 99
        // Delay to display previous LED state
        mDelaymS(900);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        // EOL
      }

      // If button was pushed during the cycle above then flag should be set
      if (button11push == 1)
      {
        // Increase LED Mode value
        ledmode = ledmode + 1;
        // Check if LED Mode value is beyond max value and if so set to min value
        if (ledmode > 5) { ledmode = 1; }
        // Reset button push flag
        button11push = 0;
      }

    }
}
