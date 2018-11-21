//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef WIRELESSADAPTER_WIRELESSADAPTER_H
#define WIRELESSADAPTER_WIRELESSADAPTER_H

#include "NetworkDevice.h"
#include "USBDevice.h"
#include <iostream>
class WirelessAdapter : public USBDevice, public NetworkDevice{
public:
    WirelessAdapter(int id, int usbType, int bandwith);
    void info();
};


#endif //WIRELESSADAPTER_WIRELESSADAPTER_H
