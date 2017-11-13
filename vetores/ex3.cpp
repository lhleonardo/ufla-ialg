#include <iostream>

using namespace std;

int main() {
	int valores[7];
	int multiplicacao = 1;
	
	for(unsigned int i = 0; i < 7; i++) {
		cin >> valores[i];
	}
	
	int posicao; 
	
	cin >> posicao;
	
	while(posicao >= 0){
		if (posicao >=0 and posicao <=6) {
			multiplicacao *= valores[posicao];
		}
	
		cin >> posicao	;
	}
	
	cout << multiplicacao << endl;
	
	return 0;
}
