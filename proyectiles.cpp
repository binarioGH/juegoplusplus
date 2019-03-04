#include <stdio.h>
#include <list>
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
	list<Bullet*> B;
	list<Bullet*>::iterator it;
	while(!ms.gameover){
		if(kbhit()){
			char key = getch();
			if(key == 32){
				B.push_back(new Bullet(ms.X()+2,ms.Y()-1));
			}
		}
		for(it =B.begin();it!=B.end();it++){
			 (*it)->move();
			 if((*it)->out()){
			 	gotoxy((*it)->GetX(), (*it)->GetY());
			 	printf(" ");
			 	delete(*it);
			 	it = B.erase(it);
			 }
		}
		a1.move();
		a2.move();
		a3.move();
		a1.collision(ms);
		a2.collision(ms);
		a3.collision(ms);
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
	printf("- G A L A X Y   D E F E N D E R -");
	for(i=27;i<56;i++){
		gotoxy(i,7);
		printf("_");
		Sleep(100);
	}
	Sleep(3000);
	system("cls");
	return;
}
