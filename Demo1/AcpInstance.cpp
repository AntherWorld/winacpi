#include "AcpInstance.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
std::wstring ConvertToWideString(const std::string& str) {
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}
AcpInstance::AcpInstance()
{
   // AcpInstance AcpInstance("AcpiLib.dll");
}
AcpInstance::AcpInstance(const std::string& dllpath)
{
  /* std::wstring wdllpath = ConvertToWideString(dllpath);
    std::wcout << L"Attempting to load DLL: " << wdllpath << std::endl;
    hModule = LoadLibrary(wdllpath.c_str());
    if (!hModule) {
        DWORD error = GetLastError();
        std::wcout << L"Failed to load DLL: " << wdllpath << L" with error code: " << error << std::endl;
    }
    else {
        std::wcout << L"Successfully loaded DLL: " << wdllpath << std::endl;
    }*/
}

HANDLE AcpInstance::OpenService()
{
    return OpenAcpiService();
}

int AcpInstance::getNamePathFromPath()
{
    std::wstring puparent = _T("\\____SB_");
    size_t          cbLength = 0;
    HRESULT hr = StringCbLength(puparent.c_str(), sizeof(puparent), &cbLength);
    if (SUCCEEDED(hr)) {
        // �ɹ���ȡ�ַ������ȣ���������
        std::cout << "cbLength:" << cbLength << std::endl;
    }
    else {
        // ���������������ݷ��صĴ����������Ӧ����
    }
    int var= GetNamePathFromPath((TCHAR *)puparent.c_str(), NULL);

        size_t size = (var * 8) + 8;//8=1���ַ�2�ֽڣ�4���ַ�8�ֽ�
        std::wstring puChild(size, L'\0');
          std::cout << "GetNamePathFromPath:" << var << std::endl;
        std::cout << (var * 8) + 8 << std::endl;
        var = GetNamePathFromPath((TCHAR*)puparent.c_str(), (TCHAR*)puChild.c_str());
        std::wcout <<puChild << std::endl;
        //size_t vsize = sizeof(puChild);
       // std::cout << "size of" << var << std::endl;

        int temp = 0;
        while (temp <var ) {
            std::wstring targetname = puChild.substr(temp*4,4);//substr ����s�д�temp*4��ʼ��4���ַ��Ŀ���
            std::wcout << targetname << std::endl;
            temp++;
        }

     
    
#ifdef _UNICODE
    //wprintf_s(L"puChild %ls\\n", puChild);
#else
    printf("%s\\n", puChild);
#endif
    return var;
}

bool AcpInstance::QueryAcpiNameS(HANDLE hDriver)
{
    return QueryAcpiNS(hDriver, nullptr, 0xC1);
}

AcpInstance::~AcpInstance()
{
  /*  if (hModule) {
        FreeLibrary(hModule);
        std::wcout << L"�ͷ�DLL��" << std::endl;
    }
    else {
        std::wcout << L"û����Ҫ�ͷŵ�DLL��" << std::endl;
    }*/
}
