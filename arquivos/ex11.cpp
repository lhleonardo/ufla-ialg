#include <iostream>
#include <fstream>

using namespace std;

bool primo(int numero) {
    bool resultado = true;

    for(int i = 2; i < numero and resultado; i++) {
        if (numero % i == 0)
            resultado = false;
    }
    
    return resultado;
}

int main() {
    string arquivo_entrada;
    cin >> arquivo_entrada;

    ifstream leitor(arquivo_entrada.c_str());

    int leitura;
    int menor, segundo_menor;
    int soma = 0;
    
    if (leitor) {
        leitor >> leitura;

        if (!primo(leitura)) {

            menor = leitura;
            segundo_menor = leitura;

            // primeiro elemento
            soma += leitura;
            
            while(leitor >> leitura and not primo(leitura)) {
                if (leitura < menor) {
                    segundo_menor = menor;
                    menor = leitura;
                }
                soma+=leitura;
            }

            // o primo deve ser somado.
            soma += leitura;

            soma -= menor;
            soma -= segundo_menor;
        } else {
            // o primeiro numero eh um primo, entao deve parar
            menor = -1;
            segundo_menor = -1;
            soma = -1;
        }
        string arquivo_saida;
        leitor >> arquivo_saida;
        
        ofstream gravador(arquivo_saida.c_str());
        if (soma < 0) soma = 0;
        if (menor >= 0)
            gravador << menor << " " << segundo_menor << " " << soma << endl;
        gravador.close();
    }


    leitor.close();
    
    return 0;
}
