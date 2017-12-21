#include <iostream>

using namespace std;

int * somatorio_linhas(int matriz[5][5]) {
	int tam = 5, soma;
	int *valores = new int[tam];
	
	for(int i = 0; i < 5; i++) {
		soma = 0;
		for(int j = 0; j < 5; j++) {
			soma += matriz[j][i];
		}
	//	cout << "A posicao " << i << " vai receber " << soma << endl;
		valores[i] = soma;
	}

	return valores;
}

int main() {
	int matriz[5][5];

	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			cin >> matriz[i][j];
		}
	}

	int *valores = somatorio_linhas(matriz);

	for(int i = 0; i < 5; i++) {
		cout << valores[i] << " ";
	}
	cout << endl;

	delete [] valores;
	return 0;
}
