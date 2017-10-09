#include <iostream>

using namespace std;

int main() {

    // notas
    double n1, n2, n3, resultado;
    // pesos
    int p1, p2, p3;

    cin >> n1 >> n2 >> n3;
    cin >> p1 >> p2 >> p3;

    resultado = (n1*p1 + n2*p2 + n3*p3) / (p1 + p2 + p3);

    cout << resultado << "\n";
    
    return 0;
}