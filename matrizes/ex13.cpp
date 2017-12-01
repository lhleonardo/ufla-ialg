#include <iostream>

using namespace std;

int main() {
	string texto;
	string busca;

	cin >> texto;
	cin >> busca;

	//if (texto.length() < busca.length()) {
		
		//cout << "-1" << endl;
		//return 0;
	//}

	//if (texto.length() == busca.length()) {
		//bool identico = true;

		//for(unsigned int i = 0; i < texto.length() and identico; i++)
			//if (texto[i] != busca[i])
				//identico = false;
				
		//if (not identico) {
			//cout << "-1" << endl;
			//return 0;
		//} else {
			//cout << "0" << endl;
			//return 0;
		//}
	//}

	unsigned int auxEncontrado = 0, qtdEncontrado = 0;
	int posEncontrado = -1;
	
	
	for(unsigned int i = 0; i < texto.length() and qtdEncontrado != busca.length(); i++) {
		if (texto[i] != busca[auxEncontrado]) {
			posEncontrado = -1;
			auxEncontrado = 0;
			qtdEncontrado = 0;
		}
		if (texto[i] == busca[auxEncontrado]) {
			auxEncontrado++;
			qtdEncontrado++;
			if (posEncontrado == -1)
				posEncontrado = i;
		} 
	}

	if (posEncontrado == -1) {
		cout << "-1" << endl;
		return 0;
	}

	cout << posEncontrado << endl;
	
	return 0;
}
