#include <stdio.h>
#include <windows.h>
#include <conio.h>
void gotoxy(int x, int y);
void clean(int x, int y);
int main(){
	bool gameover = false;
	int x=10, y=10;
	while(!gameover){
		gotoxy(x, y);printf("*");
		if(kbhit()){
			clean(x,y);
			char tecla = getch();
			if(tecla =='w')y-= 1;
			if(tecla =='s')y+=1;
			if(tecla == 'a')x -=1;
			if(tecla =='d')x+=1;
		}

	}

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