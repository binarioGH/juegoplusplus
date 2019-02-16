#include <cstdio>
#include <windows.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
struct Body{
	int head[2] = {10,10};
	int chest[2] = {head[0],head[1]+1};
	int lefthand[2] = {head[0]-1,head[1]+1};
	int righthand[2] = {head[0]+1,head[1]+1};
	int legspace[2] = {head[0],head[1]+2};
	int leftleg[2] = {head[0]-1,head[1]+2};
	int rightleg[2] = {head[0]+1,head[1]+2};
}my;
void gotoxy(int x, int y);
void clean(int nx, int ny);
void ocultar(void);
void movebody(int x, int y);
void movepart(int& part, int x, int y);
int main(){
	ocultar();
	int x = 10, y = 10;
	bool gameover = false;
	while(!gameover){
		movebody(x, y);
		if(kbhit()){
			char tecla = getch();
			if(tecla == UP){
				y -= 1;
			}
			if(tecla == DOWN){
				y += 1;
			}
			if(tecla == LEFT){
				x -= 1;
			}
			if(tecla == RIGHT){
				x += 1;
			}

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
	return;
}
void clean(int nx,int ny){
	int count = 0;
	int toclean[14]={nx,ny,nx,ny+1,nx-1,ny+1,nx+1,ny+1,nx,ny+2,nx-1,ny+2,nx+1,ny+2};
	for(count;count<14;count+=2){
		gotoxy(toclean[count],toclean[count+1]);
		printf(" ");
	}
	return;
}

void ocultar(void){
	HANDLE hCon;
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize=0;
	cci.bVisible=FALSE;
	SetConsoleCursorInfo(hCon, &cci);
	return;
}
void movebody(int x, int y){
    my.head = {x,y};
	my.chest = {my.head[0],my.head[1]+1};
	my.lefthand = {my.head[0]-1,my.head[1]+1};
	my.righthand = {my.head[0]+1,my.head[1]+1};
	my.legspace = {my.head[0],my.head[1]+2};
	my.leftleg = {my.head[0]-1,my.head[1]+2};
	my.rightleg = {my.head[0]+1,my.head[1]+2};
    movepart(&my.head,my.head[0],my.head[1], 'O');
    movepart(&my.chest,my.chest[0],my.chest[1], '!');
    movepart(&my.lefthand,my.lefthand[0],my.lefthand[1], '/');
    movepart(&my.righthand,my.righthand[0],my.righthand, '\\') 
    movepart(&my.legspace,my.legspace[0],my.legspace[1], ' ');
	movepart(&my.leftleg,my.leftleg[0],my.leftleg[1], '/');
	movepart(&my.rightleg,my.rightleg[0],my.rightleg[1], '\\');
	return;
}
void movepart(int& pPart, int x, int y, char part){
	*pPart = {x, y};
	gotoxy(*pPart[0],*pPart[1]);
	printf(part);
	return;
}
