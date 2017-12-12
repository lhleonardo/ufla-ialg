#include <iostream>

using namespace std;

int menor_valor(int vetor[], int tam) {
	if (tam == 1) 
		return vetor[0];
	
	int menor = vetor[0];
	
	for(int i = 1; i < tam; i++) {
		if (vetor[i] < menor) {
			menor = vetor[i];
		}
	}
	
	return menor;
}

int main() {
	int tam;
	cin >> tam;
	
	int valores[tam];
	
	for(int i = 0; i < tam; i++) 
		cin >> valores[i];
		
	cout << menor_valor(valores, tam) << endl;
	
	return 0;
}
