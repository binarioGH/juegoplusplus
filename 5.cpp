#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
void gotoxy(int x,int y);
void hidecursor(void);
void drawborders(void);
class Character{
private: 
	int x, y;
	void clean(void);
	void confirmPos(void);
	int body[6] = {30,47,124,92,47,92};
public:
	Character(int _x, int _y);
	bool alive = true;
	void draw(void);
	void move(void);
};
Character::Character(int _x, int _y){
	x = _x;
	y = _y;
}
void Character::clean(void){
	gotoxy(x,y);printf("  ");
	gotoxy(x,y+1);printf("   ");
	gotoxy(x,y+2);printf("   ");
	return;
}
void Character::confirmPos(void){
	if(x+2 >= 77){
		x-= 1;
	}
	if(x <= 2){
		x += 1;
	}
	if(y+2 >= 22){
		y -= 1;
	}
	if(y <= 2){
		y += 1;
	}
	return;
}
void Character::draw(void){
	gotoxy(x,y);printf(" %c",body[0]);
	gotoxy(x,y+1);printf("%c%c%c",body[1],body[2],body[3]);
	gotoxy(x,y+2);printf("%c %c",body[4],body[5]);
	return;
}
void Character::move(void){
	if(kbhit()){
		char key = getch();
		Character::clean();
		switch(key){
			 case UP: y-=1;break;
			 case DOWN: y+=1;break;
			 case LEFT: x-=1;break;
			 case RIGHT: x+=1;break;
			 case 'q': alive=false;break;
		}
	}
	Character::confirmPos();
	return;
}

int main(){
	system("cls");
	drawborders();
	hidecursor();
	Character mc = Character(10, 10);
	while(mc.alive){
		mc.draw();
		mc.move();
	}
	return 0;
}

void gotoxy(int x, int y){
	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
	return;
}
void hidecursor(void){
	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 0;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &cci);
	return;
}
void drawborders(void){
	int x = 2,y = 2;
	for(x;x<=77;x++){
		gotoxy(x,2);printf("%c",205);
		gotoxy(x,22);printf("%c",205);
	}
	for(y;y<22;y++){
		gotoxy(2,y);printf("%c",168);
		gotoxy(77,y);printf("%c",168);
	}
	gotoxy(2,2);printf("%c", 201);
	gotoxy(77,2);printf("%c",187);
	gotoxy(2,22);printf("%c",200);
	gotoxy(77,22);printf("%c",188);
	return;
}
