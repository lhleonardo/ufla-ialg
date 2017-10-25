#include <iostream>

using namespace std;

int main() {
	float razao, resultado;
	int qtd, i = 0;
	
	cin >> razao >> qtd;
	
	resultado = 1;
	
	while(i < qtd) {
		cout << resultado << endl;
		resultado = resultado * razao;
		i++;
	}
	
	
		
}

