#include <iostream>

using namespace std;

void imprime(int matriz[10][10]) {
	for(int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	
}

int main(){
	int valores[10][10];

	for(int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> valores[i][j];
		}
	}

	cout << "1." << endl;

	// troca a segunda linha (1) com a oitava linha (7)
	for(int coluna = 0; coluna < 10; coluna++) {
		int aux = valores[1][coluna];
		valores[1][coluna] = valores[7][coluna];
		valores[7][coluna] = aux;
	}

	imprime(valores);

	cout << "2." << endl;
	for(int linha = 0; linha < 10; linha++) {
		int aux = valores[linha][3];
		valores[linha][3] = valores[linha][9];
		valores[linha][9] = aux;
	}

	imprime(valores);

	cout << "3." << endl;
	for(int i = 0; i < 10; i++) {
		// valores iguais : diagonal principal
		// valores opostos: diagonal secundaria 

		// salva o valor atual da principal
		int aux = valores[i][i];
		valores[i][i] = valores[i][9-i];
		// coloca o valor da diagonal principal na secundaria
		valores[i][9-i] = aux;
	}

	imprime(valores);

	cout << "4." << endl;
	// linha 5 com coluna 10
	for(int i = 0; i < 10; i++) {
		int aux = valores[4][i];
		valores[4][i] = valores[i][9];
		valores[i][9] = aux;
	}

	imprime(valores);
	
	return 0;
}
