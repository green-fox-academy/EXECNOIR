//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef WIRELESSADAPTER_NETWORKDEVICE_H
#define WIRELESSADAPTER_NETWORKDEVICE_H
#include "Device.h"

class NetworkDevice : virtual public Device{
public:
    NetworkDevice(int id, int bandwith);

protected:
    int _bandwith;
private:

};


#endif //WIRELESSADAPTER_NETWORKDEVICE_H
