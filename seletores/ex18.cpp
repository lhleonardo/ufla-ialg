#include <iostream>

using namespace std;

int main() {
	unsigned int qtdCartas, posicao;
	unsigned int valorPosicao, novaPosicao;
	
	
	cin >> qtdCartas;
	cin >> posicao;
	
	if (qtdCartas == 0 and posicao == 0) {
		cout << 0 << endl;
		return -1;
	} 
	
	unsigned int valores[qtdCartas];
	unsigned int embaralhados[qtdCartas];
	
	// coloca valores ficticios
	for (unsigned int i = 0; i < qtdCartas; i++) {
		valores[i] = i;
		
		if (i == posicao) 
			valorPosicao = i;
	} 
	
	
	// realiza o corte de faro
	unsigned int j = (qtdCartas / 2);
	unsigned int k = 0;
	for (unsigned int i = 0; i < (qtdCartas/2); i++) {
		if (j < qtdCartas and k < qtdCartas) {
			embaralhados[k] = valores[j];
			k++;
			j++;
		}
		
		if (k < qtdCartas) {
			embaralhados[k] = valores[i];
			k++;
		}
	}	
	
	for (unsigned int i = 0; i < qtdCartas; i++) {
		if (embaralhados[i] == valorPosicao) {
			novaPosicao = i;
			break;
		}
	}

	cout << novaPosicao << endl;
	
	return 0;
}
