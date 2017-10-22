#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
	char opcao, unidade_medida;
	
	double angulo, resultado;
	
	cin >> opcao; 
	cin >> unidade_medida;
	cin >> angulo;
	
	switch(opcao) {
		case 's': {
			// calcula o seno
			
			if (fmod(angulo, 90) == 0) {
				resultado = 0;
				break;
			}
			
			if (unidade_medida == 'g') {
				resultado = sin((angulo * M_PI)/180);
			} else if (unidade_medida == 'r') {
				resultado = sin(angulo);
			} else {
				// não sei o que fazer se informar unidade de medida
				// errada
				resultado = -1333334;
			}
			break;
		}
		
		case 'c': {
			// calcula o cosseno
			if (fmod(angulo, 90) == 0) {
				resultado = 0;
				break;
			}
			
			if (unidade_medida == 'g') {
				resultado = cos(angulo * M_PI / 180);
			} else if (unidade_medida == 'r') {
				resultado = cos(angulo);
			} else {
				// não sei o que fazer se informar unidade de medida
				// errada
				resultado = -1333334;
			}
			break;
		}
		
		default: {
			resultado = 0;
			break;
		}
		
		
	}
	cout << resultado << endl;
	return 0;
}
