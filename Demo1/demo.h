#pragma once
#include <windows.h>
// AddFunc 类型定义放在 DllManager 类中管理
//typedef HANDLE(*OpenAcpiService)();
#include "..//HwAcc/ioctl.h"
extern "C" {
    __declspec(dllimport) void* OpenAcpiService();
    __declspec(dllimport) int GetNamePathFromPath(TCHAR* puParent, TCHAR* puChild);
    __declspec(dllimport) BOOLEAN QueryAcpiNS(HANDLE hDriver, ACPI_NS_DATA* pAcpiNsData, UINT MethodStartIndex);
    __declspec(dllimport) void* LoadAcpiObjects(TCHAR* chFile);
    __declspec(dllimport) void* SaveAcpiObjects(TCHAR* chFile);
    __declspec(dllimport) PVOID PutIntArg(PVOID   pArgs, UINT64  value);
    __declspec(dllimport) UINT64 EvalAcpiNSArgAndParse(TCHAR* pPath, ACPI_EVAL_INPUT_BUFFER_COMPLEX* pComplexInput, TCHAR* pAsl);

}

