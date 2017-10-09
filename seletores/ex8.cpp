#include <iostream>
#include <cfloat>

using namespace std;

int main() {
	
	float valor1, valor2, valor3, valor4;
	float maiorValor, segundoMaior;
	
	cin >> valor1;
	cin >> valor2;
	cin >> valor3; 
	cin >> valor4;
	
	maiorValor= valor1;
    segundoMaior = valor2;
    
    if (valor2 > maiorValor ) {
		segundoMaior = maiorValor;
		maiorValor = valor2;
	}  else if (valor2 > segundoMaior ) {
		segundoMaior = valor2;
	}
		
    if (valor3 > maiorValor) {
		segundoMaior = maiorValor;
		maiorValor = valor3;
    } else if (valor3 > segundoMaior) {
		segundoMaior = valor3;
	}
	
    if (valor4 > maiorValor) {
		segundoMaior = maiorValor ;
		maiorValor  = valor4;
    } else if (valor4 > segundoMaior) {
		segundoMaior = valor4;
	}

	cout << maiorValor << endl;
	cout << segundoMaior << endl;
    
	return 0;
}
