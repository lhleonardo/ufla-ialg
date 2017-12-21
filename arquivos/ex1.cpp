#include <iostream>
#include <fstream>

using namespace std;

double phi(int numero) {
	if (numero == 1) return numero;

	return 1 + (1/double(phi(numero-1)));
}

int main() {

	int valor;
	cin >> valor;
	
	ofstream gravador("phi.txt");

	for(int i = 1; i <= valor; i++) {
		gravador << phi(i) << endl;
	}
	gravador.close();

	cout << phi(valor) << endl;
	return 0;
}
