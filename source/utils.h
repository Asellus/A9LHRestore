#pragma once

#include "types.h"

#define HID_PAD       (*(vu16 *)0x10146000 ^ 0xFFF)
#define BUTTON_SELECT (1 << 2)

#define COLOR_TITLE 0xFF9900
#define COLOR_WHITE 0xFFFFFF
#define COLOR_RED   0x0000FF
#define COLOR_GREEN 0x00FF00

int pos_y;

u16 waitInput(void);
void shutdown(u32 mode, const char *message);
void reboot(u32 mode, const char *message);
