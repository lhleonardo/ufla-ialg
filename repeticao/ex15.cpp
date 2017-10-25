#include <iostream>

using namespace std;

int main() {
	unsigned int dimensao;
	unsigned int linha=0, coluna;
	char ultimo = '!';
	
	cin >> dimensao;
	
	if (dimensao == 0) {
		// nao tem o que fazer com um tabuleiro 0x0
		return 0;
	}
	
	if (dimensao == 1) {
		cout << "." << endl;
		return 0;
	}
	
	if (dimensao == 2) {
		cout << ".#" << endl << "#." << endl;
		return 0;
	}
	
	while(linha < dimensao) {
		coluna = 0;
		while(coluna < dimensao) {
			
			if (dimensao % 2 == 0 and (coluna == 0)) {
				if (ultimo == '!') {
					ultimo = '.';
				}
				cout << ultimo;
				coluna++;
				continue;
			}			
			// primeiro elemento
			if (ultimo == '!') {
				ultimo = '.';
				cout << ultimo;
				coluna++;
				continue;
			} else {
				if (ultimo == '.') {
					ultimo = '#';
					cout << ultimo;
					coluna++;
					continue;
				} else if (ultimo == '#') {
					ultimo = '.';
					cout << ultimo;
					coluna++;
					continue;
				}
			}
			
		}
		cout << endl;
		linha++;		
	}
	
	
	
	
	return 0;
}
