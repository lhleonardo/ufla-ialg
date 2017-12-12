#include <iostream>
#include <cstring>

using namespace std;

struct Produto {
	string nome;
	float custo;
	float percentual_venda;
};

// selection sort
void ordenaPeloNome(Produto lista[], int tam) {
	int min;

	Produto  aux;

	for(int i = 0; i < (tam-1); i++) {
		min = i;
		for(int j = i + 1; j < tam; j++)
			if (strcmp(lista[j].nome.c_str(), lista[min].nome.c_str()) < 0)
				min = j;
		aux = lista[min];
		lista[min] = lista[i];
		lista[i] = aux;
	}
}

float precoVenda(Produto produto) {
	return produto.custo + ((produto.custo * produto.percentual_venda)/100.0);
}

int main() {
	int tamanho;
	
	cin >> tamanho;

	Produto produtos[tamanho];

	for(int i = 0; i < tamanho; i++) {
		cin >> produtos[i].nome;
		cin >> produtos[i].custo;
		cin >> produtos[i].percentual_venda;
	}	

	ordenaPeloNome(produtos, tamanho);

	for(int i = 0; i < tamanho; i++) {
		cout << produtos[i].nome << " ";
		cout << produtos[i].custo << " ";
		cout << precoVenda(produtos[i]) << endl;
	}
	
	return 0;
}
