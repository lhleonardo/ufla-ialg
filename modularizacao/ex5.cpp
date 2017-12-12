#include <iostream>

using namespace std;

int busca(int v[], int tam, int procurado, int &verificacoes) {
	int pos = -1;
	int inicio = 0; 
	int fim = tam - 1; 
	int meio;
	
	while (inicio <= fim) {
		meio = (inicio + fim)/2;
		if (procurado == v[meio]) {
			pos = meio;
			inicio = fim + 1; // para terminar while
			verificacoes++;
		} else {
			if (procurado > v[meio]) {
				inicio = meio + 1;
				verificacoes++;
			} else {
				fim = meio - 1;
				verificacoes++;
			}
		}
	}
	
	return pos;
}

int main() {
	int tamanho;
	cin >> tamanho;

	int valores[tamanho];

	for(int i = 0; i < tamanho; i++)
		cin >> valores[i];

	int elemento, qtdVerificacoes = 0;
	cin >> elemento;

	int posicao = busca(valores, tamanho, elemento, qtdVerificacoes);

	cout << posicao << endl;
	cout << qtdVerificacoes << endl;
	
	return 0;
}
