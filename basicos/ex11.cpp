#include <iostream>

using namespace std;

/**
    Entradas:

        Valor que o cliente entrega ao funcionário (inteiro),
        Valor total da compra (inteiro).

    Saídas:

        Quantidade de notas de 20, 10, 5, 2 e 1 (respectivamente) necessárias para o troco.

**/

int main() {
    int total = 0; 
    int pago = 0;
    int troco = 0;

    int qtd_vinte = 0, qtd_dez = 0, qtd_cinco = 0, qtd_dois = 0, qtd_um = 0;

    // entrada de dados
    cin >> pago;
    cin >> total;
    troco = pago - total;

    // processamento
    while (troco > 0) {
        if (troco >= 20) {
            troco -= 20;
            qtd_vinte++;
            continue;
        }
        if (troco >= 10) {
            troco -= 10; 
            qtd_dez++;
            continue;
        }
        if (troco >=5) {
            troco -= 5;
            qtd_cinco++;
            continue;
        }
        if (troco >=2) {
            troco -=2;
            qtd_dois++;
            continue;
        }
        if (troco >=1) {
            troco -=1;
            qtd_um++;
            continue;
        }
    }
    // saida dos dados
    cout << qtd_vinte << "\n";
    cout << qtd_dez << "\n";
    cout << qtd_cinco << "\n";
    cout << qtd_dois << "\n";
    cout << qtd_um << "\n";

    return 0;
}