#include <iostream>

using namespace std;

struct Imposto {
	string nome;
	float valor;
};

struct ItemNota {
	string descricao, imposto;
	float valor;
};

Imposto lerImposto() {
	Imposto imposto;
	cin >> imposto.nome;
	cin >> imposto.valor;
	return imposto;
}

ItemNota leituraItem() {
	ItemNota item;
	cin >> item.descricao;
	cin >> item.valor;
	cin >> item.imposto;
	
	return item;
}

void criaNotaFiscal(ItemNota fiscal[], int qtdItem) {
	for(int i = 0; i < qtdItem; i++)
		fiscal[i] = leituraItem();
}

Imposto getImposto(string nome, Imposto impostos[], int qtd) {
	for(int i = 0; i < qtd; i++) 
		if (impostos[i].nome == nome)
			return impostos[i];
			
	Imposto i;
	return i; 
}

float impostoItem(ItemNota item, Imposto imposto) {
	return item.valor * imposto.valor;
}

float impostoTotal(ItemNota nota[], int qtdNota, Imposto impostos[], int qtdImposto) {
	float resultado = 0;
	
	for(int i = 0; i < qtdNota; i++) {
		Imposto imposto = getImposto(nota[i].imposto, impostos, qtdImposto);
		resultado += impostoItem(nota[i], imposto);
	}
	
	return resultado;
}

int main() {
	int qtdImp;
	cin >> qtdImp;
	Imposto impostos[qtdImp];
	
	for(int i = 0; i < qtdImp; i++)
		impostos[i] = lerImposto();
	
	int qtdNota;
	cin >> qtdNota;
	ItemNota notaFiscal[qtdNota];
	
	criaNotaFiscal(notaFiscal, qtdNota);
	
	cout << impostoTotal(notaFiscal, qtdNota, impostos, qtdImp);
	
	return 0;
}
