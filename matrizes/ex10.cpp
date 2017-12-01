#include <iostream>

using namespace std;

int main() {
	int ordem;

	cin >> ordem;

	int matriz[ordem][ordem];
	int linha = -1, coluna = -1;

	for(int i = 0; i < ordem; i++) {
		for(int j = 0; j < ordem; j++) {
			cin >> matriz[i][j];
			// guarda a linha e coluna do cavalo
			// evita o caso de encontrar um segundo cavalo
			if (matriz[i][j] == 1 and linha == -1 and coluna == -1) {
				linha = i;
				coluna = j;
			}
		}
	}

	// verifica se posso ir para as direcoes esperadas do movimento
	// do cavalo (Fonte: Kiesa)
	bool esquerda = (coluna - 1) >=0;
	bool direita  = (coluna + 1) < ordem;

	bool cima     = (linha - 2) >= 0;
	bool baixo    = (linha + 2) < ordem;

	int eliminacoes = 0;
	
	if (cima) 
		if (esquerda) 
			if (matriz[linha+2][coluna-1] == 2)
				eliminacoes++;

		if (direita)
			if (matriz[linha+2][coluna+1] == 2)
				eliminacoes++;

	if (baixo)
		if (esquerda)
			if (matriz[linha-2][coluna-1] == 2)
				eliminacoes++;
		if (direita)
			if (matriz[linha-2][coluna+1] == 2)
				eliminacoes++;

	// como ja verificou se posso ir para cima e baixo
	// verifica se posso ir pra esquerda e direita, andando apenas uma
	// posicao...
	esquerda = (coluna - 2) >=0;
	direita  = (coluna + 2) < ordem;

	cima = (linha - 1) >=0;
	baixo = (linha + 1) < ordem;

	if (esquerda)
		if (cima)
			if (matriz[linha - 1][coluna - 2] == 2)
				eliminacoes++;
		if (baixo)
			if (matriz[linha + 1][coluna - 2] == 2)
				eliminacoes++;

	if (direita)
		if (cima)
			if (matriz[linha - 1][coluna + 2] == 2)
				eliminacoes++;
		if (baixo)
			if (matriz[linha + 1][coluna + 2] == 2)
				eliminacoes++;

	cout << eliminacoes << endl;
	return 0;
}
