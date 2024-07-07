// Demo1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "AcpInstance.h"
#include "demo.h"
#include <string>
#include <windows.h>
#include <tchar.h>


#include <locale>
#include <codecvt>
#include <string>

int main()
{
    std::cout << MAX_PATH % 4 << std::endl;;

#ifdef UNICODE
    std::cout << "unicode!\n";
#else
    std::cout << "ANSI (Multibyte) mode" << std::endl;
#endif 
    AcpInstance AcpInstance;
    HANDLE success = AcpInstance.OpenService();
    bool bor = AcpInstance.QueryAcpiNameS(success);
    std::cout << "QueryAcpiNameS:" << bor << "\n" << std::endl;

    std::wstring test = L"acpi.bin";
    LoadAcpiObjects((wchar_t*)test.c_str());

    SaveAcpiObjects((wchar_t*)test.c_str());
    std::wcout << "this is a test" << (wchar_t*)test.c_str() << "\n";
    int length = AcpInstance.getNamePathFromPath();
    //"\\___"
    std::cout << "Open ACPI Service: " << (success ? "Success" : "Failure") << std::endl;
    PVOID   pArgs = nullptr;
    pArgs = PutIntArg(pArgs, 1);
   pArgs = PutIntArg(pArgs, 2);
     if (pArgs == nullptr) {
         std::cout << "pArgs is nullptr" << std::endl;
     }
     std::wstring methodPath = L"\\___RCMD";
     std::wstring strvalue = L"";
     UINT64 value = EvalAcpiNSArgAndParse((wchar_t*)methodPath.c_str(), (ACPI_EVAL_INPUT_BUFFER_COMPLEX*)pArgs, (wchar_t*)strvalue.c_str());
     std::cout <<"VALUE =" << value << std::endl;
     
    system("pause");
}