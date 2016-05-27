#include "utils.h"
#include "draw.h"
#include "i2c.h"

u16 waitInput(void){
    u32 pressedKey = 0;
    u16 key;

    //Wait for no keys to be pressed
    while(HID_PAD);

    do {
        //Wait for a key to be pressed
        while(!HID_PAD);
        key = HID_PAD;

        //Make sure it's pressed
        for(u32 i = 0x13000; i; i--){
            if(key != HID_PAD) break;
            if(i == 1) pressedKey = 1;
        }
    } while(!pressedKey);

    return key;
}

void shutdown(u32 mode, const char *message){
    if(mode){
        pos_y = drawString(message, 10, pos_y + SPACING_VERT, mode == 1 ? COLOR_RED : COLOR_GREEN);
        drawString("Press any button to shutdown", 10, pos_y, COLOR_WHITE);
        waitInput();
    }
    i2cWriteRegister(I2C_DEV_MCU, 0x20, 1);
    while(1);
}

void reboot(u32 mode, const char *message){
    if(mode){
        pos_y = drawString(message, 10, pos_y + SPACING_VERT, mode == 1 ? COLOR_RED : COLOR_GREEN);
        drawString("Press any button to reboot", 10, pos_y, COLOR_WHITE);
        waitInput();
    }
    i2cWriteRegister(I2C_DEV_MCU, 0x20, 1 << 2);
    while(1);
}