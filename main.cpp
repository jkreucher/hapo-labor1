#include "mbed.h"

// Nucleo On-Board
#define PIN_NUC_LED PA_5
#define PIN_NUC_SW  PC_13
// Shield
#define PIN_SW1     PB_5
#define PIN_SW2     PB_5
#define PIN_SW3     PB_5
#define PIN_DOUT    PB_5
#define PIN_SCLK    PB_5
#define PIN_LTCH    PB_5
#define PIN_LED1    PA_5
#define PIN_LED2    PB_5
#define PIN_LED3    PB_5
#define PIN_LED4    PB_5

DigitalOut pLed(PIN_NUC_LED);

// main() runs in its own thread in the OS
int main() {
    while (true) {
        pLed = !pLed;
        ThisThread::sleep_for(500ms);
    }
}

