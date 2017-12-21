#include <iostream>
#include <fstream>

using namespace std;

int main() {
	string origem, conteudo;

	cin >> origem;
	ifstream leitor(origem.c_str());
	if (leitor) {
		leitor >> conteudo;
		cout << conteudo << endl;
	} else {
		// falha ao ler o arquivo.
		return 0;
	}
	return 0;
}
