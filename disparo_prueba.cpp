#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
void gotoxy(int x, int y);
void hidecursor(void);
void drawborders(void);
class Ship{
private:
	int x, y;
	int vidas = 3, corazones = 3;
	void clean(void);
	void confirmPos(void);
	void shoot(void);
	void display_health(void);
	void death_animation(void);
public:
	Ship(int _x, int _y);
	bool gameover = false;
	void draw(void);
	void move(void);
	void death(void);
};
Ship::Ship(int _x, int _y){
	x = _x;
	y = _y;
	
	
}
void Ship::clean(void){
	int i;
	for(i=0;i<=2;i++){
		gotoxy(x,y+i);printf("        ");
	}
	return;
}
void Ship::confirmPos(void){
	if(x-1<=2){
		x+=1;
	}
	if(x+2>= 75){
		x-=1;
	}
	if(y+2>= 22){
		y-=1;
	}
	if(y<=2){
		y+=1;
	}
	return;
}
void Ship::shoot(void){

	return;
}
void Ship::display_health(void){
	gotoxy(50,1);printf("VIDAS %d", vidas);
	gotoxy(64,1);printf("Salud");
	gotoxy(70,1);printf("      ");
	for(int i=0;i<corazones;i++){
		gotoxy(70+i,1);printf("%c",3);
	}
	return;
}
void Ship::death_animation(void){
	int counter = 0, i= 0;
	int extra_shit = 42;
	for(i;i<3;i++){
		for(counter=0;counter<3;counter++){
			gotoxy(x,y+counter);
			if(counter==1){
				printf("  %c%c%c%c ",extra_shit,extra_shit,extra_shit,extra_shit);
			}
			else{
				printf("   %c%c   ",extra_shit,extra_shit);
			}
		}
		Sleep(200);
		Ship::clean();
		switch(i){
			case 0: extra_shit = 221;break;
			default: extra_shit-=1;break;
		}
	}
}
void Ship::draw(void){
	gotoxy(x,y);printf("  %c",30);
	gotoxy(x,y+1);printf(" %c%c%c",40,207,41);
	gotoxy(x,y+2);printf("%c%c %c%c",30,190,190,30);
	return;
}
void Ship::move(void){
	Ship::display_health();
	if(kbhit()){
		char key = getch();
		Ship::clean();
		switch(key){
			case UP:y-=1;break;
			case DOWN:y+=1;break;
			case LEFT:x-=1;break;
			case RIGHT:x+=1;break;
			case SPACE:corazones-=1;break;
			case 'w':y-=1;break;
			case 's':y+=1;break;
			case 'a':x-=1;break;
			case 'd':x+=1;break;
			case 'q':gameover = true;break;
		}
		Ship::confirmPos();
	}
	return;
}
void Ship::death(void){
	if(corazones <= 0 ){
		vidas -= 1;
		corazones = 3;
		Ship::death_animation();
	}
	if(vidas <= 0){
		gameover = true;
		Ship::death_animation();
	}
	return;
}
int main(){
	system("cls");
	Ship ms = Ship(12, 19);
	hidecursor();
	drawborders();
	while(!ms.gameover){
		ms.draw();
		ms.move();
		ms.death();
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
	return ;
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
void drawborders(void){
	int x = 2,y = 2;
	for(x;x<=77;x++){
		gotoxy(x,2);printf("%c",205);
		gotoxy(x,22);printf("%c",205);
	}
	for(y;y<22;y++){
		gotoxy(2,y);printf("%c",186);
		gotoxy(77,y);printf("%c",186);
	}
	gotoxy(2,2);printf("%c", 201);
	gotoxy(77,2);printf("%c",187);
	gotoxy(2,22);printf("%c",200);
	gotoxy(77,22);printf("%c",188);
	return;
}