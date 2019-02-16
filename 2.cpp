#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

void gotoxy(int x, int y);
void clean(int x, int y);
void ocultar(void);
int main(){
	bool gameover = false;
	int x=10, y=10;
	ocultar();
	while(!gameover){
		gotoxy(x, y);printf("*");
		if(kbhit()){
			clean(x,y);		
			char tecla = getch();
			if(tecla == UP )y-= 1;
			if(tecla ==DOWN )y+=1;
			if(tecla == LEFT)x -=1;
			if(tecla ==RIGHT )x+=1;
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

}
void clean(int lastX,int lastY){
	gotoxy(lastX, lastY);printf(" ");
}
void ocultar(void){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 100; 
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon,&cci);

}