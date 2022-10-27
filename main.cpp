#include "mbed.h"
#include <cstdint>

// Nucleo On-Board
#define PIN_NUC_LED PA_5
#define PIN_NUC_SW  PC_13
// Shield
#define PIN_SW1     PA_1
#define PIN_SW2     PA_4
#define PIN_SW3     PB_0
#define PIN_DOUT    PA_9
#define PIN_SCLK    PA_8
#define PIN_LTCH    PB_5
#define PIN_LED1    PB_6
#define PIN_LED2    PA_7
#define PIN_LED3    PA_6
#define PIN_LED4    PA_5

// 7 segment display data
//  0bHGFEDCBA active low
const uint8_t segment_data[16] = {
    0b11000000, // 0
    0b11111001, // 1
    0b11100100, // 2
    0b10110000, // 3
    0b10010001, // 4
    0b10010010, // 5
    0b10000010, // 6
    0b11111000, // 7
    0b10000000, // 8
    0b10010000, // 9
    0b10001000, // A
    0b10000011, // B
    0b11000100, // C
    0b10100001, // D
    0b10000110, // E
    0b10001110, // F
};
// 7 segment display digits
const uint16_t segment_digit[4] = {
    0x100,
    0x200,
    0x400,
    0x800
};


// Input / Output
DigitalOut pinDOUT(PIN_DOUT);
DigitalOut pinSCLK(PIN_SCLK);
DigitalOut pinLTCH(PIN_LTCH);


// Prototypes
void shift_out(uint16_t wData);


// main() runs in its own thread in the OS
int main() {
    shift_out(segment_digit[0] | segment_data[0]);
}


void shift_out(uint16_t wData) {
    for(uint8_t i=0; i<16; i++) {
        // MSB first
        pinDOUT = (wData & (0x8000 >> i));
        // send clock pulse
        pinSCLK = 1;
        pinSCLK = 0;
    }
    // latch outputs
    pinLTCH = 1;
    pinLTCH = 0;
}