#include <iostream>

using namespace std;

struct Carro {
	string nome; 
	int ano; 
	int preco;
};

int main() {
	int qtd; 
	cin >> qtd;
	
	
	Carro carros[qtd];
	
	for (int i = 0; i < qtd; i++) {
		cin >> carros[i].nome;
		cin >> carros[i].ano;
		cin >> carros[i].preco;
	}
	
	int referencia;
	cin >> referencia;
	
	for (int i = 0; i < qtd; i++) {
		if (carros[i].preco < referencia) {
			cout << carros[i].nome << " ";
			cout << carros[i].ano << " ";
			cout << carros[i].preco << endl;
		}
	}
	
}
