#include <iostream>

using namespace std;

void imprime(int valores[], int tam, int x, int y, bool trocados) {
	for(int i = 0; i < tam; i++) {
		cout << valores[i] << " ";
		if ((x >=tam or x <0) or (y >=tam or y < 0)) {
			cout << " \t";
		} else {
			if (x == i) {
				if (trocados)
					cout << "t";
				else
					cout << "*";
			} else if(y==i) {
				if (trocados)
					cout << "t";
				else
					cout << "*";
			}
			cout << "\t";
		}
	}
	cout << endl;
}

void troca(int vetor[], int x, int y) {
	int aux = vetor[x];
	vetor[x] = vetor[y];
	vetor[y] = aux;
}

void ordena(int vetor[], unsigned int tam) {
	bool trocado;
	do {
		trocado = false;
		for(unsigned int i = 0; i < tam -1; i++) {
			if (vetor[i] > vetor[i+1]) {
				imprime(vetor, tam, i, i+1, true);
				troca(vetor, i, i+1);
				trocado = true;
			} else
				imprime(vetor, tam, i, i+1, false);
		}
	} while(trocado);
	// imprimir sem descricao
	imprime(vetor, tam, -1, -1, false);
}

int main() {
	int tamanho;
	cin >> tamanho;
	int valores[tamanho];

	for(int i = 0; i < tamanho; i++) {
		cin >> valores[i];
	}

	ordena(valores, tamanho);
	return 0;
}
