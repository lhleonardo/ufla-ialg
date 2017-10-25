#include <iostream>

using namespace std;

int main() {
	int n, i=1, soma = 0;
	
	cin >> n;
	
	while (i <= n) {
		if (n % i == 0) {
			
			cout << i;
			if (i == n) {
				cout << "=";
			} else {
				cout << "+";
			}
			soma += i;
		}
		i++;
	}
	
	cout << soma << endl;
	
	
	return 0;
}
