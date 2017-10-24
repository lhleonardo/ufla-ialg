#include <iostream>

using namespace std;

int main() {
	float horaExtra, horaFalta; 
	float horaTotal;
	float premio;
	
	cin >> horaExtra >> horaFalta;
	
	if (horaExtra < 0 or horaFalta < 0) {
		return -1;
	}
	
	horaTotal = horaExtra - ((2.0/3.0) * horaFalta);
	
	if (horaTotal <= 600) {
		premio = 100.0;
	} else if (horaTotal > 600 and horaTotal <=1200) {
		premio = 200.0;
	} else if (horaTotal > 1200 and horaTotal <= 1800) {
		premio = 300.0;		
	} else if (horaTotal > 1800 and horaTotal <= 2400) {
		premio = 400.0;
	} else if (horaTotal > 1400) {
		premio = 500.0;
	} else {
		return -1;
	}
	
	cout << premio << endl;
	
	return 0;
}
