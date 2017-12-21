#include <iostream>

using namespace std;

void troca(int vetor[], int x, int y) {
	int aux = vetor[x];
	vetor[x] = vetor[y];
	vetor[y] = aux;
}

void ordena(int valores[], int tam) {
	int min;
	for(int i = 0; i < tam-1; i++) {
		min = i;
		for(int j = i+1; j < tam; j++)
			if (valores[j] < valores[min])
				min = j;
		troca(valores, i, min);
		
	}
}

int main() {
	int n;
	cin >> n;

	int valores[n];

	for(int i = 0; i < n; i++)
		cin >> valores[i];

	int k;
	cin >> k;

	ordena(valores, n);

	for(int i = 0; i < k; i++)
		cout << valores[i] << " ";
		
	return 0;
}
