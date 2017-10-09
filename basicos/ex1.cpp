#include <iostream>

/**
* Faça um programa que receba o valor do salário de um funcionario em reais e
* converta esse valor para Dolar, Euro e Libra. 
*
* Adote: 
*	1 dolar: 2.13 reais
*	1 euro: 2.84
*	1 libra: 3.34
*
*/

using namespace std;

int main() {
	const double dolar = 2.13;
	const double euro = 2.84;
	const double libra = 3.34;
	double salario = 0.0;

	cout << "Conversor de Moedas!\n";
	cout << "Informe o valor do funcionario em reais: ";
	cin >> salario;

	cout << (salario / dolar) << "\n";
	cout << (salario / euro) << "\n";
	cout << (salario / libra) << "\n";
		
	return 0;
}
