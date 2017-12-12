#include <iostream>
using namespace std;

int ricci(int a, int b, int ordem) {
	if (ordem == 0) return a;
	if (ordem == 1) return b;

	return ricci(a, b, ordem-1) + ricci(a, b, ordem-2);
}

int main()
{
    int ordem, a, b;
    
    cin >> a >> b >> ordem;
    
    for(int i = 0; i < ordem; i++) {
		cout << ricci(a, b, i) << " ";
	}
    
    return 0;
}

