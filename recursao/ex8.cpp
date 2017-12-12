#include <iostream>

using namespace std;

void reverso(int tamanho) {
	int numero;
	cin >> numero;

	if (tamanho > 1) {
		reverso(tamanho-1);
	} else {
		//...
	}

	cout << numero << " 	";
	
}

int main() {
	int qtd;

	cin >> qtd;

	reverso(qtd);
	
	return 0;
}
