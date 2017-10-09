#include <iostream>

using namespace std;

int main() {
	
	int numero1, numero2;
	int diferenca;
	
	cin >> numero1 >> numero2;
	
	diferenca = numero1 - numero2;
	
	if (diferenca < 0) 
		diferenca *= -1;
	
	cout << diferenca;
	
	return 0;
}
