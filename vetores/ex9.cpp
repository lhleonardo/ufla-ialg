#include <iostream>

using namespace std;

int main() {
	float valores[10], somaPositivos=0;
	int qtdNegativos = 0;
	
	for (int i = 0; i < 10; i++) {
		cin >> valores[i];
		
		if (valores[i] > 0) {
			somaPositivos += valores[i];
		} else if (valores[i] < 0) {
			qtdNegativos++;
		}
	}
	
	cout << qtdNegativos << endl;
	cout << somaPositivos << endl;
	
	return 0;
}
