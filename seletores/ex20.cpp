#include <iostream>

using namespace std;

int main(){
	double x1, y1, x2, y2, a, b, x, y;
	char letra;
		
	cin >> x1 >> y1 >> x2 >> y2 >> letra;
		
	a = (y2 - y1)/(x2 - x1);
	b = y1 - (x1 * a);
		
	if (letra == 'x'){
		cin >> x;
		y = (a * x) + b;
		
		if ((x1 == x2) && x > (x1 - x2)){
			cout << "nenhuma";
		} else if ((x >= x1) && (x <= x2)){
			cout << y1;
		} else {
			cout << y;
		}
	} else if (letra == 'y'){
		cin >> y;
		x = (y - b)/a;
		
		if ((y1 == y2) && y > (y1 - y2)){
			cout << "nenhuma";
		}else if ((y >= y1) && (y <= y2)){
			cout << x1;
		} else {
			cout << x;
		}
	}
}
