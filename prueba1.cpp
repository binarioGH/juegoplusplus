#include <stdio.h>
#include <windows.h>

int main(){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwpost;
	int i;
	for(i=0;i<10;i++){
		dwpost.X = 5+i;
		dwpost.Y = 4+i;
		SetConsoleCursorPosition(hcon, dwpost);
		printf("Hola mundo");
	}
	return 0;
}