#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

/**
    Implemente um programa que receba um número que represente o tempo em milissegundos 
    que se passou desde as 00 : 00 : 00 (HORAS : MINUTOS : SEGUNDOS) horas de um dia. 

    O seu programa deve imprimir na saída padrão a hora representada por este número de milissegundos.

    Exemplo de Entrada:
        3600000

    Exemplo de Saída:
        1 : 0 : 0.0

**/

int main() {
    int ms = 0;
    int hora = 0, minuto = 0;
    double segundo = 0.0;

    cin >> ms;

    hora = ms / 3600000;
    ms = ms % 3600000;
    minuto = ms / 60000;
    ms = ms % 60000;
    segundo =  ms / 1000.0;

    printf(" %d : %d : %.2f \n", hora, minuto, segundo);

    return 0;
}