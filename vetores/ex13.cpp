#include <iostream>
#include <climits>

using namespace std;

int main() {
	unsigned int n;
	int maior = INT_MIN, menor = INT_MAX, posMenor = -1, posMaior = -1;
	int central = -1, posCentral = -1;
	cin >> n;
	
	int valores[n];
	
	for (unsigned int i = 0; i < n; i++) {
		cin >> valores[i];
		if (valores[i] > maior) {
			maior = valores[i];
			posMaior = i;
		}
		
		if (valores[i] < menor) {
			menor = valores[i];
			posMenor = i;
		}
	}
	
	if (n%2 != 0) {
		central = valores[n/2];
		posCentral = n/2;
	}		
	
	cout << maior << endl << menor << endl << central << endl;
	cout << posMaior << endl << posMenor << endl << posCentral << endl;
}
