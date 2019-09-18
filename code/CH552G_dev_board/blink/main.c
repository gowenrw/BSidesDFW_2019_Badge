// Blink LEDs alternating between groups
// LEDs connected to pins 1.4, 1.5, 1.6, 1.7, 3.0, 3.1, 3.2, 3.3
// Tactile switch connected to pin 3.4

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

// P1 = 0x90 P3 = 0xB0
SBIT(LED30, 0xB0, LED30_PIN);
SBIT(LED31, 0xB0, LED31_PIN);
SBIT(LED32, 0xB0, LED32_PIN);
SBIT(LED33, 0xB0, LED33_PIN);
SBIT(LED14, 0x90, LED14_PIN);
SBIT(LED15, 0x90, LED15_PIN);
SBIT(LED16, 0x90, LED16_PIN);
SBIT(LED17, 0x90, LED17_PIN);

void main() {
    CfgFsys();

    P3_DIR_PU &= 0x0C;
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

    P1_DIR_PU &= 0x0C;
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

    // Setting half the LEDs to opposite state to alternate which ones blink
    LED30 = !LED30;
    LED31 = !LED31;
    LED32 = !LED32;
    LED33 = !LED33;

    while (1) {
      // Delay controls blink speed
    	mDelaymS(300);
      // Setting the LEDs to opposite state to turn them on or off
      LED30 = !LED30;
      LED31 = !LED31;
      LED32 = !LED32;
      LED33 = !LED33;
      LED14 = !LED14;
      LED15 = !LED15;
      LED16 = !LED16;
      LED17 = !LED17;
    }
}
