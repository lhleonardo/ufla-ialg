#include <iostream>

using namespace std;

int fibo(int ordem) {
	if (ordem == 0) return 0;
	if (ordem == 1) return 1;

	return fibo(ordem-1) + fibo(ordem-2);
}

int main() {

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cout << fibo(i) << " ";

	return 0;
}
