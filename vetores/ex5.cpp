#include <iostream>

using namespace std;

int main() {
	int codigos[10];
	int quantidades[10];
	int qtdInsuficiente = 0, qtdInconsistente = 0;
		
	for (int i = 0; i < 10; i++) {
		cin >> codigos[i];		
		i++;
	} 
	
	for (int i = 0; i < 10; i++) {
		cin >> quantidades[i];
		i++;
	}
	
	int cliente = -1, produto, quantidade;
	
	while (cliente != 0) {
		cin >> cliente;
		cin >> produto;
		cin >> quantidade;
	
		bool encontrou = false;
		int posicao;
		
		for (int i = 0; (i < 10) and (not encontrou); i++) {
			if (codigos[i] == produto) {
				posicao = i;
				encontrou = true;
			}
		}
		
		if (encontrou) {
			if (quantidades[posicao] >= quantidade) {
				quantidades[posicao] -= quantidade;
			} else {
				qtdInsuficiente++;
			}
			
		} else {
			qtdInconsistente++;		
		}
	}
	
	for (int i = 0; i < 10; i++) {
		cout << codigos[i] << " " << quantidades[i] << endl;
	}
	
	cout << qtdInconsistente << endl;
	cout << qtdInsuficiente << endl;
	
	return 0;
}
