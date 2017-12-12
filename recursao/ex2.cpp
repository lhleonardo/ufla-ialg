#include <iostream>
using namespace std;

int multiplica(int x, int y) {
	if (x == 1) return y;
	
	if (x == 0) return 0;
	
	return y + multiplica(x-1, y);
}

int main()
{
    int x, y;
    
    cin >> x >> y;
    
    cout << multiplica(x, y) << endl;
    
    return 0;
}

