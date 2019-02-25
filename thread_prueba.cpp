#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;
void *procesoSeparado(void);
int main(){
	pthraed p1;
	pthread_create(&p1,NULL, &procesoSeparado, NULL);
	int i = 0;
	for(i;i<5;i++){
		cout<<"Thread: "<<i<<endl;
	}
	return 0;
}
void procesoSeparado(void){
	int i = 0;
	for(i;i<5;i++){
		cout<<"Thread: "<<i<<endl;
	}
	return;
}