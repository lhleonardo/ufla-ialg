#include <iostream>
#include <cmath>

using namespace std;

int main() {
	char opcao;
	float valor;
	
	cin >> opcao;
	
	if (opcao == 's') {
		cin >> opcao;
		cin >> valor;
		if (opcao == 'g') {
			//valor = valor * (M_PI / 180.0);
			
			//cout << (sin(valor) * 180.0 / M_PI);
			cout << sin(valor);
		} else {
			cout << sin(valor);
		}
	
	} else {
		cin >> opcao;
		cin >> valor;
		if (opcao == 'g') {
			valor = (valor * M_PI) / 180.0;
			cout << ((cos(valor) * 180.0) / M_PI);
		} else {
			cout << cos(valor);
		}
		
	}
	
		
	return 0;
}
