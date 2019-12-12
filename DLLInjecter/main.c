#include <Windows.h>
#include<stdlib.h>
void inject(int PID, char* path)
{
    HANDLE processhandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
    HMODULE hdll = LoadLibraryA("KERNEL32.DLL");
    LPTHREAD_START_ROUTINE address = (LPTHREAD_START_ROUTINE)GetProcAddress(hdll, "LoadLibraryA");
    LPVOID areturn = VirtualAllocEx(processhandle, NULL, strlen(path) + 1, MEM_COMMIT, PAGE_READWRITE);
    WriteProcessMemory(processhandle, areturn, path, strlen(path) + 1, NULL);
    HANDLE hThread = CreateRemoteThread(processhandle, NULL, 0, address, areturn, 0, NULL);
    WaitForSingleObject(hThread, 2000);

    CloseHandle(processhandle);
    CloseHandle(hThread);
}

int main(int argc, char *argv[]) {
	DWORD pid;
	HWND pointer=FindWindow("MainWindow","植物大战僵尸中文版");
	GetWindowThreadProcessId(pointer,&pid);
	TCHAR buffer[MAX_PATH];
	GetCurrentDirectory(MAX_PATH,buffer);
	strcat(buffer,"\\crack.dll");
	inject(pid,buffer); 
}
