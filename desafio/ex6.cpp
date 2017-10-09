#include <iostream>
#include <limits>
using namespace std;
int main() {
	double maiorValor = numeric_limits<double>::min();
	double segundoMaiorValor = numeric_limits<double>::min();
	double soma = 0;
	double media;

	double valores [7];
		
	for (int i = 0; i < 7; i++) {
		cin >> valores[i];
	}
	
	// pega o maior valor
	for (int i = 0; i < 7; i++) {
		soma += valores[i];
		if (valores[i] > maiorValor) {
			maiorValor = valores[i];
		}
	}
		
	// pega o segundo maior valor
	for (int i = 0; i<7; i++) {
		// se for maior que o valor em i
		// e também se for diferente do maior valor...
		if (valores[i] > segundoMaiorValor) {
			if (valores[i] != maiorValor) {
				segundoMaiorValor = valores[i];	
			}
		}
	}
	
	soma -= maiorValor + segundoMaiorValor;	
	media = soma / 5;
	
	cout << maiorValor << endl;
	cout << segundoMaiorValor << endl;
	cout << media << endl;
	
	return 0;
}



