#include <iostream>

using namespace std;

void ordena(int valores[], int tam) {
	int min, aux;
	for(int i = 0; i < tam-1; i++) {
		min = i;
		for(int j = i+1; j < tam; j++)
			if (valores[j] < valores[min])
				min = j;

		aux = valores[min];
		valores[min] = valores[i];
		valores[i] = aux;
	}
}

int main() {
	int tam;
	cin >> tam;

	int valores[tam];
	for(int i = 0; i < tam; i++) {
		cin >> valores[i];
	}

	int fim;
	cin >> fim;
	ordena(valores, fim+1);

	for(int i = 0; i < tam; i++)
		cout << valores[i] << " ";

	cout << endl;
	return 0;
}
