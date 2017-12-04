#include <iostream>
#include <climits> 

using namespace std;

int qtdDigitos(int valor) {
	int qtd = 0;
	
	while(valor > 0) {
		valor/=10;
		qtd++;
	}
	
	return qtd;
}

void converte(int numero, int tam, int numeros[]) {
	int cont = tam-1;
	
	while(numero > 0) {
		numeros[cont] = numero % 10;
		numero /=10;
		cont--;
	}
}

bool isCapicua(int numero) {
	int tam = qtdDigitos(numero);
	bool capicua = true;
	int valores[tam];
	
	converte(numero, tam, valores);
	
	for(int i = 0; (i < (tam/2)) and capicua; i++) 
		if (valores[i] != valores[(tam-1)-i])
			capicua = false;
	
	return capicua;
}

void maiorMenor(int valores[], int tam, int &maior, int &menor) {
	maior = INT_MIN;
	menor = INT_MAX;
	
	for(int i = 0; i < tam; i++) {
		if (valores[i] > maior) 
			maior = valores[i];
		if (valores[i] < menor) 
			menor = valores[i];
	}
	
	if (maior == INT_MIN)
		maior = 0;
		
	if (menor == INT_MAX)
		menor = 0;
	
}

int main() {
    int tam; 
    
    cin >> tam;
    
    int valores[tam], capicuas[tam], normais[tam];
    int contCapicua = 0, contNormais = 0;
    
    for(int i = 0; i < tam; i++) {
		cin >> valores[i];
		if (isCapicua(valores[i])) {
			capicuas[contCapicua] = valores[i];
			contCapicua++;
		} else {
			normais[contNormais] = valores[i];
			contNormais++;
		}
	}
	
	for(int i = 0; i < contNormais; i++) 
		cout << normais[i] << endl;
    
    int maior = 0, menor = 0;
    
    maiorMenor(capicuas, contCapicua, maior, menor);
    
    cout << menor << endl;
    cout << maior << endl;
    
    return 0;
}

