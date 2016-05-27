#include "restore.h"
#include "fs.h"
#include "screeninit.h"
#include "types.h"

void main(void){
    mountSD();
    initScreens();
    restore();
}
