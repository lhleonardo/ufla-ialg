#include <iostream>

using namespace std;

bool busca(int **valores, int linha, int coluna, int elemento) {
	bool encontrado = false;
	for(int i = 0; i < linha and not encontrado; i++) {
		for(int j = 0; j < coluna and not encontrado; j++) {
			//cout << valores[i][j] << " ";
			if (valores[i][j] == elemento) encontrado = true;
		}
	}
	return encontrado;
}

int main() {
	int linha, coluna;
	cin >> linha >> coluna;

	int **matriz = new int*[linha];

	for(int i = 0; i < linha; i++) {
		matriz[i] = new int[coluna];
		for(int j = 0; j < coluna; j++) {
			cin >> matriz[i][j];
		}
	}

	int elemento;
	cin >> elemento;
	
	if (busca(matriz, linha, coluna, elemento)) {
		cout << "1" << endl;
	} else {
		cout << "0" << endl;
	}

	for(int i = 0; i < linha; i++)
		delete [] matriz[i];

	delete [] matriz;
	return 0;
}
