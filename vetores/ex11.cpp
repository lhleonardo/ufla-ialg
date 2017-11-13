#include <iostream>

using namespace std;


int main() {
	int tamanho;
	
	cin >> tamanho;
	
	char valores[tamanho];
	
	for (int i = 0; i < tamanho; i++) {
		cin >> valores[i];
	}
	
	char marc1, marc2;
	
	cin >> marc1; 
	cin >> marc2;
	
	int indice1 = -1, indice2 = -1;
	
	for (int i = 0; (i < tamanho and (indice1 == -1 or indice2 == -1)); i++) {
		if (valores[i] == marc1) {
			indice1 = i;
		}
		if (valores[i] == marc2) {
			indice2 = i;
		}
	}
	
	if (indice1 > indice2) {
		for(int i = indice2 + 1; i < indice1; i++) {
			cout << valores[i] << " ";
		}
	} else {
		for(int i = indice1 + 1; i < indice2; i++) {
			cout << valores[i] << " ";
		}
	}
	
	
	return 0;
}
