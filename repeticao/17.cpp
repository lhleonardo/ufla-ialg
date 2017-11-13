#include <iostream>
#include <math.h>

using namespace std;

int main(){
	double angulo, raio, x, y, qtdCadeiras, angulo2 = 0;
	
	cin >> raio >> qtdCadeiras;
	
	angulo = (2 * M_PI)/qtdCadeiras;
	
	for(int cont = 1; cont <= qtdCadeiras; cont++){
		x = (cos(angulo2)) * raio;
		y = (sin(angulo2)) * raio;
		
		angulo2 = angulo2 + angulo;
		
		cout << x << " " << y << endl;
	}
}
