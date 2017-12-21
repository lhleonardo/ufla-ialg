#include <iostream>

using namespace std;

void bubbleSort(int a[], int tam){
	int aux;
	for (int i = tam-1; i >= 1; i--) {
		for ( int j=0; j < i ; j++) {
			if(a[j] > a[j+1]) {
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	int matriz[n][m];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j <m ; j++)
			cin >> matriz[i][j];

	int *vetor;
	vetor = (int *) matriz;
	bubbleSort(vetor, m*n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <m ; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
