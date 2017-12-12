#include <iostream>

using namespace std;

void troca(int valores[], int x, int y) {
	int temp = valores[x];
	valores[x] = valores[y];
	valores[y] = temp;
}

void particiona(int valores[], int &i, int &j) {
	int pivo = valores[((i+j)/2)];
	
	while(i <=j) {
		while (valores[i] < pivo) i++;
		while (valores[j] > pivo) j--;

		if (i<=j){
			troca(valores, i, j);
			i++;
			j--;
		}
	}
}

void quickSort(int valores[], int esquerda, int direita) {
	int i = esquerda, j = direita;
	
	particiona(valores, i, j);

	if (esquerda < j) {
		quickSort(valores, esquerda, j);
	}

	if (direita > i) {
		quickSort(valores, i, direita);
	}
}

int main() {
	int tam;
	cin >> tam;

	int valores[tam];

	for(int i = 0; i < tam; i++)
		cin >> valores[i];

	int i = 0, j = tam-1;

	quickSort(valores, i, j);

	for(int i = 0; i < tam; i++)
		cout << valores[i] << " ";
	cout << endl;
	return 0;
}
