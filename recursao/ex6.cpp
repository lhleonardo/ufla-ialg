#include <iostream>

using namespace std;

int T(int discos) {
	if (discos == 1) return 1;

	return (2 * T(discos-1)) + 1;
}

int main() {
	int discos;

	cin >> discos;

	cout << T(discos) << endl;

	return 0;
}
