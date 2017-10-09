#include <iostream>

using namespace std;

int main() {
	int lado1, lado2, lado3;
	
	cin >> lado1;
	cin >> lado2;
	cin >> lado3;
	
	// o comprimento do lado eh menor que a soma dos outros dois
	if ((lado1 < (lado2 + lado3)) or
		(lado2 < (lado1 + lado3)) or
		(lado3 < (lado1 + lado2))) {
			// equilatero
			if ((lado1 == lado2) and
				(lado2 == lado3) and
				(lado3 == lado1)) {
					
				cout << "equilatero" << endl;	
			} else if ((lado1 == lado2) or
						(lado2 == lado3) or
						(lado3 == lado1)) {
				
				cout << "isosceles" << endl;
				
			} else if ((lado1 != lado2) and
						(lado2 != lado3) and
						(lado3 != lado1)) {
							
				cout << "escaleno" << endl;
			} else {
				cout << "-1" << endl;
			}
			
	} else {
		cout << "-1" << endl;
	}
	
	return 0;
}
