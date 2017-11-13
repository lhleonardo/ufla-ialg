#include <iostream>

using namespace std;

int main() {
	int numeros[8], positivos[8], negativos[8];
	int qtdPositivo = 0, qtdNegativo = 0;
	
	int contPos = 0, contNeg = 0;
	
	for (int i = 0; i < 8; i++) {
		cin >> numeros[i];
		if (numeros[i] > 0) {
			positivos[contPos] = numeros[i];
			qtdPositivo++;
			contPos++;
		} else if (numeros[i] < 0) {
			negativos[contNeg] = numeros[i];
			qtdNegativo++;
			contNeg++;
		} 
	}
	
	for(int i = 0; i < qtdPositivo; i++) {
		cout << positivos[i] << " ";
	}
	
	cout << endl;
	
	for(int i = 0; i < qtdNegativo; i++) {
		cout << negativos[i] << " ";
	}
	
	return 0;
}
