#include <iostream>

using namespace std;

int main() {
	
	int n ;
	int triangular;
	int i = 1;
	int ultimo = 0;
	
	cin >> n;
		
	if (n >=0 ) { 
		do {
			ultimo += i;
			if ( i == (n-1)){
				triangular = ultimo;
			}
			i++;
		}while(i<=n);
		
		cout << (n + triangular) << endl;
	} else {
		return -1;
	}
	
	return 0;
	
}
