#include <iostream>

using namespace std;

int main() {
	unsigned int hora, minuto;
	unsigned int total;
	
	cin >> hora;
	cin >> minuto;
	
	total = hora * 60;
	cout << total << endl;
	
	total += minuto;
	cout << total << endl;
	
	total *= 60;
	cout << total << endl;
		
	return 0;
}
