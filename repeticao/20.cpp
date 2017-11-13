#include <iostream>
#include <cmath>

using namespace std;

int main(){
		int N, potencia;
		double a = 0, produto = 1;		
				
		cin >> N;
				
		for(int cont = 1; cont <= N; cont++){
				
			a = sqrt(2+a);

			produto = produto * a;
		}
		
		potencia = pow(2, N); 			
		
		cout << 2/(produto/potencia);
		
		return 0;
}
