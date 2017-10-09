#include <iostream>

using namespace std;

int main() {
	int valores [4];
	
	for (unsigned int i = 0; i < 4; i++) {
		cin >> valores[i];
	}
	
	for (unsigned int fim = 3; fim > 0; --fim) {
        for (unsigned int i = 0; i < fim; ++i) {
            if (valores[i] > valores[i+1]) {
                int aux = valores[i];
                valores[i] = valores[i+1];
                valores[i+1] = aux;
            }
        }
    }
    
    for (unsigned int i = 0; i < 4; i++) {
		if (i == 3) 
			cout << valores[i];
		else
			cout << valores[i] << " ";
	}
	
	
	
	
	return 0;
}
