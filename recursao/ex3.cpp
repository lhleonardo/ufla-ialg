#include <iostream>
using namespace std;

void imprime(int num, int pos) {
	if (num-pos == num) {
		cout << num;
		return;
	}
	cout << (num - pos) << " ";
	imprime(num, pos-1);
}

int main()
{
	int num;
	cin >> num;
	
	imprime(num, num);
	
    return 0;
}

