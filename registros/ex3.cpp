#include <iostream>
#include <cfloat>

using namespace std;

struct Pessoa {
	float salario;
	int idade;
	int filhos;
};

int main() {
	int n, totalFilhos = 0, qtdSalarioMaiorQueMil = 0;
	float totalSalario = 0;

	Pessoa rica;
	rica.salario = FLT_MIN;

	cin >> n;

	Pessoa pessoas[n];

	for (int i = 0; i < n; i++) {
		Pessoa p;
		cin >> p.salario;
		cin >> p.idade;
		cin >> p.filhos;
		
		totalSalario += p.salario;
		totalFilhos += p.filhos;

		if (p.salario > rica.salario) 
			rica = p;

		if (p.salario > 1000) 
			qtdSalarioMaiorQueMil++;
			
		pessoas[i] = p;
	}

	cout << (totalSalario/float(n)) << endl;
	cout << (totalFilhos/float(n)) << endl;
	cout << rica.salario << endl;
	cout << ((qtdSalarioMaiorQueMil * 100) / float(n)) << "%" << endl;
	
	return 0;
}
