#include <iostream>
#include <cfloat>

using namespace std;

struct Paciente {
	string nome;
	char sexo;
	float altura;
	float peso;
};

float pesoIdeal(Paciente p) {
	if (p.sexo == 'H') {
		return (72.7 * p.altura) - 58;
	} else {
		return (62.1 * p.altura) - 44.7;
	}
}

int main() {
	int n;
	Paciente maisPesado;
	maisPesado.peso = FLT_MIN;

	cin >> n;

	Paciente pacientes[n];

	for (int i = 0; i<n; i++) {
		Paciente p;
		cin >> p.nome;
		cin >> p.sexo;
		cin >> p.altura;
		cin >> p.peso;

		if (p.peso > maisPesado.peso) {
			maisPesado = p;
		}
				
		pacientes[i] = p;
	}

	cout << maisPesado.nome << endl;

	for(int i = 0; i < n; i++) {
		Paciente p = pacientes[i];
		if (p.peso > pesoIdeal(p)) {
			cout << p.nome << " " << (pesoIdeal(p) - p.peso) << endl;
		}
	}

	for(int i = 0; i < n; i++) {
		Paciente p = pacientes[i];
		if (p.peso < pesoIdeal(p)) {
			cout << p.nome << " " << (pesoIdeal(p) - p.peso) << endl;
		}
	}
		
	return 0;
}	
