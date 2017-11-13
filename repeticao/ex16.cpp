#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int num, aux;
			
	cin >> num;
	
	for (int cont = 1; cont <= num; cont++){
		aux = cont;
		if(pow(aux, 2) <= num){
			aux = pow(aux,2);
			cout << aux << " ";
		}
	}
}
