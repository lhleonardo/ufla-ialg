#include <iostream>

using namespace std;

void troca(int vetor[], int x, int y) {
	int aux = vetor[x];
	vetor[x] = vetor[y];
	vetor[y] = aux;
}

void bubble(int vetor[], int tam) {
	bool trocado = false;
	do {
		trocado = false;
		for(int i = 0; i < tam-1; i++) {
			if (vetor[i] > vetor[i+1]) {
				troca(vetor, i, i+1);
				trocado = true;
			}
		}
	}while (trocado);
}

void bubbleAlternativo(int vetor[], int tam) {
	bool trocado;
	do {
		trocado = false;
		for(int i = tam-1; i >= 1; i--) {
			if (vetor[i] < vetor[i-1]) {
				troca(vetor, i, i-1);
				trocado = true;
			}
		}
	} while(trocado);
}

void inverso(int vetor[], int tam) {
	bool trocado;
	do {
		trocado = false;
		for(int i = tam-1; i >=1; i--)
			if (vetor[i] > vetor[i-1]) {
				troca(vetor, i, i-1);
				trocado = true;
			}
	} while(trocado);
}

void inversoAlternativo(int vetor[], int tam) {
	bool trocado;
	do {
		trocado = false;
		for(int i = 0; i < tam-1; i++) {
			if (vetor[i] < vetor[i+1]) {
				troca(vetor, i, i+1);
				trocado = true;
			}
		}
	} while(trocado);
	
}


void imprime(int v[], int t) {
	for(int i = 0; i < t; i++) 
		cout << v[i] << " ";
	cout << endl;
}

int main() {
	int tam, leitura;
	cin >> tam;
	int v1[tam], v2[tam], v3[tam], v4[tam];

	if (tam == 0) return 0;
	
	for(int i = 0; i < tam; i++) {
		cin >> leitura;
		v1[i] = leitura;
		v2[i] = leitura;
		v3[i] = leitura;
		v4[i] = leitura;
	}
	
	bubble(v1, tam);
	bubbleAlternativo(v2, tam);

	inverso(v3, tam);
	inversoAlternativo(v4, tam);

	cout << "levando os maiores elementos para o final do vetor" << endl;
	imprime(v1, tam);
	cout << "levando os menores elementos para o inicio do vetor" << endl;
	imprime(v2, tam);
	cout << "levando os maiores elementos para o inicio do vetor" << endl;
	imprime(v3, tam);
	cout << "levando os menores elementos para o final do vetor" << endl;
	imprime(v4, tam);
	
	return 0;
}
