#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main(int argc, char *argv[]) {
	SetConsoleTitle("pointer"); //�Ѵ��ڱ����Ϊ"pointer"
	int b=100;
	while(1)
	{
		system("cls");
		printf("%X:%d",&b,b); //��ʾ����b���ڴ��ַ�Լ���ֵ
	}
}
