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

// user parameters
#define BUTTON_LONG     50
#define BUTTON_SHORT    5

// 7 segment display data
//  0bHGFEDCBA active low
const uint16_t segment_data[16] = {
    //HGFEDCBAxxxx1234
    0b1100000000000000, // 0
    0b1111100100000000, // 1
    0b1010010000000000, // 2
    0b1011000000000000, // 3
    0b1001100100000000, // 4
    0b1001001000000000, // 5
    0b1000001000000000, // 6
    0b1111100000000000, // 7
    0b1000000000000000, // 8
    0b1001000000000000, // 9
    0b1000100000000000, // A
    0b1000001100000000, // B
    0b1100011000000000, // C
    0b1010000100000000, // D
    0b1000011000000000, // E
    0b1000111000000000, // F
};
// 7 segment display digits
const uint16_t segment_digit[4] = {
    //xxxx1234
    0b00001000,
    0b00000100,
    0b00000010,
    0b00000001
};
// bar graph pattern
const uint8_t bargraph_data[5] = {
    0x0, 0x1, 0x3, 0x7, 0xF
};

// global variables
uint8_t bSW1_Timer=0, bSW2_Timer=0, bSW3_Timer=0;
int8_t bValue=0, bDigit=0, bBar=0;

// Input / Output
BusOut busLeds(PIN_LED1, PIN_LED2, PIN_LED3, PIN_LED4);
DigitalIn pinSW1(PIN_SW1);
DigitalIn pinSW2(PIN_SW2);
DigitalIn pinSW3(PIN_SW3);
DigitalOut pinDOUT(PIN_DOUT);
DigitalOut pinSCLK(PIN_SCLK);
DigitalOut pinLTCH(PIN_LTCH);


// Prototypes
void vShiftOut(uint16_t wData);
void vCheckButtons();


// main() runs in its own thread in the OS
int main() {
    // init
    vShiftOut(segment_digit[bDigit] | segment_data[bValue]);
    busLeds = ~bargraph_data[bBar];

    while(1) {
        vCheckButtons();
        ThisThread::sleep_for(10ms);
    }
}


void vShiftOut(uint16_t wData) {
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


void vCheckButtons() {
    // check switch 1
    if(pinSW1 == 0) {
        if(bSW1_Timer <= BUTTON_LONG) {
            if(bSW1_Timer == BUTTON_SHORT) {
                // event: short press
            }
            if(bSW1_Timer == BUTTON_LONG) {
                // event: long press
                bValue--;
                if(bValue < 0) bValue=0xF;
                // update display
                vShiftOut(segment_digit[bDigit] | segment_data[bValue]);
            }
            bSW1_Timer++;
        } 
    } else {
        if((bSW1_Timer >= BUTTON_SHORT) && (bSW1_Timer <= BUTTON_LONG)) {
            // event: released from short
            bValue++;
            if(bValue > 0xF) bValue=0x0;
            // update display
            vShiftOut(segment_digit[bDigit] | segment_data[bValue]);
        }
        if(bSW1_Timer > BUTTON_LONG) {
            // event: released from long
        }
        bSW1_Timer = 0;
    }

    // check switch 2
    if(pinSW2 == 0) {
        if(bSW2_Timer <= BUTTON_LONG) {
            if(bSW2_Timer == BUTTON_SHORT) {
                // event: short press
            }
            if(bSW2_Timer == BUTTON_LONG) {
                // event: long press
                bDigit--;
                if(bDigit < 0) bDigit=3;
                // update display
                vShiftOut(segment_digit[bDigit] | segment_data[bValue]);
            }
            bSW2_Timer++;
        } 
    } else {
        if((bSW2_Timer >= BUTTON_SHORT) && (bSW2_Timer <= BUTTON_LONG)) {
            // event: released from short
            bDigit++;
            if(bDigit > 3) bDigit=0;
            // update display
            vShiftOut(segment_digit[bDigit] | segment_data[bValue]);
        }
        if(bSW2_Timer > BUTTON_LONG) {
            // event: released from long
        }
        bSW2_Timer = 0;
    }

    // check switch 3
    if(pinSW3 == 0) {
        if(bSW3_Timer <= BUTTON_LONG) {
            if(bSW3_Timer == BUTTON_SHORT) {
                // event: short press
            }
            if(bSW3_Timer == BUTTON_LONG) {
                // event: long press
                bBar--;
                if(bBar < 0) bBar = sizeof(bargraph_data) - 1;
                // update leds
                busLeds = ~bargraph_data[bBar];
            }
            bSW3_Timer++;
        } 
    } else {
        if((bSW3_Timer >= BUTTON_SHORT) && (bSW3_Timer <= BUTTON_LONG)) {
            // event: released from short
            bBar++;
            if(bBar >= sizeof(bargraph_data)) bBar=0;
            // update leds
            busLeds = ~bargraph_data[bBar];
        }
        if(bSW3_Timer > BUTTON_LONG) {
            // event: released from long
        }
        bSW3_Timer = 0;
    }
}