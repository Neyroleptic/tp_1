#include "integer.h"
#include <Windows.h>

int main()
{
	system("chcp 1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	LoadData();
	return 0;
}