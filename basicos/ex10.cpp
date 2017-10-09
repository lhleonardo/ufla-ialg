#include <iostream>

using namespace std;

/**
    Um fabricante produz e embala seus produtos dois a dois. Recentemente ele começou a experimentar a 
    venda dos produtos em embalagens de luxo, para presente, com preço maior.

    Uma pesquisa de mercado estimou que existe demanda para 1/3 da sua produção distribuídos em
    embalagens de luxo. O fabricante então adaptou a linha de produção de tal forma que duas embalagens 
    comuns são usadas, depois uma de luxo, depois mais duas comuns, depois mais uma de luxo e assim por
    diante.

    Faça um programa que dada a quantidade de produtos, informe quantos foram distribuídos em embalagens 
    comuns e quantos foram distribuídos em embalagens de luxo.

    Entradas:

        O número de produtos produzidos (um número inteiro, positivo).

    Saídas:

        O número de produtos distribuídos em embalagens comuns (número inteiro).
        O número de produtos distribuídos em embalagens de luxo (número inteiro).

*/

int main() {
    int qtd = 0;
    int qtd_luxo = 0;
    int qtd_comum = 0;

    // entrada de dados
    cin >> qtd;

    // processamento de dados
    qtd_luxo = (int) ((qtd/3) + 0.5);
    qtd_comum = qtd - qtd_luxo;

    cout << qtd_comum << "\n";
    cout << qtd_luxo << "\n";

    return 0;
}