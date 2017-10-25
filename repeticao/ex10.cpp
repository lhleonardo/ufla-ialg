#include <iostream>

using namespace std;

int main() {
	int limite, sequencia;
	unsigned int a = 0, b = 1;
	
	cin >> limite;
	
	if (limite < 0) {
		return 0;
	}
	
	switch(limite) {
		case 0: {
			break;
		}
		case 1: {
			cout << a << endl;
			limite--;
			break;
		} 
		case 2: {
			cout << a << endl;
			cout << b << endl;
			limite--;
			limite--;
			break;
		}
		default: {
			cout << a << endl;
			cout << b << endl;
			limite--;
			limite--;
			break;
		}
		
		
	}
	
	for (int i = 0; i < limite; i++) {
		sequencia = (a + b);
		cout << sequencia << endl;
		a = b;
		b = sequencia;
	}
		
}
