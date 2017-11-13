#include <iostream>

using namespace std;

int main() {
	int t1, t2;
	cin >> t1 >> t2;
	
	int primeiro[t1], segundo[t2];
	
	for (int i = 0; i < t1; i++) {
		cin >> primeiro[i];
	}
	
	for (int i = 0; i < t2; i++) {
		cin >> segundo[i];
	}
	
	bool peloMenosUmaIntersecao = false;
	
	for (int i = 0; i < t1; i++) {
		bool encontrou = false;
		for (int j = 0; j < t2 and not encontrou; j++) {
			if (primeiro[i] == segundo[j]) {
				cout << primeiro[i] << endl;
				encontrou = true;
				peloMenosUmaIntersecao = true;			
			}
		}
		
	}
	
	if (not peloMenosUmaIntersecao) {
		cout << "-1" << endl;
	}
		
	return 0;
}
