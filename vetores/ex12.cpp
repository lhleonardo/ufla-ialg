#include <iostream>

using namespace std;

int main() {
	int tamanho;
	cin >> tamanho;
	
	int numeros[tamanho];
	bool isPalindromo = true;
		
	for (int i = 0; i < tamanho; i++) {
		cin >> numeros[i];		
	}
	
	for (int i = 0; i < tamanho and isPalindromo; i++) {
		if (tamanho%2 == 0) {
			if (numeros[i] != numeros[(tamanho-1) - i]) {
				isPalindromo = false;
			}
		} else {
			// eh impar, entao o elemento (tamanho/2 + 1) não necessita 
			// ser identico a outro elemento, ja que, por exemplo, o 
			// numero 12321, o valor 3 nao tem com quem ser comparado.
			if (i != ((numeros[i] / 2)+1)) {
				if (numeros[i] != numeros[(tamanho-1) - i]) {
					isPalindromo = false;
				}
			}
		}
	}
	
	cout << isPalindromo << endl;
		
	return 0;
}
