#include <iostream>
#include <thread>
#include <windows.h>
using namespace std;
void vlt(void);
int main(){
	int i;
	std::thread vuelta retardada(vlt());
	for(i;i<10;i++){
		cout<<"vuelta "<<i;
	}
	return 0;
}
void vlt(void){
	Sleep(1000);
	cout<<"Vuelta con retrazo mental.";
	return;
}