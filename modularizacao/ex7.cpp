#include <iostream>
#include <cstring>

using namespace std;

struct Contato {
	string nome;
	string telefone;
};

void adiciona(Contato novo, Contato lista[], int tamanho, int existentes) {
	if (existentes == 0) {
		lista[0] = novo;
		return;
	}

	// trocar os valores...........
}

void imprime(Contato contato) {
	cout << contato.nome << " ";
	cout << contato.telefone << endl;
}

void imprime(Contato lista[], int qtdInseridos) {
	cout << endl;
	
	if (qtdInseridos == 0) {
		imprime(lista[0]);
	} else {
		for( int i = 0; i < qtdInseridos; i++)
			imprime(lista[i]);
	}

	cout << endl;
}


int main() {
	int qtd;

	cin >> qtd;

	Contato contatos[qtd];

	for(int i = 0; i < qtd; i++) {
		Contato contato;
		cin >> contato.nome;
		cin >> contato.telefone;

		adiciona(contato, contatos, qtd, i);
		
		imprime(contatos, i);
		
	}

	return 0;
}
