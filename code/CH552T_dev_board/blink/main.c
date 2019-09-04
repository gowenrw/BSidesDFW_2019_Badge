// Blink Yellow and Green LEDs connected to pins 1.4 and 1.6

#include <ch554.h>
#include <debug.h>

#define Y_LED_PIN 3
#define G_LED_PIN 5

// P1 = 0x90 P3 = 0xB0
SBIT(YLED, 0xB0, Y_LED_PIN);
SBIT(GLED, 0xB0, G_LED_PIN);

void main() {
    CfgFsys();

    P1_DIR_PU &= 0x0C;
    // Configure pin 3.3 as GPIO output
    P3_MOD_OC = P3_MOD_OC & ~(1<<Y_LED_PIN);
    P3_DIR_PU = P3_DIR_PU |	(1<<Y_LED_PIN);
    // Configure pin 3.5 as GPIO output
    P3_MOD_OC = P3_MOD_OC & ~(1<<G_LED_PIN);
    P3_DIR_PU = P3_DIR_PU |	(1<<G_LED_PIN);

    YLED = !YLED;

    while (1) {
    	mDelaymS(100);
        YLED = !YLED;
        GLED = !GLED;
    }
}
