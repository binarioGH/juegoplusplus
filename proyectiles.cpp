#include <iostream>
#include <conio.h>
#include "functions.cpp"
using namespace std;
void StartAnimation(Ship& nave);
int main(int nArgs, char* ARGV[]){
	system("cls");
	hideCursor();
	AST a1(10,4), a2(4,8), a3(15,10);
	Ship ms = Ship(39, 26);
	StartAnimation(ms);
	drawborders();
	while(!ms.gameover){
		a1.move();
		a2.move();
		a3.move();
		ms.draw();
		ms.checkmove();
		ms.death();
		Sleep(100);
	}
	return 0;
}
void StartAnimation(Ship& nave){
	int i;
	for(i=0;i<7;i++){
		nave.draw();
		Sleep(500);
		nave.move('w');	
	}
	gotoxy(25,6);
	cout<<"- G A L A X Y   D E F E N D E R -";
	for(i=27;i<56;i++){
		gotoxy(i,7);
		cout<<"_";
		Sleep(100);
	}
	Sleep(3000);
	system("cls");
	return;
}
