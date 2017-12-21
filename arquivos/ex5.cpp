#include <iostream>
#include <fstream>

using namespace std;

struct Posicao {
	int x;
	int y;
};

int main() {
	char base, inimigo;

	ifstream leitor("tropas.txt");

	if (not leitor) return 0;

	leitor >> base >> inimigo;

	int qtd_base;
	leitor >> qtd_base;

	Posicao posicoes_base[qtd_base];

	for(int i = 0; i < qtd_base; i++) {
		leitor >> posicoes_base[i].x >> posicoes_base[i].y;
	}

	int qtd_inimigo;
	leitor >> qtd_inimigo;

	Posicao posicoes_inimigo[qtd_inimigo];
	for(int i = 0; i < qtd_inimigo; i++) {
		leitor >> posicoes_inimigo[i].x >> posicoes_inimigo[i].y;
	}

	char vazio;
	leitor >> vazio;

	char posicoes[10][10];

	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			posicoes[i][j] = vazio;
		}
	}

	int x, y;
	for(int i = 0; i < qtd_inimigo; i++) {
		x = posicoes_inimigo[i].x;
		y = posicoes_inimigo[i].y;
		posicoes[x][y] = inimigo;
	}

	for (int i = 0; i < qtd_base; i++){
		x = posicoes_base[i].x;
		y = posicoes_base[i].y;
		posicoes[x][y] = base;
	}

	int inimigos, amigos;
	bool vantagem[10];
	for(int i = 0, cont_vantagem = 0; i < 10; i++, cont_vantagem++) {
		inimigos = amigos = 0;
		for(int j = 0; j < 10; j++) {
			if (posicoes[i][j] == inimigo)
				inimigos++;
			if (posicoes[i][j] == base)
				amigos++;
		}
		vantagem[cont_vantagem] = (amigos - inimigos) > 0;
	}
	
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			cout << posicoes[i][j] << " ";
		}
		cout << endl;
	}
	cout << base << ":";

	for(int i = 0; i < 10; i++) {
		if (vantagem[i]) {
			cout << " " << i;
		}
	}

	leitor.close();
	return 0;
}
