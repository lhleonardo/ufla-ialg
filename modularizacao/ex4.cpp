#include <iostream>

using namespace std;

struct Imposto {
	string nome;
	float valor;
};

struct Item {
	string descricao;
	float valor;
	Imposto imposto;
};

struct NotaFiscal {
	Item *itens;	
};

void lerItensNotaFiscal(Item itens[], int tam) {
	for(int i = 0; i < tam; i++) {
		cin >> itens[i].descricao;
		cin >> itens[i].valor;
		cin >> itens[i].imposto.nome;
	}	
} 

NotaFiscal lerNotaFiscal(Item valores[]) {
	NotaFiscal nf;

	nf.(&itens) = (&valores);

	return nf;
}

void lerImpostos(Imposto impostos[], int tam) {
	for(int i = 0; i < tam; i++) {
		cin >> impostos[i].nome;
		cin >> impostos[i].valor;
	}
}

int main() {
	int qtdAliquota, qtdItens;

	cin >> qtdAliquota;

	Imposto impostos[qtdAliquota];

	lerImpostos(impostos, qtdAliquota);

	cin >> qtdItens;

	Item itens[qtdItens];

	lerItensNotaFiscal(itens, qtdItens);

}
