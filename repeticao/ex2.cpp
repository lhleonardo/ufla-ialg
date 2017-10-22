#include <iostream>

using namespace std;

int main() {
	unsigned int qtdIngressos, i = 1;
	unsigned int ingressoSorteado = 0;
	unsigned int ingressoAtual;
	
	cin >> qtdIngressos;
	
	while(i <= qtdIngressos) {
		cin >> ingressoAtual;
		if (ingressoAtual == i && ingressoSorteado == 0) {
			ingressoSorteado = ingressoAtual;	
		}
		i++;
	}
	
	cout << ingressoSorteado << endl;
	
	return 0;
}
