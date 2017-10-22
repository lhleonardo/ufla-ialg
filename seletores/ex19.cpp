#include <iostream>
#include <sstream> 
#include <cctype> 

using namespace std;

bool isAlpha(string texto) {
	for (unsigned int i = 0; i < texto.length(); i++) {
		if (isalpha(texto[i])) {
			
			return true;
		}
	}	
	return false;
}

int main() {
	string texto;
	cin >> texto;
	
	if (isAlpha(texto)) {
		cout << "erro" << endl;
		return -1;
	}
	
	
	
	if (texto.length() < 5) {
		unsigned int qtdZero = 5 - texto.length();
		for (unsigned int i = 0; i<qtdZero; i++) {
			texto.insert(0, "0");
		}
	} else {
		if (texto.length() > 5) {
			cout << "invalido" << endl;
			return -1;
		}
	}
	
	for (unsigned int i = 0; i < texto.length(); i++) {
		if (i != (texto.length() -1)) {
			cout << texto[i] << "...";
		} else {
			cout << texto[i];
		}
	}
	
	return 0;
}
