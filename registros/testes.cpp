#include <iostream>

using namespace std;

struct aluno {
	string nome;
	float cra;
	string curso;
};

int main() {
	aluno alunos_ialg[4];
	
	int i =  0;
	
	while (i < 4) {
		cin >> alunos_ialg[i].nome;
		cin >> alunos_ialg[i].cra;
		cin >> alunos_ialg[i].curso;
		
		i++;
	}
	
	i = 0;
	while(i < 4) {
		
		cout << "******* Aluno " << i << " ******* "<< endl;
		cout << "Nome: " << alunos_ialg[i].nome << endl;
		cout << "CRA: " << alunos_ialg[i].cra << endl;
		cout << "Curso: " << alunos_ialg[i].curso << endl;
		
		
		i++;
	}
	
	
	return 0;
}
