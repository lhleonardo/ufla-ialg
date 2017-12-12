#include <iostream>

using namespace std;

bool procura(int vetor[], int tam, int procurado) {
	
	for (int i = 0; i < tam; i++)
		if (vetor[i] == procurado)
			return true;
	
	return false;
}

int main() {
	int tam;
	cin >> tam;
	
	int valores[tam];
	
	for(int i = 0; i < tam; i++) 
		cin >> valores[i];
		
	int x;
	cin >> x;
	
	cout << procura(valores, tam, x) << endl;
	return 0;
}
