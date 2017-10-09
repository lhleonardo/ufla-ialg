#include <iostream>

using namespace std;

int main() {
	unsigned int dia, hora, minuto, duracao;
	
	cin >> dia;
	cin >> hora;
	cin >> minuto;
	cin >> duracao;
	
	dia += duracao / 1440;
	duracao = duracao % 1440;
	
	hora += duracao / 60;
	duracao = duracao % 60;
	
	if (hora > 23) {
		hora -= 24;
		dia++;
	}	
	
	minuto += duracao;
	
	if (minuto > 59) {
		minuto-= 60;
		hora++;
		if (hora > 23) {
			hora -= 24;
			dia++;
		}
	}
	
	cout << dia << endl;
	cout << hora << endl;
	cout << minuto << endl;
	
	
	return 0;
}
