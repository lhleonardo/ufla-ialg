#include <iostream>
#include <climits>

using namespace std;

int main() {
	int ordem;
	
	cin >> ordem;

	int matriz[ordem][ordem];
	int menorValor = INT_MAX, linhaMenor = -1;

	for (int i = 0; i < ordem; i++) {
		for (int j = 0; j < ordem; j++) {
			cin >> matriz[i][j];
			if (matriz[i][j] < menorValor) {
				menorValor = matriz[i][j];
				linhaMenor = i;
			}
		}
	}

	cout << linhaMenor << endl;

	return 0;
}
