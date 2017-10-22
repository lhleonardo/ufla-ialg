#include <iostream>
#include <math.h>

using namespace std;

int main() {
	float altura, resultado; 
	
	cin >> altura;
	
	resultado = (altura + sqrt(pow(altura, 2) + 4))/2.0;
	resultado = log(resultado);
	resultado = 2 * resultado;
	
	cout << resultado;
	
	
	return 0;
}
