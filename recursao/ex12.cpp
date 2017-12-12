#include <iostream>
using namespace std;

float media_aritmetica(int valores[], int tam, int cont) {
	if (cont == tam-1) return valores[cont]/float(tam);
	
	return (valores[cont]/float(tam)) + media_aritmetica(valores, tam, cont+1);
}

int main() {
	int tam;
	cin >> tam;
	
	int valores[tam];
	for(int i = 0; i < tam; i++) {
		cin >> valores[i];
	}
	
	cout << media_aritmetica(valores, tam, 0) << endl;
	
	return 0;
}

