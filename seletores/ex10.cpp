#include <iostream>

using namespace std;

void imprime(int dia, int mes, int ano) {
	cout << dia << " " << mes << " " << ano << endl;
}

int main() {
	unsigned int dia1, mes1, ano1;
	unsigned int dia2, mes2, ano2;
	
	cin >> dia1 >> mes1 >> ano1;
	cin >> dia2 >> mes2 >> ano2;
	
	if (ano1 > ano2) {
		// ano 1 eh o maior
		imprime(dia1, mes1, ano1);
		
	} else if (ano1 == ano2) {
		// anos iguais, vai pro mes		
		if (mes1 > mes2) {
			// mes 1 eh maior
			imprime(dia1, mes1, ano1);
		} else if (mes1 == mes2) {
			// meses iguais, vai pra dia
			if (dia1 > dia2) {
				// dia 1 eh o maior
				imprime(dia1, mes1, ano1);
			} else if (dia1 == dia2) {
				// dias iguais?????????? 
				// imprime o proprio dia soh pra nao deixar sem nada
				imprime(dia1, mes1, ano1);
			} else {
				// dia 2 eh o maior
				imprime(dia2, mes2, ano2);
			}
		} else {
			// mes 2 eh maior
			imprime(dia2, mes2, ano2);
		}
			
	} else {
		// ano 2 eh o maior
		imprime(dia2, mes2, ano2);
	}
	
	return 0;
}
