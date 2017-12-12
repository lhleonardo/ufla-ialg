#include <iostream>
#include <fstream>

using namespace std;

struct Produto {
	string nome;
	float compra;
	float venda;
};

void lerProdutos(Produto produtos[], int qtd) {
	for(int i = 0; i < qtd; i++) {
		cin >> produtos[i].nome;
		cin >> produtos[i].compra;
		cin >> produtos[i].venda;
	}
}

void escreverNoArquivo(Produto produtos[], int qtd, string destino) {
	ofstream gravador(destino.c_str(), ios::app);

	if (not gravador) {
		cout << "Nao eh possivel gravar!";
		return;
	}

	for(int i = 0; i < qtd;i++) {
		gravador << produtos[i].nome << " ";
		gravador << produtos[i].compra << " ";
		gravador << produtos[i].venda << endl;
	}

	gravador.close();
}

int main () {
	int qtd;
	cin >> qtd;

	Produto produtos[qtd];

	lerProdutos(produtos, qtd);

	escreverNoArquivo(produtos, qtd, "produtos.txt");

	return 0;
}
