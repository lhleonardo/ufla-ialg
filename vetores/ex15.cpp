#include <iostream>

using namespace std;

int main() {
	int logica[15], estrutura[10];
	
	for (int i = 0; i < 15; i++) {
		cin >> logica[i];
	}
	
	for (int i = 0; i < 10; i++){
		cin >> estrutura[i];
	}
	
	//cout << endl;
	for (int i = 0; i < 15; i++){
		bool encontrou = false;
		for (int j = 0; j < 10 and not encontrou; j++){
			if (logica[i] == estrutura[j]) {
				cout << logica[i] << endl;
				encontrou = true;
			}
		}
	}
	
	return 0;
}
