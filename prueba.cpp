#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
void gotoxy(int x, int y);
void hidecursor(void);
class Character{
private:
	int x, y;
	int body[6] = {30,47,124,92,47,92};
	void clean(void);
public:
	Character(int _x, int _y);
	bool gameover = false;
	void draw(void);
	void move(void);
	void confirmPos(void);
};
Character::Character(int _x, int _y){
	x = _x;
	y = _y;
}
void Character::draw(void){
	gotoxy(x,y);printf(" %c",body[0]);
	gotoxy(x,y+1);printf("%c%c%c",body[1],body[2],body[3]);
	gotoxy(x,y+2);printf("%c %c",body[4],body[5]);
	return;
}
void Character::clean(void){
	gotoxy(x,y);printf("  ");
	gotoxy(x,y+1);printf("   ");
	gotoxy(x,y+2);printf("   ");
	return;
}
void Character::move(void){
	if(kbhit()){
		char key = getch();
		Character::clean();
		switch(key){
			case UP:y-=1;break;
			case DOWN:y+=1;break;
			case LEFT:x-=1;break;
			case RIGHT:x+=1;break;
			case 'q':gameover = true;break;
		}
	}
}
void Character::confirmPos(void){
	if(x+1 >= 79){
		x -=1;
	}
	if(x-1 <= 0){
		x += 1;
	}
	if(y+2 >= 25){
		y -= 1;
	}
	if(y <= 0){
		y += 1;
	}
}

int main(){
	hidecursor();
	Character mc = Character(10,10);
	while(!mc.gameover){
		mc.draw();
		mc.move();
		mc.confirmPos();
		Sleep(30);
	}
	return 0;
}
void gotoxy(int x, int y){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
	return;
}
void hidecursor(void){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 0;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &cci);
	return;
}