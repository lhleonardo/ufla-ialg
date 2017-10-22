#include <iostream>

using namespace std;


int main() {
	int cargo, percentual = 0;
	float salario, aumento, novoSalario;
	
	bool erro = false;
	
	cin >> cargo;
	cin >> salario;
	
	if (salario >= 0) {
		// analisa, escreve e define o desconto para os cargos
		switch (cargo) {
			case 1: {
				cout << "Escrituario" << endl;
				percentual = 50;
				break;
			}
			case 2: {
				cout << "Secretario" << endl;
				percentual = 35;
				break;
			}
			case 3: {
				cout << "Caixa" << endl;
				percentual = 20;
				break;
			}
			case 4: {
				cout << "Gerente" << endl;
				percentual = 10;
				break;
			}
			case 5: {
				cout << "Diretor" << endl;
				percentual = 0;
				break;
			}
			default: {
				erro = true;
				break;
			}
		}
		// valor fora do intervalo 1-5
		if (erro) {
			return -1;
		}
		
	} else {
		// salario negativo
		return -1;
	}
	
	// calcula o aumento e define o novo salario
	aumento = (salario * percentual)/100.0;
	novoSalario = salario + aumento;
	
	cout << aumento << endl;
	cout << novoSalario << endl;
	
	return 0;
}
