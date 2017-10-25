#include <iostream>

using namespace std;

int main() {
	int n1, n2, resultado = 0; 
	
	cin >> n1 >> n2;
	
	while (n2 > 0) {
		resultado += n1;
		cout << resultado << endl;
		n2--;
	}
	
	
	return 0;
}
