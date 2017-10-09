#include <iostream>

using namespace std;

/*
    Escreva um programa que receba 3 numeros e calcule a media aritmetica desses numeros.
    Se a media apresentar algum valor decimal, ela devera ter suas casas decimais desprezadas. 
*/

int main() {
    int n1 = 0, n2 = 0, n3 = 0;
    int media = 0;
    
    // entrada dos dados direta, sem mensagem
    cin >> n1;
    cin >> n2;
    cin >> n3;

    // processamento 
    media = (n1 + n2 + n3) / 3;

    // saida
    cout << media << "\n";

    return 0;
}