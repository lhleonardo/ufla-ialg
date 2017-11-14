#include <iostream>

using namespace std;

int main() {
	int tamanho;

	cin >> tamanho;

	int valores[tamanho];
	int modas[tamanho];

	for (int i = 0; i < tamanho; i++) {
		cin >> valores[i];
	}
	// vai salvar a quantidade e tambem vai ser o contador do vetor
	// dois coelhos em uma cajadada... hehehe
	int qtdModa = 0;
	for (int i = 0; i < tamanho; i++) {
		for (int j = 0; j < tamanho; j++) {
			if (valores[i] == valores[j] and i != j) {
				if (valores[i] != -12321) {
					cout << valores[i] << "x" << valores[j];
					cout << " (" << i << "," << j << ")" << endl;
					modas[qtdModa] = valores[i];
					qtdModa++;
				}
			}
		}
	}
	
	cout << qtdModa << endl;
	if (qtdModa > 0) {
		for (int i = 0; i < qtdModa; i++) {
			cout << modas[i] << " ";
		}
	}
		
	return 0;
}
