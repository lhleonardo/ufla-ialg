#include <iostream>

using namespace std;

int MIN(int a, int b, int c) {
	int menor = a;

	if (b < menor)
		menor = b;

	if (c < menor)
		menor = c;

	return menor;
	
}

int f(int n) {
	if (n <= 3) return n;

	return MIN(f(n-1), f(n-2), f(n-3))+1;
}

int main() {

	int numero;
	cin >> numero;

	cout << f(numero) << endl;

	return 0;
}
