#include <iostream>

using namespace std;

int main() {
	float operando1, operando2;
	char operacao;
	
	cin >> operando1;
	cin >> operacao;
	cin >> operando2;
	
	switch (operacao) {
		case '+': 
			cout << (operando1 + operando2) << endl;
			break;
		case '-': 
			cout << (operando1 - operando2) << endl;
			break;
		case '*':
			cout << (operando1 * operando2) << endl;
			break;
		case '/': 
			if (operando2 != 0)
				cout << (operando1 / operando2) << endl;
			else 
				cout << "erro" << endl;
			break;
	}
	
	return 0;
}
