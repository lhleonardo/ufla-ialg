#include <iostream>
using namespace std;

double phi(int n) {
	if (n == 1) return 1; 
	
	return 1 + 1/phi(n-1);
}

int main()
{
    int tam;
    cin >> tam;
    
    double resultado = phi(tam);
    
    cout << resultado << endl;
    
    return 0;
}


