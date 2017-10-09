#include <iostream>
#include <math.h>

using namespace std;

int main() {
    // tamanho do degrau em cm
    double degrau; 
    // objetivo de subida do usuário em metros
    double objetivo;
    // resultado anterior
    double previa;
    
    int qtd_degraus = 0;

    cin >> degrau;
    cin >> objetivo;

    previa = (objetivo * 100)/degrau;
    qtd_degraus = ceil(previa);

    cout << qtd_degraus << "\n";

    return 0;
}