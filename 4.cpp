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
	void clean(int _x, int _y);
	void move(int _x, int _y);

};
Guy::Guy(int _x, int _y){
	Guy::move(_x, _y);
}

void Guy::draw(void){
	gotoxy(x,y);printf(" %c", 30);
	gotoxy(x,y+1);printf("%c%c%c",47,124,92);
	gotoxy(x,y+2);printf("%c %c",47,92);
	return;
}
void Guy::clean(int _x,int _y){
	gotoxy(_x,_y);printf("  ");
	gotoxy(_x,_y+1);printf("   ");
	gotoxy(_x,_y+2);printf("   ");
	return;
}
void Guy::move(int _x, int _y){
	x = _x;
	y = _y;
	return ;
}

int main(){
	int x = 10, y = 10;
	bool gameover = false;
	Guy mc = Guy(x, y);
	while(!gameover){
		mc.draw();
		if(kbhit){
			char key = getch();
			//mc.clean(x, y);
			if(key == 'w' || key==UP){
				y -= 1;
				mc.move(x,y);
			}
			if(key == 's' || key == DOWN){
				y += 1;
				mc.move(x,y);
			}
			if(key == 'a' || key == LEFT){
				x -= 1;
				mc.move(x,y);
			}
			if(key == 'd' || key == RIGHT){
				x += 1;
				mc.move(x,y);
			}
			if(key == 'q'){
				gameover = true;

			}

		}
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