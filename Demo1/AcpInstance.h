#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "Demo.h"
class AcpInstance
{
public :
    AcpInstance();
    AcpInstance(const std::string& dllpath);
    HANDLE OpenService();
    int getNamePathFromPath();
    bool QueryAcpiNameS(HANDLE hDriver);

	template<typename FuncType>
	FuncType getFunction(const char* funcName);
	~AcpInstance();


private:
	HMODULE hModule;
    HANDLE hDriver;
};
template<typename FuncType>
FuncType AcpInstance::getFunction(const char* funcName) {
    if (!hModule) {
        return nullptr;
    }

    FuncType func = (FuncType)GetProcAddress(hModule, funcName);
    if (!func) {
        std::cerr << "Failed to get function address: " << funcName << std::endl;
    }
    return func;
}
