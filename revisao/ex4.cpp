#include <iostream>
#include <climits>

using namespace std;

int main() {
		
	int menorValor = INT_MAX;
	int maiorValor = INT_MIN;
	
	for (unsigned int i = 0; i < 5; i++) {
		int valor;
		
		cin >> valor;
		if (valor > maiorValor) {
			maiorValor = valor;
		}
		
		if (valor < menorValor) {
			menorValor = valor;
		}
	}
	
	cout << menorValor << endl;
	cout << maiorValor << endl;
	
	
	return 0;
}
