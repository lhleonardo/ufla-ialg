#include <iostream>
#include <vector>

using namespace std;

int main() {
    int valor; 
    int qtd_cem = 0, qtd_cinquenta = 0, qtd_vinte = 0, qtd_dez = 0, 
        qtd_cinco = 0, qtd_dois = 0, qtd_um = 0;
    cin >> valor;

    while (valor > 0) {
        if (valor >= 100) {
            valor -= 100;
            qtd_cem++;
            continue;
        }
        if (valor >= 50) {
            valor -= 50;
            qtd_cinquenta++;
            continue;
        }
        if (valor >= 20) {
            valor -= 20;
            qtd_vinte++;
            continue;
        }
        if (valor >= 10) {
            valor -= 10; 
            qtd_dez++;
            continue;
        }
        if (valor >=5) {
            valor -= 5;
            qtd_cinco++;
            continue;
        }
        if (valor >=2) {
            valor -=2;
            qtd_dois++;
            continue;
        }
        if (valor >=1) {
            valor -=1;
            qtd_um++;
            continue;
        }
    }
    // saida dos dados
    cout << qtd_cem << "\n";
    cout << qtd_cinquenta << "\n";
    cout << qtd_vinte << "\n";
    cout << qtd_dez << "\n";
    cout << qtd_cinco << "\n";
    cout << qtd_dois << "\n";
    cout << qtd_um << "\n";

    return 0;
}

