#include <iostream>

using namespace std;

float fatorial(int numero) {
	if (numero == 0) {
		return 1;
	} 
	
	return numero * fatorial(numero-1);
}

int main() {
	int numero;
	float resultado = 0;
	
	cin >> numero;
		
	for(int i = 0; i <= numero; i++) {
		resultado += 1 / fatorial(numero);
	}
	
	cout << resultado << endl;

	return 0;
}
