#include <iostream>

using namespace std;

int main() {
	string palavra;
	int vogais = 0;
	
	cin >> palavra;
	
	for (unsigned int i = 0; i < palavra.length(); i++){
		if (palavra[i] == 'a' or palavra[i] == 'e' or palavra[i] == 'i'
			or palavra[i] == 'o' or palavra[i] == 'u') {
			vogais++;
		}
	}
	
	cout << vogais << endl;
	return 0;
}
