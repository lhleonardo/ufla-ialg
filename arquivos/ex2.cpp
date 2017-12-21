#include <iostream>
#include <fstream>

using namespace std;

struct Casa {
	string nome;
	string sede;
	string brasao;
};

string busca_casa(Casa valores[], int qtd, string filtro, char opcao) {
	string resposta;
	bool encontrou = false;
	int i = 0;

	while (i < qtd and not encontrou) {
		if (valores[i].nome == filtro) {
			if (opcao == 'c') {
				resposta = valores[i].sede;
			} else {
				resposta = valores[i].brasao;
			}
			encontrou = true;
		}
		i++;
	}

	return resposta;
}

int main() {
	Casa valores[100];
	Casa leitura;
	ifstream arquivo("casas.txt");

	int i = 0;
	while(i<100 and arquivo >> leitura.nome >> leitura.sede >> leitura.brasao) {
		valores[i] = leitura;
		i++;
	}

	string filtro;
	char op;

	cin >> filtro >> op;

	cout << busca_casa(valores, i, filtro, op) << endl;

	return 0;
}
