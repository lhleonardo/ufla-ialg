#include <iostream>

using namespace std;

int main() {
	int valores[10], multiplos[5];
	unsigned int i;
	
	i = 0;
	while(i < 10) {
		cin >> valores[i];
		
		i++;
	}
	
	i = 0;
	while(i < 5) {
		cin >> multiplos[i];
		
		i++;
	}
	
	i = 0;
	while(i < 10) {
		unsigned int j = 0, qtd = 0;
		while (j < 5) {
			if (valores[i] % multiplos[j] == 0) {
				qtd++;
			}
			j++;
		}
		cout << valores[i] << " " << qtd << endl;
		
		i++;		
	}
	
}
