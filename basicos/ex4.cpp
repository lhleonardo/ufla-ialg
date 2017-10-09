#include <iostream>

/**
    Faça um algoritmo que leia a idade de uma pessoa expressa em 
    anos e mostre essa idade em meses, semanas e dias, respectivamente
*/

int main() {
    
    int idade = 0;
    int semanas = 0, meses = 0, dias = 0;

    // entrada dos dados
    // std::cout << "Conversor de Idades!\n";
    // std::cout << "Informe a idade expressa em anos: ";
    std::cin >> idade;

    // processamento 
    semanas = idade * 48;
    meses = idade * 12;
    dias = meses * 30;

    // saida
    std::cout << meses << "\n";
    std::cout << semanas << "\n";
    std::cout << dias << "\n";
    
    return 0;
}