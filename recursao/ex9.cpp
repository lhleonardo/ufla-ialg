#include <iostream>
using namespace std;

int h(int x);
int f(int x);

int f(int x) {
	if (x==0) return 1;
	
	if (x>0) {
		if (x%2==0) {
			return 2*h(x) + f(x-1);
		} else {
			return 2*h(x) - f(x-1);
		}
	}
	
	return -1;
}

int h(int x) {
	if (x == 0) return 0;
	
	if (x > 0)
		return h(x-1) + f(x-1);
	
	return -1;
}

int main()
{
	int x;
	cin >> x;
	cout << f(x) << endl;
    return 0;
}

