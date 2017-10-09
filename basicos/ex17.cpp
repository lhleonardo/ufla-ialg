#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int produto;
    int caixa;

    cin >> produto;

    caixa = ceil(produto/6.0);

    cout << caixa << "\n";

}
