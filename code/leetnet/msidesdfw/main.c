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

int i=0;
int count=0;
int bright=350;
int inhale=1250;
int pulse=3571;
int rest=1000;

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

      if (ledmode < 5) //rolling mode, 1-4
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
      if (ledmode == 5) //single LED walking pulse
      {
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
	
        for( count = 0; count < 8; count = count + 1 ){
            if (BUTTON11 == 0) { button11push = 1; }
	    for( i = 1; i < bright; i = i + 1 ){
                if (count == 0) {LED14 = 1;}
                if (count == 1) {LED15 = 1;}
                if (count == 2) {LED16 = 1;}
                if (count == 3) {LED17 = 1;}
                if (count == 4) {LED30 = 1;}
                if (count == 5) {LED31 = 1;}
                if (count == 6) {LED32 = 1;}
                if (count == 7) {LED33 = 1;}
                mDelayuS(i*10);
                if (count == 0) {LED14 = 0;}
                if (count == 1) {LED15 = 0;}
                if (count == 2) {LED16 = 0;}
                if (count == 3) {LED17 = 0;}
                if (count == 4) {LED30 = 0;}
                if (count == 5) {LED31 = 0;}
                if (count == 6) {LED32 = 0;}
                if (count == 7) {LED33 = 0;}
                mDelayuS(pulse-i*10);
            }
            if (BUTTON11 == 0) { button11push = 1; }
            for( i = bright-1; i>0; i = i - 1 ){
                if (count == 0) {LED14 = 1;}
                if (count == 1) {LED15 = 1;}
                if (count == 2) {LED16 = 1;}
                if (count == 3) {LED17 = 1;}
                if (count == 4) {LED30 = 1;}
                if (count == 5) {LED31 = 1;}
                if (count == 6) {LED32 = 1;}
                if (count == 7) {LED33 = 1;}
                mDelayuS(i*10);
                if (count == 0) {LED14 = 0;}
                if (count == 1) {LED15 = 0;}
                if (count == 2) {LED16 = 0;}
                if (count == 3) {LED17 = 0;}
                if (count == 4) {LED30 = 0;}
                if (count == 5) {LED31 = 0;}
                if (count == 6) {LED32 = 0;}
                if (count == 7) {LED33 = 0;}
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
                if (count == 0) {LED14 = 1;}
                if (count == 1) {LED15 = 1;}
                if (count == 2) {LED16 = 1;}
                if (count == 3) {LED17 = 1;}
                if (count == 4) {LED30 = 1;}
                if (count == 5) {LED31 = 1;}
                if (count == 6) {LED32 = 1;}
                if (count == 7) {LED33 = 1;}
                mDelayuS(i*10);
                if (count == 0) {LED14 = 0;}
                if (count == 1) {LED15 = 0;}
                if (count == 2) {LED16 = 0;}
                if (count == 3) {LED17 = 0;}
                if (count == 4) {LED30 = 0;}
                if (count == 5) {LED31 = 0;}
                if (count == 6) {LED32 = 0;}
                if (count == 7) {LED33 = 0;}
                mDelayuS(pulse-i*10);
            }
            if (BUTTON11 == 0) { button11push = 1; }
            for( i = bright-1; i>0; i = i - 1 ){
                LED14 = 1;  // ON
                LED15 = 1;  // ON
                LED16 = 1;  // ON
                LED17 = 1;  // ON
                LED30 = 1;  // ON
                LED31 = 1;  // ON
                LED32 = 1;  // ON
                LED33 = 1;  // ON
                mDelayuS(i*10);
                LED14 = 0;  // OFF
                LED15 = 0;  // OFF
                LED16 = 0;  // OFF
                LED17 = 0;  // OFF
                LED30 = 0;  // OFF
                LED31 = 0;  // OFF
                LED32 = 0;  // OFF
                LED33 = 0;  // OFF
                mDelayuS(pulse-i*10);
            }
	    if (BUTTON11 == 0) { button11push = 1; }
        }
      }
      if (ledmode == 7) //fracking cylons
      {
	if (BUTTON11 == 0) { button11push = 1; }
	//go there
        LED14 = 1;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 1;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 1;  // OFF
        LED17 = 0;  // OFF
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 1;  // OFF
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        LED30 = 1;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        LED30 = 0;  // OFF
        LED31 = 1;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 1;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 1;  // OFF
        //and back again
        mDelaymS(250);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 1;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        LED30 = 0;  // OFF
        LED31 = 1;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        LED30 = 1;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 1;  // OFF
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 1;  // OFF
        LED17 = 0;  // OFF
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 0;  // OFF
        LED15 = 1;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(150);
	if (BUTTON11 == 0) { button11push = 1; }
        LED14 = 1;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        mDelaymS(250);
	if (BUTTON11 == 0) { button11push = 1; }
      }
      if (ledmode == 8) //group pulsing mode
      {
	if (BUTTON11 == 0) { button11push = 1; }
	for( i = 1; i < bright; i = i + 1 ){
            LED14 = 1;  // ON
            LED15 = 1;  // ON
            LED16 = 1;  // ON
            LED17 = 1;  // ON
            LED30 = 1;  // ON
            LED31 = 1;  // ON
            LED32 = 1;  // ON
            LED33 = 1;  // ON
            mDelayuS(i*10);
            LED14 = 0;  // OFF
            LED15 = 0;  // OFF
            LED16 = 0;  // OFF
            LED17 = 0;  // OFF
            LED30 = 0;  // OFF
            LED31 = 0;  // OFF
            LED32 = 0;  // OFF
            LED33 = 0;  // OFF
            mDelayuS(pulse-i*10);
        }
	if (BUTTON11 == 0) { button11push = 1; }
        for( i = bright-1; i>0; i = i - 1 ){
            LED14 = 1;  // ON
            LED15 = 1;  // ON
            LED16 = 1;  // ON
            LED17 = 1;  // ON
            LED30 = 1;  // ON
            LED31 = 1;  // ON
            LED32 = 1;  // ON
            LED33 = 1;  // ON
            mDelayuS(i*10);
            LED14 = 0;  // OFF
            LED15 = 0;  // OFF
            LED16 = 0;  // OFF
            LED17 = 0;  // OFF
            LED30 = 0;  // OFF
            LED31 = 0;  // OFF
            LED32 = 0;  // OFF
            LED33 = 0;  // OFF
            mDelayuS(pulse-i*10);
        }
	if (BUTTON11 == 0) { button11push = 1; }
      }
      if (ledmode == 9) //flashing mode
      {
        if (BUTTON11 == 0) { button11push = 1; }
        mDelaymS(40 * ledmode);
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        if (BUTTON11 == 0) { button11push = 1; }
        mDelaymS(40 * ledmode);
        LED30 = 1;  // ON
        LED31 = 1;  // ON
        LED32 = 1;  // ON
        LED33 = 1;  // ON
        LED14 = 1;  // ON
        LED15 = 1;  // ON
        LED16 = 1;  // ON
        LED17 = 1;  // ON
        if (BUTTON11 == 0) { button11push = 1; }
        mDelaymS(40 * ledmode);
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        if (BUTTON11 == 0) { button11push = 1; }
        mDelaymS(40 * ledmode);
        LED30 = 1;  // ON
        LED31 = 1;  // ON
        LED32 = 1;  // ON
        LED33 = 1;  // ON
        LED14 = 1;  // ON
        LED15 = 1;  // ON
        LED16 = 1;  // ON
        LED17 = 1;  // ON

      }
      if (ledmode == 10) //flashing mode
      {
        if (BUTTON11 == 0) { button11push = 1; }
        mDelaymS(40 * ledmode);
        LED14 = 1;  // OFF
        LED15 = 0;  // OFF
        LED16 = 0;  // OFF
        LED17 = 1;  // OFF
        LED30 = 0;  // OFF
        LED31 = 0;  // OFF
        LED32 = 1;  // OFF
        LED33 = 0;  // OFF
        if (BUTTON11 == 0) { button11push = 1; }
        mDelaymS(40 * ledmode);
        LED14 = 0;  // OFF
        LED15 = 1;  // OFF
        LED16 = 0;  // OFF
        LED17 = 0;  // OFF
        LED30 = 1;  // OFF
        LED31 = 0;  // OFF
        LED32 = 0;  // OFF
        LED33 = 1;  // OFF
        if (BUTTON11 == 0) { button11push = 1; }
        mDelaymS(40 * ledmode);
        LED14 = 0;  // OFF
        LED15 = 0;  // OFF
        LED16 = 1;  // OFF
        LED17 = 0;  // OFF
        LED30 = 0;  // OFF
        LED31 = 1;  // OFF
        LED32 = 0;  // OFF
        LED33 = 0;  // OFF

      }
      if (ledmode == 11) //binary flash mode
      {
        // -------------------------------------- 01 - M - 155
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
        // -------------------------------------- 02 - @ - 100
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 03 - L - 154
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
        // -------------------------------------- 04 - E - 145
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
        // -------------------------------------- 05 - E - 145
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
        // -------------------------------------- 06 - T - 164
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
        // -------------------------------------- 07 - N - 156
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 1, LED31 = 1, LED32 = 1, LED33 = 0;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 08 - E - 145
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
        // -------------------------------------- 09 - T - 164
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
        // -------------------------------------- 10 - . - 056
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
        // -------------------------------------- 11 - N - 156
        // Delay to display previous LED state
        mDelaymS(200);
        // If we see button push set button push flag
        if (BUTTON11 == 0) { button11push = 1; }
        // Flash LEDs
        LED14 = 0, LED15 = 1, LED16 = 1, LED17 = 0, LED30 = 1, LED31 = 1, LED32 = 1, LED33 = 0;
        // Delay to display previous LED state
        mDelaymS(400);
        // LEDs OFF
        LED14 = 0, LED15 = 0, LED16 = 0, LED17 = 0, LED30 = 0, LED31 = 0, LED32 = 0, LED33 = 0;
        //
        // -------------------------------------- 12 - E - 145
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
        // -------------------------------------- 13 - T - 164
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
        if (ledmode > 11) { ledmode = 1; }
        // Reset button push flag
        button11push = 0;
      }
    }
}
