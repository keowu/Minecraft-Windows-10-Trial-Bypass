#include "ketholibminecraftimplementation.h"

void KethoLibMinecraftImplementation::minecraftBypassDo()
{
    HANDLE hProcess = this->kethoinstance->abrirProcessoPeloNome(L"Minecraft.Windows.exe");
    uintptr_t moduleBase = this->kethoinstance->getModuleBaseAddress(this->kethoinstance->getProcessInfo(L"Minecraft.Windows.exe"),
                                                                     L"Minecraft.Windows.exe");
    this->kethoinstance->readMemoryOpcodes(hProcess, moduleBase, this->x64PatchAddress, &this->bbyte);
    qDebug() << "Assembly Original:";
    qDebug() << "Byte:: ";
    for(int i = 0; i < static_cast<int>(this->bbyte.size()); ++i){
        qDebug() << unsigned(bbyte.at(i));
    }
    this->kethoinstance->writeMemoryOpcodes(hProcess, moduleBase, this->x64PatchAddress, this->x64AssemblyOpcodes);
    this->bbyte.clear();
    qDebug() << "Patched patched:";
    this->kethoinstance->readMemoryOpcodes(hProcess, moduleBase, this->x64PatchAddress, &this->bbyte);
    qDebug() << "Byte:: ";
    for(int i = 0; i < static_cast<int>(this->bbyte.size()); ++i){
        qDebug() << unsigned(bbyte.at(i));
    }
    CloseHandle(hProcess);
}



bool KethoLibMinecraftImplementation::checkIfMinecraftProcessIsRunning(){
    DWORD minePID = this->kethoinstance->getProcessInfo(L"Minecraft.Windows.exe");
    return (minePID != 0) ? true : false;
}
