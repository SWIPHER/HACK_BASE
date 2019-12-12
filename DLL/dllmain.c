#include <windows.h>
void hello()
{
	DWORD address=*(DWORD*)0x6A9EC0;
	DWORD address_1=*(DWORD*)(address+0x768);
	DWORD address_2=address_1 + 0x5560;
	*(DWORD*)address_2=999;
	
}
BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			MessageBoxA(NULL,"程序注入成功","注入成功",MB_OK);
			while(1)
			{
				hello();
			}
			
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}
