#include <iostream>

using namespace std;

void ordena(float valores[], int tam) {
	int j, aux;
	
	for(int i = 1; i < tam-1; i++) {
		j = i-1;
		aux = valores[i];
		while((j>=0) and (aux < valores[j])) {
			valores[j+1] = valores[j];
			j--;
		}
		valores[j+1] = aux;
	}
}

int main() {


	return 0;
}
