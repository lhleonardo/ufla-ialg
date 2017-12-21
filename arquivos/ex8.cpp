#include <iostream>
#include <fstream>

using namespace std;

bool eh_simetrica(int **valores, int ordem) {
	bool simetrica = true;
	for(int i = 0; i < ordem and simetrica; i++) {
		for(int j = 0; j < ordem and simetrica; j++) {
			if (valores[i][j] != valores[j][i])
				simetrica = false;
		}
	}
	return simetrica;
}

int main() {
	int ordem;

	ifstream leitor("matriz.txt");
	// falha ao abrir o arquivo.
	if (not leitor) return 0;

	leitor >> ordem;

	int **matriz = new int*[ordem];

	int leitura;
	for(int i = 0; i < ordem; i++) {
		matriz[i] = new int[ordem];
		for(int j = 0; j < ordem; j++) {
			leitor >> leitura;
			matriz[i][j] = leitura;
		}
	}

	if (eh_simetrica(matriz, ordem)) {
		cout << "simetrica" << endl;
	} else {
		cout << "nao simetrica" << endl;
	}

	leitor.close();
	for(int i = 0; i < ordem; i++)
		delete [] matriz[i];

	delete [] matriz;
	
	return 0;
}
