#include <iostream>

using namespace std;

int main() {
	float preco; 
	int codigoProduto;
	
	float desconto, precoAtualizado;
	
	cin >> preco;
	cin >> codigoProduto;
	
	if (preco <= 30) {
		desconto = 0;
	} else if (preco > 30 and preco <= 100) {
		desconto = (preco * 10)/100;		
	} else {
		desconto = (preco * 15)/100;
	}
	
	precoAtualizado = preco - desconto;
	
	cout << desconto << endl;
	cout << precoAtualizado << endl;
	
	
}
