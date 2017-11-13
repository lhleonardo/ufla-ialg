#include <iostream>

using namespace std;

int main(){
	int num1, num2, ciclo = 1, cicloMaior = 1, N, auxNum1;
	
	cin >> num1 >> num2;
	
	N = num1;
	
	while(num2 >= num1){
		auxNum1 = num1;
		num1++;
		
		while(auxNum1 != 1){
			if(auxNum1 % 2 ==0){
				auxNum1 = auxNum1 / 2;
				ciclo++;
			} else {
				auxNum1 = (auxNum1 * 3) +1;
				ciclo++;
			}
		} 
		if(ciclo > cicloMaior){
			cicloMaior = ciclo;
		}
		ciclo = 1;
	}
	cout << N << endl;
	cout << num2 << endl;
	cout << cicloMaior;
	
}
