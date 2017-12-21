#include <iostream>

using namespace std;

char * nome_mes(int mes) {
	// vetor com doze nomes (os doze meses)
	char ** nomes = new char*[12];

	// o valor maximo de cada nome sao 10 caracteres, sendo Fevereiro
	// o mes com tamanho mais extenso
	for(int i = 0; i < 12; i++)
		nomes[i] = new char[10];

	// cada posicao, de zero ate 11, recebe seu respectivo nome
	// sendo sua posicao valida como i+1
	nomes[0] = (char * ) "Janeiro";
	nomes[1] = (char * ) "Fevereiro";
	nomes[2] = (char * ) "Marco";
	nomes[3] = (char * ) "Abril";
	nomes[4] = (char * ) "Maio";
	nomes[5] = (char * ) "Junho";
	nomes[6] = (char * ) "Julho";
	nomes[7] = (char * ) "Agosto";
	nomes[8] = (char * ) "Setembro";
	nomes[9] = (char * ) "Outubro";
	nomes[10] = (char * )"Novembro";
	nomes[11] = (char * )"Dezembro";

	// retorna o nome do mes -1, ja que o vetor comeca em zero
	return nomes[mes-1];
}

int main() {
	// mes como numero positivo
	unsigned int mes;
	cin >> mes;

	// se for um numero maior que doze, nao existe mes para ele
	if (mes > 12) return 0;

	// retorno do nome da funcao
	char *nome = nome_mes(mes);

	// impressao do nome do mes
	cout << nome << endl;

	// liberar a alocacao dinamica da memoria
	// se descomentar essa linha, o programa imprime coisas aleatorias
	// que eu nao faço ideia do que seja...

	// como liberar a memoria?
	
	// delete[] nome;
		
	return 0;
}
