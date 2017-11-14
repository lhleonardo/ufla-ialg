#include <iostream>

using namespace std;

int main() {
	int linha, coluna;

	cin >> linha >> coluna;

	int matriz[linha][coluna];

	for (int i = 0; i < linha; i++) {
		for (int j = 0; j < coluna; j++) {
			cin >> matriz[i][j];
		}
	}

	for(int i = 0; i < coluna; i++) {
		for (int j = 0; j < linha; j++) {
			cout << matriz[j][i] << " ";
		}
		cout << endl;
	}

	return 0;
}
