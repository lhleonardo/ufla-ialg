#include <iostream>

using namespace std;

int main() {
	unsigned int contador = 0, qtdA = 0, qtdB = 0;
	char leitura;
	
	do {
		cin >> leitura;
		if (leitura == 'a') {
			qtdA++;
		} else if (leitura == 'b'){
			qtdB++;
		}
		contador++;
		
	} while(contador < 10);
	
	if (qtdA < qtdB) {
		cout << "1";
	} else {
		cout << "0";
	}
	
	return 0;
}

