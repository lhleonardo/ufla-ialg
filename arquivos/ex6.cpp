#include <iostream>
#include <fstream>

using namespace std;

int main() {
	string destino, conteudo;

	cin >> destino;
	cin >> conteudo;

	ofstream gravador(destino.c_str());
	gravador << conteudo;

	gravador.close();

	return 0;
}
