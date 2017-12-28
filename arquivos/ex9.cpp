#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string valores_a[100], valores_b[100];

    ifstream arquivo_a("arquivoA.txt");
    ifstream arquivo_b("arquivoB.txt");

    int cont_a = 0, cont_b = 0;

    string leitura;
    while(arquivo_a >> leitura and cont_a < 100) {
        valores_a[cont_a++] = leitura;
    }

    while(arquivo_b >> leitura and cont_b < 100) {
        valores_b[cont_b++] = leitura;
    }

    int tamanho = cont_a + cont_b, cont_c = 0;
    string valores_c[tamanho];

    int i = 0, j = cont_b - 1;

    bool flag = true;
    
    while(cont_c < tamanho) {
        if (flag and i < cont_a) {
            valores_c[cont_c] = valores_a[i];
            i++;
        }

        if (not flag and j >= 0){
            valores_c[cont_c] = valores_b[j];
            j--;
        }
        cont_c++;
        flag = not flag;
    }

    for (int i = 0; i < cont_c; i++) {
        cout << valores_c[i] << " ";
    }
    

    return 0;
}
