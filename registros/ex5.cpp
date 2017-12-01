#include <iostream>

using namespace std;

struct Entrevistado {
	int idade;
	char sexo;
	// S ou N
	char resposta;
};

int main() {
	int n;

	int qtdSim = 0, qtdNao = 0;
	int qtdMaior18Sim = 0, qtdMenor18Nao = 0;
	int mulheresMaior18Nao = 0, homensMenor18Sim = 0;

	cin >> n;

	Entrevistado entrevistados[n];

	for(int i = 0; i < n; i++) {
		Entrevistado e;
		cin >> e.sexo;
		cin >> e.idade;		
		cin >> e.resposta;

		if (e.resposta == 'S') {
			qtdSim++;
		}

		if(e.resposta == 'N') {
			qtdNao++;
		}

		if (e.idade > 18 and e.resposta == 'S') {
			qtdMaior18Sim++;
		}

		if (e.idade < 18 and e.resposta == 'N') {
			qtdMenor18Nao++;
		}

		if (e.resposta == 'N' and e.sexo == 'F' and e.idade > 18) {
			mulheresMaior18Nao++;
		}

		if (e.resposta == 'S' and e.sexo == 'M' and e.idade < 18) {
			homensMenor18Sim++;
		}

		entrevistados[i] = e;
	}

	cout << qtdSim << endl;
	cout << qtdNao << endl;
	cout << qtdMaior18Sim << endl;
	cout << qtdMenor18Nao << endl;
	cout << mulheresMaior18Nao << endl;
	cout << homensMenor18Sim << endl;

	return 0;
}
