#include <iostream>

using namespace std;

int sucessor(int x) {
	x++;
	return x;
}

int antecessor(int x) {
	x--;
	return x;
}

int soma(int x, int y) {
	if (y >=0) {
		if (y == 0) return x;	
		return soma(sucessor(x), antecessor(y));
	} else {
		if (x == 0) return y;
		return soma(antecessor(x), sucessor(y));
	}
}

int main() {
	int x, y;
	
	cin >> x >> y;
	
	cout << soma(x, y) << endl;
	
	return 0;
}

