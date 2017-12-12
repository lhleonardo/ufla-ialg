#include <iostream>
#include <fstream>

using namespace std;

struct Produto {
	string nome;
	float compra;
	float venda;
};

void ler_produtos(string origem, Produto produtos[], int qtd) {
	ifstream leitor (origem.c_str());

	for(int i = 0; i < qtd; i++) {
		leitor >> produtos[i].nome;
		leitor >> produtos[i].compra;
		leitor >> produtos[i].venda;
	}
	
}

float calcula_lucro(Produto produto) {
	return produto.venda-produto.compra;
}

void swap(Produto produtos[], int x, int y) {
	Produto aux = produtos[x];
	produtos[x] = produtos[y];
	produtos[y] = aux;
}

void ordena(Produto produtos[], int tam) {
	bool troca;
	do {
		troca = false;
		for(int i = 0; i < tam-1; i++) {
			if (calcula_lucro(produtos[i]) > calcula_lucro(produtos[i+1])){
				swap(produtos, i, i+1);
				troca = true;
			}
		}
		
	} while(troca);
}

void salva_arquivo(string destino, Produto valores[], int qtd) {
	ofstream gravador (destino.c_str(), ios::app);

	if (not gravador){
		cout << "Nao eh possivel gravar!";
		return;
	}

	for(int i = 0; i < qtd ;i++) {
		gravador << valores[i].nome << " ";
		gravador << valores[i].compra << " ";
		gravador << valores[i].venda << " ";
		gravador << calcula_lucro(valores[i]) << endl;
	}

	gravador.close();
}

int main() {
	int tam;
	cin >> tam;
	
	Produto produtos[tam];
	
	ler_produtos("produtos.txt", produtos, tam);

	ordena(produtos, tam);

	salva_arquivo("lucros.txt", produtos, tam);
	
	return 0;
}
