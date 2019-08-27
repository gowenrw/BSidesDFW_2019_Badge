// Blink Yellow and Green LEDs connected to pins 1.4 and 1.6

#include <ch554.h>
#include <debug.h>

#define Y_LED_PIN 4
#define G_LED_PIN 6
SBIT(YLED, 0x90, Y_LED_PIN);
SBIT(GLED, 0x90, G_LED_PIN);

void main() {
    CfgFsys();

    P1_DIR_PU &= 0x0C;
    // Configure pin 1.4 as GPIO output
    P1_MOD_OC = P1_MOD_OC & ~(1<<Y_LED_PIN);
    P1_DIR_PU = P1_DIR_PU |	(1<<Y_LED_PIN);
    // Configure pin 1.6 as GPIO output
    P1_MOD_OC = P1_MOD_OC & ~(1<<G_LED_PIN);
    P1_DIR_PU = P1_DIR_PU |	(1<<G_LED_PIN);

    YLED = !YLED;

    while (1) {
    	mDelaymS(100);
        YLED = !YLED;
        GLED = !GLED;
    }
}
