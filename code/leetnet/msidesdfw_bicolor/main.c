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

//added for LED net driver
#define LED34_PIN 4
SBIT(LED34, 0xB0, LED34_PIN);


//added for breath effects
int i=0;
int count=0;
int bright=350;
int inhale=1250;
int pulse=3571;
int rest=1000;

//added because 0 isn't always 0
int LED_ON  = 1;
int LED_OFF = 0;


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
    // Configure pin 3.2 as GPIO output
    P3_MOD_OC = P3_MOD_OC & ~(1<<LED32_PIN);
    P3_DIR_PU = P3_DIR_PU |	(1<<LED32_PIN);
    // Configure pin 3.3 as GPIO output
    P3_MOD_OC = P3_MOD_OC & ~(1<<LED33_PIN);
    P3_DIR_PU = P3_DIR_PU |	(1<<LED33_PIN);


    // Configure pin 3.4 as GPIO output
    P3_MOD_OC = P3_MOD_OC & ~(1<<LED34_PIN);
    P3_DIR_PU = P3_DIR_PU |	(1<<LED34_PIN);

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
    LED30 = LED_OFF;
    LED31 = LED_OFF;
    LED32 = LED_OFF;
    LED33 = LED_OFF;
    LED14 = LED_OFF;
    LED15 = LED_OFF;
    LED16 = LED_OFF;
    LED17 = LED_OFF;

    //added for LED net driver
    LED34 = LED_ON; //should be blue

    //added for a red start
    LED_ON = !LED_ON;
    LED_OFF = !LED_OFF;
    LED34 = !LED34;


    while (1) {
      if (ledmode < 5) //rolling mode, 1-4
      {
        // Delay controls speed
        mDelaymS(40 * ledmode);
        // Button starts as TRUE 1 and pulls down to FALSE 0 when pushed
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Turn off previous two, turn on next two
        LED33 = LED_OFF;
        LED30 = LED_ON;
        LED17 = LED_OFF;
        LED14 = LED_ON;
        // Delay controls speed
      	mDelaymS(40 * ledmode);
        // Button starts as TRUE 1 and pulls down to FALSE 0 when pushed
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Turn off previous two, turn on next two
        LED30 = LED_OFF;
        LED31 = LED_ON;
        LED14 = LED_OFF;
        LED15 = LED_ON;
        // Delay controls speed
        mDelaymS(40 * ledmode);
        // Button starts as TRUE 1 and pulls down to FALSE 0 when pushed
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Turn off previous two, turn on next two
        LED31 = LED_OFF;
        LED32 = LED_ON;
        LED15 = LED_OFF;
        LED16 = LED_ON;
        // Delay controls speed
        mDelaymS(40 * ledmode);
        // Button starts as TRUE 1 and pulls down to FALSE 0 when pushed
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Turn off previous two, turn on next two
        LED32 = LED_OFF;
        LED33 = LED_ON;
        LED16 = LED_OFF;
        LED17 = LED_ON;
      }
      if (ledmode == 5) //single LED walking pulse
      {
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        for( count = 0; count < 8; count = count + 1 ){
            if (BUTTON11 == 0) { button11push = 1; }
	    for( i = 1; i < bright; i = i + 1 ){
                if (count == 0) {LED14 = LED_ON;}
                if (count == 1) {LED15 = LED_ON;}
                if (count == 2) {LED16 = LED_ON;}
                if (count == 3) {LED17 = LED_ON;}
                if (count == 4) {LED30 = LED_ON;}
                if (count == 5) {LED31 = LED_ON;}
                if (count == 6) {LED32 = LED_ON;}
                if (count == 7) {LED33 = LED_ON;}
                mDelayuS(i*10);
                if (count == 0) {LED14 = LED_OFF;}
                if (count == 1) {LED15 = LED_OFF;}
                if (count == 2) {LED16 = LED_OFF;}
                if (count == 3) {LED17 = LED_OFF;}
                if (count == 4) {LED30 = LED_OFF;}
                if (count == 5) {LED31 = LED_OFF;}
                if (count == 6) {LED32 = LED_OFF;}
                if (count == 7) {LED33 = LED_OFF;}
                mDelayuS(pulse-i*10);
            }
            if (BUTTON11 == 0) { button11push = 1; }
            for( i = bright-1; i>0; i = i - 1 ){
                if (count == 0) {LED14 = LED_ON;}
                if (count == 1) {LED15 = LED_ON;}
                if (count == 2) {LED16 = LED_ON;}
                if (count == 3) {LED17 = LED_ON;}
                if (count == 4) {LED30 = LED_ON;}
                if (count == 5) {LED31 = LED_ON;}
                if (count == 6) {LED32 = LED_ON;}
                if (count == 7) {LED33 = LED_ON;}
                mDelayuS(i*10);
                if (count == 0) {LED14 = LED_OFF;}
                if (count == 1) {LED15 = LED_OFF;}
                if (count == 2) {LED16 = LED_OFF;}
                if (count == 3) {LED17 = LED_OFF;}
                if (count == 4) {LED30 = LED_OFF;}
                if (count == 5) {LED31 = LED_OFF;}
                if (count == 6) {LED32 = LED_OFF;}
                if (count == 7) {LED33 = LED_OFF;}
                mDelayuS(pulse-i*10);
            }
	    if (BUTTON11 == 0) { button11push = 1; }
        }
      }
      if (ledmode == 6) //led walking pulse, group die off
      {
	for( count = 0; count < 8; count = count + 1 ){
            if (BUTTON11 == 0) { button11push = 1; }
	    for( i = 1; i < bright; i = i + 1 ){
                if (count == 0) {LED14 = LED_ON;}
                if (count == 1) {LED15 = LED_ON;}
                if (count == 2) {LED16 = LED_ON;}
                if (count == 3) {LED17 = LED_ON;}
                if (count == 4) {LED30 = LED_ON;}
                if (count == 5) {LED31 = LED_ON;}
                if (count == 6) {LED32 = LED_ON;}
                if (count == 7) {LED33 = LED_ON;}
                mDelayuS(i*10);
                if (count == 0) {LED14 = LED_OFF;}
                if (count == 1) {LED15 = LED_OFF;}
                if (count == 2) {LED16 = LED_OFF;}
                if (count == 3) {LED17 = LED_OFF;}
                if (count == 4) {LED30 = LED_OFF;}
                if (count == 5) {LED31 = LED_OFF;}
                if (count == 6) {LED32 = LED_OFF;}
                if (count == 7) {LED33 = LED_OFF;}
                mDelayuS(pulse-i*10);
            }
            if (BUTTON11 == 0) { button11push = 1; }
            for( i = bright-1; i>0; i = i - 1 ){
                LED14 = LED_ON;
                LED15 = LED_ON;
                LED16 = LED_ON;
                LED17 = LED_ON;
                LED30 = LED_ON;
                LED31 = LED_ON;
                LED32 = LED_ON;
                LED33 = LED_ON;
                mDelayuS(i*10);
                LED14 = LED_OFF;
                LED15 = LED_OFF;
                LED16 = LED_OFF;
                LED17 = LED_OFF;
                LED30 = LED_OFF;
                LED31 = LED_OFF;
                LED32 = LED_OFF;
                LED33 = LED_OFF;
                mDelayuS(pulse-i*10);
            }
	    if (BUTTON11 == 0) { button11push = 1; }
        }
      }
      if (ledmode == 7) //fracking cylons
      {
	if (BUTTON11 == 0) { button11push = 1; }
	//go there
        LED14 = LED_ON;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_ON;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_ON;
        LED17 = LED_OFF;
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_ON;
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        LED30 = LED_ON;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        LED30 = LED_OFF;
        LED31 = LED_ON;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_ON;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_ON;
        //and back again
        mDelaymS(250);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_ON;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        LED30 = LED_OFF;
        LED31 = LED_ON;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        LED30 = LED_ON;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_ON;
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_ON;
        LED17 = LED_OFF;
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_OFF;
        LED15 = LED_ON;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = LED_ON;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        mDelaymS(250);
	if (BUTTON11 == 0) { button11push = 1; }
      }
      if (ledmode == 8) //group pulsing mode
      {
	if (BUTTON11 == 0) { button11push = 1; }
	for( i = 1; i < bright; i = i + 1 ){
            LED14 = LED_ON;
            LED15 = LED_ON;
            LED16 = LED_ON;
            LED17 = LED_ON;
            LED30 = LED_ON;
            LED31 = LED_ON;
            LED32 = LED_ON;
            LED33 = LED_ON;
            mDelayuS(i*10);
            LED14 = LED_OFF;
            LED15 = LED_OFF;
            LED16 = LED_OFF;
            LED17 = LED_OFF;
            LED30 = LED_OFF;
            LED31 = LED_OFF;
            LED32 = LED_OFF;
            LED33 = LED_OFF;
            mDelayuS(pulse-i*10);
        }
	if (BUTTON11 == 0) { button11push = 1; }
        for( i = bright-1; i>0; i = i - 1 ){
            LED14 = LED_ON;
            LED15 = LED_ON;
            LED16 = LED_ON;
            LED17 = LED_ON;
            LED30 = LED_ON;
            LED31 = LED_ON;
            LED32 = LED_ON;
            LED33 = LED_ON;
            mDelayuS(i*10);
            LED14 = LED_OFF;
            LED15 = LED_OFF;
            LED16 = LED_OFF;
            LED17 = LED_OFF;
            LED30 = LED_OFF;
            LED31 = LED_OFF;
            LED32 = LED_OFF;
            LED33 = LED_OFF;
            mDelayuS(pulse-i*10);
        }
	if (BUTTON11 == 0) { button11push = 1; }
      }
      if (ledmode == 9) //bi-color flashing mode
      {
        if (BUTTON11 == 0) { button11push = 1; }
        mDelaymS(150);
        LED30 = LED_ON;
        LED31 = LED_ON;
        LED32 = LED_ON;
        LED33 = LED_ON;
        LED14 = LED_ON;
        LED15 = LED_ON;
        LED16 = LED_ON;
        LED17 = LED_ON;
        if (BUTTON11 == 0) { button11push = 1; }
        mDelaymS(100);
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_OFF;
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_OFF;

	//switch states!
        LED_ON = !LED_ON;
        LED_OFF = !LED_OFF;
        LED34 = !LED34;
      }
      if (ledmode == 10) //following mode
      {
        if (BUTTON11 == 0) { button11push = 1; }
        mDelaymS(40 * ledmode);
        LED14 = LED_ON;
        LED15 = LED_OFF;
        LED16 = LED_OFF;
        LED17 = LED_ON;
        LED30 = LED_OFF;
        LED31 = LED_OFF;
        LED32 = LED_ON;
        LED33 = LED_OFF;
        if (BUTTON11 == 0) { button11push = 1; }
        mDelaymS(40 * ledmode);
        LED14 = LED_OFF;
        LED15 = LED_ON;
        LED16 = LED_OFF;
        LED17 = LED_OFF;
        LED30 = LED_ON;
        LED31 = LED_OFF;
        LED32 = LED_OFF;
        LED33 = LED_ON;
        if (BUTTON11 == 0) { button11push = 1; }
        mDelaymS(40 * ledmode);
        LED14 = LED_OFF;
        LED15 = LED_OFF;
        LED16 = LED_ON;
        LED17 = LED_OFF;
        LED30 = LED_OFF;
        LED31 = LED_ON;
        LED32 = LED_OFF;
        LED33 = LED_OFF;

      }
      if (ledmode == 11) //binary flash mode
      {
        // -------------------------------------- 01 - M - 155
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = LED_OFF, LED15 = LED_ON, LED16 = LED_ON, LED17 = LED_OFF, LED30 = LED_ON, LED31 = LED_ON, LED32 = LED_OFF, LED33 = LED_ON;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        //
        // -------------------------------------- 02 - @ - 100
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = LED_OFF, LED15 = LED_ON, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        //
        // -------------------------------------- 03 - L - 154
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = LED_OFF, LED15 = LED_ON, LED16 = LED_ON, LED17 = LED_OFF, LED30 = LED_ON, LED31 = LED_ON, LED32 = LED_OFF, LED33 = LED_OFF;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        //
        // -------------------------------------- 04 - E - 145
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = LED_OFF, LED15 = LED_ON, LED16 = LED_ON, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_ON, LED32 = LED_OFF, LED33 = LED_ON;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        //
        // -------------------------------------- 05 - E - 145
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = LED_OFF, LED15 = LED_ON, LED16 = LED_ON, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_ON, LED32 = LED_OFF, LED33 = LED_ON;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        //
        // -------------------------------------- 06 - T - 164
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = LED_OFF, LED15 = LED_ON, LED16 = LED_ON, LED17 = LED_ON, LED30 = LED_OFF, LED31 = LED_ON, LED32 = LED_OFF, LED33 = LED_OFF;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        //
        // -------------------------------------- 07 - N - 156
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = LED_OFF, LED15 = LED_ON, LED16 = LED_ON, LED17 = LED_OFF, LED30 = LED_ON, LED31 = LED_ON, LED32 = LED_ON, LED33 = LED_OFF;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        //
        // -------------------------------------- 08 - E - 145
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = LED_OFF, LED15 = LED_ON, LED16 = LED_ON, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_ON, LED32 = LED_OFF, LED33 = LED_ON;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        //
        // -------------------------------------- 09 - T - 164
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = LED_OFF, LED15 = LED_ON, LED16 = LED_ON, LED17 = LED_ON, LED30 = LED_OFF, LED31 = LED_ON, LED32 = LED_OFF, LED33 = LED_OFF;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        //
        // -------------------------------------- 10 - . - 056
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_ON, LED17 = LED_OFF, LED30 = LED_ON, LED31 = LED_ON, LED32 = LED_ON, LED33 = LED_OFF;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        //
        // -------------------------------------- 11 - N - 156
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = LED_OFF, LED15 = LED_ON, LED16 = LED_ON, LED17 = LED_OFF, LED30 = LED_ON, LED31 = LED_ON, LED32 = LED_ON, LED33 = LED_OFF;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        //
        // -------------------------------------- 12 - E - 145
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = LED_OFF, LED15 = LED_ON, LED16 = LED_ON, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_ON, LED32 = LED_OFF, LED33 = LED_ON;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        //
        // -------------------------------------- 13 - T - 164
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = LED_OFF, LED15 = LED_ON, LED16 = LED_ON, LED17 = LED_ON, LED30 = LED_OFF, LED31 = LED_ON, LED32 = LED_OFF, LED33 = LED_OFF;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        // -------------------------------------- 99
        // Delay to display previous LED state
        mDelaymS(900);
        // LEDs OFF
        LED14 = LED_OFF, LED15 = LED_OFF, LED16 = LED_OFF, LED17 = LED_OFF, LED30 = LED_OFF, LED31 = LED_OFF, LED32 = LED_OFF, LED33 = LED_OFF;
        // EOL
      }
      // If button was pushed during the cycle above then flag should be set
      if (button11push == 1)
      {
        // Increase LED Mode value
        if (!LED34)
        {
          ledmode = ledmode + 1;
        }
        // Check if LED Mode value is beyond max value and if so set to min value
        if (ledmode > 11)
        {
          ledmode = 1;
        }
        // Reset button push flag
        button11push = 0;
        LED_ON = !LED_ON;
        LED_OFF = !LED_OFF;
        LED34 = !LED34;
      }
    }
}
