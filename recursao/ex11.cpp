#include <iostream>
using namespace std;

float H(int n) {
	if (n == 1) return 1;
	
	return (1/float(n))+H(n-1);
}

int main() {
	
	int m;
	cin >> m;
	
	float valores[m][m];
	int ordem = 1;
	float principal = 0, secundaria = 0;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++) {
			valores[i][j] = H(ordem);
			ordem++;
			
			if (i == j)
				principal += valores[i][j];
			
			if (i+j == m-1)
				secundaria += valores[i][j];
		}
	
	float diagonal = secundaria - principal;
	
	cout << diagonal << endl;
	
	return 0;
}

