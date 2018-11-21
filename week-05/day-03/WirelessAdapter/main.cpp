#include <iostream>
#include "WirelessAdapter.h"

enum class USBType{
    USB_TYPE_2,
    USB_TYPE_3
};

int main( int argc, char* args[] )
{
    WirelessAdapter adapter(10, 1, 100);
    adapter.info();
}