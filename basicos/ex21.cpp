#include <iostream>

using namespace std;

int main() {
	float x1, y1, x2, y2;
	
	float coeficiente_angular_m;
	float coeficiente_linear_q;
	
	cin >> x1;
	cin >> y1; 
	cin >> x2;
	cin >> y2;
	
	coeficiente_angular_m = (y2 - y1)/(x2 - x1);
	coeficiente_linear_q = y1 - (coeficiente_angular_m * x1);
	
	cout << coeficiente_angular_m << endl;
	cout << coeficiente_linear_q << endl;
	
	return 0;
}

