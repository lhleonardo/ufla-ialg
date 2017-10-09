#include <iostream>
#include <math.h>

using namespace std;

/**
    Faça um programa que calcula a distância entre dois pontos no plano cartesiano.

    Entrada:

        Número real da coordenada x do primeiro ponto.
        Número real da coordenada y do primeiro ponto.
        Número real da coordenada x do segundo ponto.
        Número real da coordenada y do segundo ponto.

    Saída

        Número real representando a distância entre os pontos.

**/

int main() {
    double x1 = 0.0, x2 = 0.0;
    double y1 = 0.0, y2 = 0.0;

    double distancia = 0.0;

    // entrada de dados
    cin >> x1;
    cin >> y1; 
    cin >> x2; 
    cin >> y2;

    // processamento
    distancia = pow(x2-x1, 2) + pow(y2-y1, 2);
    distancia = sqrt(distancia);

    //saída
    cout << distancia << "\n";

    return 0;
}