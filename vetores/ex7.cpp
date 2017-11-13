#include <iostream>

using namespace std;

int main() {
	int valores[10];
	int k;
	
	cin >> k;
	
	if (k > 10) {
		// k <=10
		return 0;
	}
	
	for (int i = 0; i < 10; i++) {
		if (i < k) {
			cin >> valores[i];
		} else {
			valores[i] = 0;
		}
	}

	int valor, posicao;
	
	cin >> valor >> posicao;
	
	if ((posicao > (k - 1)) and posicao < 10) {
		// valor acima do k, entao nao tem que deslocar
		valores[posicao] = valor;
	} else {
		if (posicao == (k-1)) {
			// coloca em sequencia do ultimo valor definido pelo usuario (k)
			// ja que a posicao no vetor valida para k eh k-1 (ultimo valor)
			int aux = valores[k-1];
			valores[k-1] = valor;
			valores[k] = aux;
		} else {
			// insere no meio do vetor...
			if (posicao == 9) {
				valores[9] = valor;
			} else if (posicao >= 0) {
				int ultimo = valor;
				
				for (int i = posicao; i <= k; i++) {
					int aux = valores[i];
					valores[i] = ultimo;
					ultimo = aux;
				}
				
			}
			
		}
		
	}
	
	for (int i = 0; i < 10; i++) {
		cout << valores[i] << " ";
	}
	
	return 0;
}
