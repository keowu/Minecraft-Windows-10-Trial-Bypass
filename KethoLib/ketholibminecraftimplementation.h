#ifndef KETHOLIBMINECRAFTIMPLEMENTATION_H
#define KETHOLIBMINECRAFTIMPLEMENTATION_H
#include "KethoLib.h"
#include "QDebug"

class KethoLibMinecraftImplementation
{

private:
    KethoLib *kethoinstance = new KethoLib();
    std::vector<unsigned int> x64PatchAddress = { 0x8E953E, 0x8E953F, 0x8E9540,
                                                  0x8E9541, 0x937565, 0xBBD333,
                                                  0xBBD334, 0xBBD335, 0x1929EF6 };

    std::vector<unsigned int>x64AssemblyOpcodes = {
                                                     0xE9, 0x07, 0x01,
                                                     0x00, 0xEB, 0xE9,
                                                     0x8C, 0x00, 0xEB
                                                   };
    int i = 0;
    std::vector<uint8_t>bbyte;

public:
    void minecraftBypassDo();
    bool checkIfMinecraftProcessIsRunning();
};

#endif // KETHOLIBMINECRAFTIMPLEMENTATION_H
