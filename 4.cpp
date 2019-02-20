#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

void gotoxy(int x, int y);
void hidecursor(void);
class Guy{
private:
	int x,y;
public:
	Guy(int _x, int _y);
	void draw(void);
	void clean();
	void move();
	bool gameover = false;

};
Guy::Guy(int _x, int _y){
	x = _x;
	y = _y;
}

void Guy::draw(void){
	gotoxy(x,y);printf(" %c", 30);
	gotoxy(x,y+1);printf("%c%c%c",47,124,92);
	gotoxy(x,y+2);printf("%c %c",47,92);
	return;
}
void Guy::clean(){
	gotoxy(x,y);printf("  ");
	gotoxy(x,y+1);printf("   ");
	gotoxy(x,y+2);printf("   ");
	return;
}
void Guy::move(){
	if(kbhit){
		char key = getch();
		clean();
		if(key == 'w' || key==UP){
			y -= 1;
		}
		if(key == 's' || key==DOWN){
			y += 1;
		}
		if(key == 'a' || key==LEFT){
			x -= 1;
		}
		if(key == 'd' || key==RIGHT){
			x += 1;
		}
		if(key == 'q'){
			gameover = true;
		}
		draw();
	}
	return ;
}

int main(){
	Guy mc = Guy(10, 10);
	while(!mc.gameover){
		mc.move();
		Sleep(30);
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
	return;
}
void hidecursor(void){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 0;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &cci);
	return;
}