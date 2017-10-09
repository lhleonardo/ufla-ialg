#include <iostream>

using namespace std;

int main() {
    int numero, divisor, resto, qtd;

    cin >> numero;
    cin >> divisor;

    if (divisor == 0) {
        cout << -1 << endl;
        return 0;
    }

    if (divisor > numero ) {
        cout << -1 << endl;
        return 0;
    }


    for (qtd = 0; numero >= divisor; qtd++){
        resto = numero - divisor;
        numero = resto;
        cout << numero << endl;
    }

    cout << qtd << endl;  

    return 0;
}