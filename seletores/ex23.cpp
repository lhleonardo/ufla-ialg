#include <iostream>

using namespace std;

float percentual(float valor, int p) {
	return (valor * p) / 100.0;
}

float calculaImposto(float salario) {
	if (salario<200) {
		return 0;
	} else if (salario >=200 and salario <=450) {
		return percentual(salario, 3);	
	} else if (salario >= 450 and salario <=700) {
		return percentual(salario, 8);
	} else {
		return percentual(salario, 12);
	}
}

float calculaGratificacao(float salario, int tempo) {
	if (salario <=500) {
		if (tempo <3) {
			return percentual(salario, 23);
		} else if (tempo >= 3 and tempo <=6) {
			return percentual(salario, 35);
		} else {
			return percentual(salario, 33);
		}
		
	} else {
		if (tempo<=3) {
			return percentual(salario, 20);
		} else if (tempo > 3) {
			return percentual(salario, 30);
		}
		
	}
	return 0;
}

char classificaCategoria(float valor) {
	if (valor <350) {
		return 'A';
	} else if (valor >=350 and valor <=600) {
		return 'B';
	} else if (valor > 600) {
		return 'C';
	}
	return ' ';
}

int main() {
	float salario, imposto, gratificacao, liquido; 
	char categoria;
	int tempo;
	
	cin >> salario >> tempo;
	
	if (salario > 0) {
		imposto = calculaImposto(salario);
		gratificacao = calculaGratificacao(salario, tempo);
		
		liquido = (salario - imposto) + gratificacao;
		categoria = classificaCategoria(liquido);
		
		cout << imposto << endl;
		cout << gratificacao << endl;
		cout << liquido << endl;
		cout << categoria << endl;
		
	} else {
		// salario negativo?
		// salario sem valor ganha gratificacao?
		return -1;
	}
	
	return 0;
}
