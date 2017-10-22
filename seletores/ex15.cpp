#include <iostream>

using namespace std;

float getPrecoProduto(int codigo) {
	if (codigo >=1 and codigo <=10) {
		return 10;
	}
	
	if (codigo >=11 and codigo <=20) {
		return 15;
	}
	
	if (codigo >=21 and codigo <=30) {
		return 20;
	}
	
	if (codigo >=31 and codigo <= 40) {
		return 30;
	}
	
	return -1;
}

float calculaDesconto(float valor) {
	if (valor < 250 and valor >= 0) {
		return (valor * 5) / 100.0;
	} else if (valor >= 250 and valor <= 500) {
		return (valor * 10) / 100.0;
	} else {
		return (valor * 15) / 100.0;
	}	
}

int main() {
	int codigoProduto, quantidade;
	float precoUnitario, valorBruto;
	float desconto, valorFinal;	
	
	
	cin >> codigoProduto;
	cin >> quantidade;
	
	precoUnitario = getPrecoProduto(codigoProduto);
	valorBruto = precoUnitario * quantidade;
	desconto = calculaDesconto(valorBruto);
	valorFinal = valorBruto - desconto;
	
	cout << precoUnitario << endl;
	cout << valorBruto << endl;
	cout << desconto << endl;
	cout << valorFinal << endl;
	
	return 0;
}
