#include <iostream>

using namespace std;

int main() {
	int vetor[7], maior, segundoMaior;
	float media = 0;
	
	for(int i = 0; i < 7; i++){
		cin >> vetor[i];
		media += vetor[i];
	}
	
	for (int fim = 6; fim > 0; --fim) {
		for (int i = 0; i < fim; ++i) {
			if (vetor[i] < vetor[i+1]) {
				int aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
			}
		}
	}
	
	maior = vetor[0];
	segundoMaior = vetor[1];
	
	media -= maior;
	media -= segundoMaior;
	
	media /= 5;
	
	cout << maior << endl;
	cout << segundoMaior << endl;
	cout << media << endl;	
		
	return 0;
}
