#include "net_ir.h"
#include <stdio.h>
#include <string.h>

#define IRU_SHARED_MEM_SIZE 0x1000
static u32* irSharedMem = NULL;

NetMode currentMode = NET_MODE_NONE;

void netInit(void) {
    if (!irSharedMem) {
        irSharedMem = (u32*)memalign(0x1000, IRU_SHARED_MEM_SIZE);
    }
    Result r = iruInit(irSharedMem, IRU_SHARED_MEM_SIZE);
    if (R_FAILED(r)) {
        printf("IRU init failed: 0x%08lX\n", r);
    }
}

void netExit(void) {
    iruExit();
    if (irSharedMem) {
        free(irSharedMem);
        irSharedMem = NULL;
    }
}

int netSendPacket(u8* data, u32 size) {
    if (currentMode == NET_MODE_NONE) return -1;

    // IRU expects u8*, not const
    Result r = iruSendData(data, size, true);  
    if (R_FAILED(r)) {
        return -1;
    }
    return size;
}

int netRecvPacket(u8* data, u32 size) {
    if (currentMode == NET_MODE_NONE) return -1;

    u32 transferred = 0;
    Result r = iruRecvData(data, size, 0 /* flag */, &transferred, false /* non-block */);
    if (R_FAILED(r) || transferred == 0) {
        return 0; // no data yet
    }
    return (int)transferred;
}

bool selectNetMode(){
    u32 kDown = hidKeysDown();
    u32 kHeld = hidKeysHeld();

    if((kHeld && KEY_X) && (kDown && KEY_L)){
        currentMode = NET_MODE_IR_HOST;
        return false;
    } else if((kHeld && KEY_X) && (kDown && KEY_R)){
        currentMode = NET_MODE_IR_CLIENT;
        return true;
    } else {
        currentMode = NET_MODE_NONE;
        return false;
    }
}