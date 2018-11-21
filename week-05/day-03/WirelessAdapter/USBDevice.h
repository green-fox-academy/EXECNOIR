//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef WIRELESSADAPTER_USBDEVICE_H
#define WIRELESSADAPTER_USBDEVICE_H
#include "Device.h"

class USBDevice : virtual public Device{
public:
    USBDevice(int id, int usbType);

public:
protected:
    int _usbType;
private:
};


#endif //WIRELESSADAPTER_USBDEVICE_H
