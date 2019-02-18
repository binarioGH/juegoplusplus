#include <stdio.h>
#include <windows.h>
int main(){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = 0;
	dwPos.Y = 0;
	SetConsoleCursorPosition(hCon, dwPos);
	printf("*");
	return 0;
}