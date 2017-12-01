#include <iostream>

using namespace std;

int main() {
	int tam;

	cin >> tam;

	char valores[tam];

	for(int i = 0; i < tam; i++)
		cin >> valores[i];

	char desejado;
	bool encontrado = false;
	
	cin >> desejado;

	for(int i = 0; i < tam; i++) {
		if (valores[i] == desejado) {
			encontrado = true;
			cout << i << " ";
		}

	}

	if (not encontrado)
		cout << "-1" << endl;
	else
		cout << endl;
		
	return 0;
}
