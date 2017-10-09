#include <iostream>

using namespace std;

/**
    Faça um programa que receba o número de lados de um polígono convexo, 
    calcule e mostre o número de diagonais desse polígono. 
    
    Sabe-se que NumeroDeDiagonais = [N * (N - 3)] / 2, em que N é o número de lados do polígono.
*/

int main() {
    // declaracao de variaveis
    int lados = 0;
    int diagonais = 0;

    // entrada de dados
    cin >> lados;
    // eh necessario que os lados sejam, no minimo, 3
    if (lados < 3) {
        return -1;
    }   

    // processamento
    diagonais = (lados * (lados - 3))/2;

    // saida
    cout << diagonais << "\n";

    return 0;
}