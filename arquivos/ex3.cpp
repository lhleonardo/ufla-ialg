#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

void trim(string *st, char remover) {
	(*st).erase(remove((*st).begin(), (*st).end(), ' '), (*st).end());
}

int main() {
	string entrada, saida;
	cin >> entrada >> saida;

	ifstream leitor(entrada.c_str());
	ofstream gravador(saida.c_str());
	
	string leitura;
	while (leitor >> leitura) {
		trim(&leitura, ' ');
		gravador << leitura;
	}
	
	return 0;
}
