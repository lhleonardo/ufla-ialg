#include <iostream>

using namespace std;

void imprime(int valores[], int tamanho) {
	cout << "[";

	for(int i = 0; i < tamanho; i++) {
		cout << valores[i];

		if (i != (tamanho-1))
			cout << ", ";
	}

	cout << "]";
}

int main() {
	int tamanho;
	cin >> tamanho;

	int valores[tamanho];

	for(int i = 0; i < tamanho; i++)
		cin >> valores[i];

	imprime(valores, tamanho);

	cout << endl;

	return 0;
}
