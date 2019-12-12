#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
int main(int argc, char *argv[]) {
	DWORD address=0x6A9EC0;
	DWORD address_real;
	DWORD pid;
	int b=999;
	HWND pointer=FindWindow("MainWindow","植物大战僵尸中文版");
	printf("%X",pointer);
	GetWindowThreadProcessId(pointer,&pid);
	HANDLE pointer_handle=OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
	ReadProcessMemory(pointer_handle,(LPVOID)0x6A9EC0,&address_real,4,NULL);
	ReadProcessMemory(pointer_handle,(LPVOID)(address_real+0x768),&address_real,4,NULL);
	if(WriteProcessMemory(pointer_handle,(LPVOID)(address_real+0x5560),&b,4,NULL))
	{
		printf("Success!");
	}
	else{
		printf("Fuck!"); 
	}
	
}
