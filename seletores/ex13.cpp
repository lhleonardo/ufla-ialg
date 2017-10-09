#include <iostream>
#include <cfloat>

using namespace std;

int main() {
	float numeroLido, maiorValor = FLT_MIN;
	
	for (unsigned int i = 0; i < 3; i++) {
		cin >> numeroLido;
		
		if (numeroLido > maiorValor) {
			maiorValor = numeroLido;
		}
	}
	
	cout << maiorValor << endl;
	
	return 0;
}
