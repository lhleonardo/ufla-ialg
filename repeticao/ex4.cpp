#include <iostream>

using namespace std;

int main() {
	int valor;
	int ultimo; 
	int i = 0;
	
	bool ehSequencia = true;
	
	do {
		cin >> valor;
		if (i == 0) {
			cout << " i == 0 , então o ultimo valor é: "<< ultimo << endl;
			ultimo = valor;
			i++;
			continue;
		}
		if (valor > ultimo) {
			cout <<" valor [" valor << "] é maior que o ultimo [" << ultimo << "]" << endl ;
			i++;
			continue;
		} else {
			if (valor == ultimo) {
				i++;
				continue;
			}
			ehSequencia = false;
			break;
		}
		
		ultimo = valor;
		i++;
		
	} while (i < 5);
	
	if (ehSequencia == true) {
		cout << "1" << endl;
	} else {
		cout << "0" << endl;
	}
	
}
