#ifndef _DONGLEMANAGER_H
#define _DONGLEMANAGER_H

#include <pthread.h>
#include <sysutils/NetlinkEvent.h>
#include "UsbMdmMgr.h"

class DongleManager {
private:
    static DongleManager *sInstance;

private:
    UsbMdmMgr * mUsbMdmMgr;
    DongleManager(){mUsbMdmMgr = new UsbMdmMgr();};

public:
    ~DongleManager(){delete mUsbMdmMgr;};
    void handleUsbEvent(NetlinkEvent *evt);
    int switch_usbmode(int vid, int pid, const char *devpath);

    static DongleManager *Instance();
};

#endif // _DONGLEMANAGER_H
