#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main(int argc, char *argv[]) {
	SetConsoleTitle("pointer"); //把窗口标题改为"pointer"
	int b=100;
	while(1)
	{
		system("cls");
		printf("%X:%d",&b,b); //显示变量b的内存地址以及数值
	}
}
