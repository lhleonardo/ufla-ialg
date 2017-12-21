#include <iostream>
#include <fstream>

using namespace std;

// insertion sort
void ordena(int valores[], int tam) {
	int aux, j;
	for(int i = 1; i < tam; i++) {
		aux = valores[i];
		j = i - 1;
		while(j>=0 and valores[j] > aux) {
			valores[j+1] = valores[j];
			j--;
		}

		valores[j+1] = aux;
	}
}

void grava_no_arquivo(int valores[], int tam) {
	ordena(valores, tam);
	ofstream arquivo("saida.dat", ios::binary);
	arquivo.write((const char *) (&valores), sizeof(int));
	arquivo.close();
}

int main() {
	int tam;
	cin >> tam;

	int valores[tam];
	for(int i = 0; i < tam; i++)
		cin >> valores[i];

	grava_no_arquivo(valores, tam);
}
