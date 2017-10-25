#include <iostream>

using namespace std;

int mdc(int valor1, int valor2) {
    
    int i, menor;
 
    // pega o menor valor
	if (valor1<valor2) {
		menor=valor1;
	} else {
		menor=valor2;
	}
    

	for (i=menor; i>=1; i--) {
        // se os dois forem divisiveis, seus restos serão 0
        // e a negação de zero é 1, ou seja, true
		if (!(valor1%i) && !(valor2%i)) {
			return i;
		}
	}
 
	return 0;
}

int main() {
	int v1, v2;
	
	cin >> v1;
	cin >> v2;
	
	cout << mdc(v1, v2) << endl;
	
	
	return 0;
}
