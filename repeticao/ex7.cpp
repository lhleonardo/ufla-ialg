#include <iostream>

using namespace std;

int main() {
	int divisor, quociente, numero; 
	
	cin >> divisor;
	
	bool encontrou = false;
	
	while (not encontrou) {
		cin >> numero;
		if (numero % divisor == 2) {
			encontrou = true;
			quociente = numero / divisor;
		}
	}
	
	cout << quociente << endl;
	
	return 0;
}
