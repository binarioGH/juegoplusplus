#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
void gotoxy(int x, int y);
void clean(int nx, int ny);
void ocultar(void);
int main(){
	ocultar();
	bool gameover = false, clear=true ;
	int x = 10, y = 10;
	while(!gameover){
		gotoxy(x,y);printf("*");
		if(kbhit()){
			if(clear){
				clean(x, y);
			}
			char tecla = getch();
			if(tecla == UP || tecla == 'w')y-= 1;
			if(tecla ==DOWN|| tecla == 's' )y+=1;
			if(tecla ==LEFT|| tecla == 'a')x -=1;
			if(tecla==RIGHT|| tecla == 'd' )x+=1;
			if(tecla == 'x'){
				if(clear){
					clear = false;
				}
				else{
					clear = true;
				}
			}


		}

	}
	Sleep(30);
	return 0;
}
void gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
	return;
}
void clean(int nx, int ny){
	gotoxy(nx, ny);printf(" ");
	return;
}
void ocultar(void){
	HANDLE hCon;
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 0;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &cci);
	return;
}