#include <iostream>

using namespace std;

int main() {
	int tamanho;
	
	cin >> tamanho;
	
	int valores[tamanho];
	
	for (int i = 0; i < tamanho; i++) {
		cin >> valores[i];
	}
	
	int valorRemover, posicaoRemover = -1;
	
	cin >> valorRemover;
	
	for (int i = 0; i < tamanho and posicaoRemover == -1; i++) {
		if (valores[i] == valorRemover) {
			posicaoRemover = i;
		}
	} 
	
	if (posicaoRemover == -1) {
		cout << "ELEMENTO NAO ENCONTRADO" << endl;
		
		return 0;
	}
	
	for (int i = 0; i < tamanho; i++) {
		if (i != posicaoRemover) {
			cout << valores[i] << " ";
		}
	}
	
	return 0;
}
