#include <iostream>

using namespace std;

void imprime(int valores[], int tam) {
	for(int i = 0; i < tam; i++)
		cout << valores[i] << " ";

	cout << endl;
}

void select_sort(int vetor[], int tam) {
	int min, aux;
	
	for(int i = tam-1; i >=0 ; i--) {
		min = i;
		for(int j = 0; j < i; j++) {
			if (vetor[j] < vetor[min]) min = j;
		}		
		aux = vetor[min];
		vetor[min] = vetor[i];
		vetor[i] = aux;
		if (min != i)
			imprime(vetor, tam);
	}	
}

int busca_binaria(int valores[], int tam, int e, int &qtd) {
	int posicao = -1;
	int inicio = 0; // inicio do vetor sendo considerado
	int fim = tam - 1; // fim do vetor sendo considerado
	int meio;
	
	while (inicio <= fim) {
		meio = (inicio + fim)/2;
		if (e == valores[meio]) {
			posicao = meio;
			inicio = fim + 1; // para terminar while
			qtd++;
		} else {
			if (e > valores[meio]) {
				inicio = meio + 1;
				qtd++;
			} else { // elemento < meio
				fim = meio - 1;
				qtd++;
			}
		}
	}
	return posicao;		
}

int main() {
	int tam, e;
	cin >> tam;
	int valores[tam];

	if (tam <=0) return 0;

	for(int i = 0; i < tam; i++)
		cin >> valores[i];
	
	select_sort(valores, tam);

		cin >> e;
	
	int qtd = 0;
	int pos = busca_binaria(valores, tam, e, qtd);

	cout << pos << endl;
	cout << qtd << endl;
	
	return 0;
}
