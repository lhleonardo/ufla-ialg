#include <iostream>

using namespace std;

int main() {
	int numero, resultado = 1;
	
	cin >> numero;
	
	while(numero >= 1) {
		resultado *= numero;
		numero--;
	}
	
	cout << resultado << endl;	
	
	return 0;
}
