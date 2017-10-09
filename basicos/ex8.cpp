#include <iostream>

/**
    Faça um programa que receba o raio de uma esfera, calcule e mostre:

        a) o diâmetro da esfera; sabe-se que: D = 2R ;
        b) a área da superfície da esfera; sabe-se que: A = 4πR2 ;
        c) o volume da esfera; sabe-se que: V = 4πR3 / 3 . 

    Obs.: Adote o valor de π como sendo igual a 3,14.

**/

using namespace std;

int main() {
    const double PI = 3.14;
    double raio = 0.0;
    double diametro = 0.0, area = 0.0, volume = 0.0;
    
    // entrada dos dados
    cin >> raio;

    //processamento
    diametro = raio * 2;
    area = 4 * PI * (raio * raio);
    volume = (4 * PI * (raio *raio * raio)) / 3;

    // saida
    cout << diametro << "\n";
    cout << area << "\n";
    cout << volume << "\n";

    return 0;
}