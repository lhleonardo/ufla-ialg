#include <iostream>

using namespace std;

int main() {
    // variaveis de entrada
    double baseMaior, baseMenor, altura;
    double resultado;

    cin >> baseMaior >> baseMenor >> altura;

    resultado = ((baseMaior + baseMenor) * altura)/2;

    cout << resultado << "\n";

    return 0;
}