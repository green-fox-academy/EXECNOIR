//
// Created by EXEC_NOIR on 11/21/2018.
//

#include "WirelessAdapter.h"

WirelessAdapter::WirelessAdapter(int id, int usbType, int bandwith) : USBDevice(id, usbType),
                                                                               NetworkDevice(id, bandwith), Device(id) {}

void WirelessAdapter::info() {
    std::cout << "ID: " << _id << std::endl
                << "USBType: " << _usbType << std::endl
                <<  "Bandwith: " << _bandwith << std::endl;
}
