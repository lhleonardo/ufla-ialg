#include <iostream>

using namespace std;

// verifica se uma palavra eh palindroma
bool isPalindromo(string palavra) {
	int tam = palavra.length();
	// defino que a palavra eh palindroma, pois acho mais facil verificar
	// se ela nao eh do que se ela for uma palindroma
	bool palindromo = true;
	
	for(int i = 0; i < (tam/2) and palindromo; i++)
		// se a posicao atual for diferente da ultima posicao menos
		// o valor da posicao atual
		if (palavra[i] != palavra[(tam-1)-i])
			palindromo = false;

	return palindromo;
}

void classifica(string palindromos[], int tamanho, string &maior, string &menor) {
	if (tamanho <=0) return;

	// defino que os maiores e menores sao os primeiros elementos
	maior = palindromos[0];
	menor = palindromos[0];

	for(int i = 0; i < tamanho; i++) {
		// metodo compare presente nas strings, que verifica se o texto
		// da variavel em questao esta "antes, depois" ou se o texto eh
		// o mesmo para as duas

		// se for menor que zero, a palavra que antes era a maior eh
		// trocada, pois ela vem antes da comparada 
		if (palindromos[i].compare(maior) < 0) {
			maior = palindromos[i];
		}

		// se for maior que zero, a palavra que antes era a menor eh
		// trocada, pois ela vem depois da comparada
		if (palindromos[i].compare(menor) > 0) {
			menor = palindromos[i];
		}
	}
}

int main() {

	int qtd, i, j, k;

	cin >> qtd;

	string palindromos[qtd], palavras[qtd];

	// recebe os valores
	for(i = 0, j = 0, k = 0; i < qtd; i++) {
		string palavra;
		cin >> palavra;
		// se for palindroma, salva em um vetor, caso contrario, salva
		// em outro vetor, o das palavras comuns
		if (isPalindromo(palavra)) {
			palindromos[j] = palavra;
			j++;
		} else {
			palavras[k] = palavra;
			k++;
		}
	}

	string maior, menor;

	for(int i = 0; i < k; i++)
		cout << palavras[i] << endl;

	// faz a classificação de maior e menor dos palindromos informados
	classifica(palindromos, j, menor, maior);

	cout << menor << endl;
	cout << maior << endl;
	
	return 0;
}

