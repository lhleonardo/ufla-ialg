#include <iostream>

using namespace std;

/* 
    Faça um programa que calcula a área de um retângulo.

    Entradas:

        A largura do retângulo (um número real).
        A altura do retângulo (um número real).

    Saída:

        A área do retângulo (um número real).

*/
int main () {
    double largura = 0.0;
    double altura = 0.0;
    double area = 0.0;

    // cout << "Calculadora de areas do retangulo!\n";
    
    // cout << "Informe a largura do retangulo: ";
    cin >> largura;
    // cout << "Informe a altura do retangulo: ";
    cin >> altura;

    area = altura * largura;

    // cout << "A area do triangulo eh: " << area << "\n";
    cout << area << "\n";

    return 0;
}