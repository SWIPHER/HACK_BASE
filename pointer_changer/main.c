#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
int main(int argc, char *argv[]) {
    DWORD address=0x61FE8C;
    DWORD pid;
    int b=107;
    HWND pointer=FindWindow("ConsoleWindowClass","pointer");
    GetWindowThreadProcessId(pointer,&pid);
    HANDLE pointer_handle=OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
    if(WriteProcessMemory(pointer_handle,(LPCVOID)address,&b,4,NULL))
    {
        printf("Success!");
    }
    else{
        printf("Fuck!"); 
    }
}
