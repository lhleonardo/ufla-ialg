#include <iostream>

using namespace std;

int main() {
	unsigned int n1 = 1;
	unsigned int n2;
	
	do {
		n2 = 1;
		do {
			cout << n1 << " x " << n2 << " = " << (n1 * n2) << endl;			
			n2++;
		} while(n2 <=10);
		n1++;
	} while(n1 <=10);
	return 0;
}
