#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
void hidecursor(void);
void gotoxy(int x, int y, char toprint);
void clean(int nx, int ny);
char getpaintingchar(void);
int main(){
	hidecursor();
	int x = 10, y = 10;
	bool keeppainting = true, pls_clean = true;
	char my_char = '*';
	while(keeppainting){
		gotoxy(x, y, my_char);
		if(kbhit()){
			char key = getch();
			if(pls_clean){
				clean(x, y);
			}
			switch(key){
				case UP: y -= 1;break;
				case 'w': y -= 1;break;
				case DOWN: y += 1;break;
				case 's': y += 1;break;
				case LEFT: x+=1;break;
				case 'd': x+= 1;break;
				case RIGHT:x-=1;break;
				case 'a': x-=1;break;
				case 'x':pls_clean=true;break;
				case 'z':pls_clean=false;break;
				case 'c':my_char = getpaintingchar();break;
				case 'e':keeppainting=false;break;
			}
			Sleep(30);
		}

	}
	return 0;
}

void hidecursor(void){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 0;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &cci);
}

void gotoxy(int x, int y, char toprint){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x; 
	dwPos.Y = y; 
	SetConsoleCursorPosition(hCon,dwPos);
	printf("%c",toprint);
	return;
}

void clean(int nx, int ny){
	gotoxy(nx, ny, ' ');
	return;
}
char getpaintingchar(void){
	gotoxy(0,0,' ');
	char new_char;
	printf("Ingresa un char: ");
	scanf("%c", &new_char);
	return new_char;
}