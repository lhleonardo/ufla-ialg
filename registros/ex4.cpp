#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

struct Atleta {
	string nome;
	string esporte;
	int idade;
	float altura;
};

int main() {
	Atleta maisAlto;
	Atleta maisVelho;

	maisAlto.altura = FLT_MIN;
	maisVelho.idade = INT_MIN;

	for (int i = 0; i < 5; i++) {
		Atleta a;
		cin >> a.nome;
		cin >> a.esporte;
		cin >> a.idade;
		cin >> a.altura;

		if (a.altura > maisAlto.altura) {
			maisAlto = a;
		}

		if (a.idade > maisVelho.idade) {
			maisVelho = a;
		}	
	}

	cout << maisAlto .nome << " " << maisAlto .esporte << endl;
	cout << maisVelho.nome << " " << maisVelho.esporte << endl;

	return 0;
}
