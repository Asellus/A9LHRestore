#include "restore.h"
#include "memory.h"
#include "fs.h"
#include "crypto.h"
#include "draw.h"
#include "utils.h"
#include "fatfs/ff.h"
#include "fatfs/sdmmc/sdmmc.h"

int pos_y;

void restore(void){

    drawString(TITLE, 10, 10, COLOR_TITLE);
    pos_y = drawString("Press SELECT to restore arm9loaderhax.bin", 10, 40, COLOR_WHITE);
    pos_y = drawString("Press any other button to shutdown", 10, pos_y, COLOR_WHITE);

    if(waitInput() != BUTTON_SELECT) shutdown(0, NULL);

    const char *path;
    FILINFO fno;

    path = "arm9loaderhax.bin.bak";
    if(f_stat(path, &fno) == FR_NO_FILE) {
         shutdown(1, "Error: arm9loaderhax.bin.bak doesn't exist");
    }

    f_rename("arm9loaderhax.bin", "arm9loaderhax.bin.tmp");
    f_rename("arm9loaderhax.bin.bak", "arm9loaderhax.bin");
    f_rename("arm9loaderhax.bin.tmp", "arm9loaderhax.bin.bak");

    reboot(2, "Restore: success!");
}
