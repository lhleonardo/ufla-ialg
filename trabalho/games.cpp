#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>

// TAMANHO MAXIMO PERMITIDO PARA UM TEXTO, FINS DE NORMALIZACAO
#define MAX_NOME 300

using namespace std;

// CONSTANTE PARA FACIL MANUTENCAO E TROCA DO ARQUIVO BINARIO 
char nome_arquivo[] = {"games.dat"};

// ESTRUTURA QUE REPRESENTA UM DETERMINADO GAME
struct Game {
	int codigo;
	char nome[MAX_NOME];
	int ano_lancamento;
	char plataforma[MAX_NOME];
	char descricao[MAX_NOME];
};

/**
 * Metodo responsavel por realizar a coleta dos dados de um determinado
 * game informado pelo usuario e salvar no arquivo a partir dos mesmos.
 *
 * Esse metodo tambem tem a obrigacao de cuidar da atomicidade dos valores,
 * sendo diferenciados pelo codigo que os identifica. 
 *
 * */
void cadastrar(ofstream *gravador, int codigo) {
	Game *leitura = new Game;
	
	// META: 
	// trabalhar capturando os textos com espacos
	system("clear");
	cout << "Cadastrando novo game..." << endl;
	cout << "Informe o nome (até " << MAX_NOME << " caracteres e SEM ESPACOS): ";
	cin >> leitura->nome;
	
	cout << "Informe o ano de lancamento: ";
	cin >> leitura->ano_lancamento;
	cout << "Informe a plataforma suportada (até " << MAX_NOME << " caracteres e SEM ESPACOS): ";
	cin >> leitura->plataforma;
	cout << "Informe uma pequena descricao (até " << MAX_NOME << " caracteres e SEM ESPACOS): ";
	cin >> leitura->descricao;

	leitura->codigo = codigo;

	(*gravador).write(reinterpret_cast<const char *> (leitura), sizeof(Game));

	delete leitura;
}

/**
 * Funcao que faz o ponteiro de escrita ir ao final do arquivo. Com isso,
 * pode-se obter o tamanho de bytes que o arquivo tem (ja que esta no
 * ultimo elemento). Retorna um inteiro.
 * */
int tamanho_buffer(ifstream *arquivo) {
	(*arquivo).seekg(0, (*arquivo).end);
	int tam = (*arquivo).tellg();
	(*arquivo).seekg(0, (*arquivo).beg);
	return tam;
}

/**
 * Funcao que, a partir do arquivo aberto, retorna a quantidade de registros
 * de Game salvo em seu corpo.
 *
 * Logica do valor: Tamanho total / tamanho do Registro
 *
 * */
int qtd_cadastrados(ifstream *arquivo) {
	return tamanho_buffer(arquivo) / sizeof(Game);
}

/**
 * Funcao auxiliar que, a partir do tamanho ja obtido do arquivo, retorna
 * a quantidade de registros presente nesse tamanho.
 *
 * Logica do valor: Tamanho total / tamanho do registro
 *
 * Sobrecarga da funcao que utiliza um ponteiro de arquivo
 * */
int qtd_cadastrados(int buffer) {
	return buffer/sizeof(Game);
}

/**
 * Funcao auxiliar que apenas limpa o prompt de comando (tela).
 *
 * Como nos dois sistemas mais utilizados (Windows e Linux) os comandos
 * de limpeza da tela sao diferentes, e sabendo que toda instrucao bem-
 * sucedida passada para a funcao *system* tem o retorno como 0, limpa a
 * tela para respectivo S.O. em execucao (os mais utilizados).
 *
 * Ou seja, se o comando de limpar no windows nao der certo (retornar
 * algo diferente de zero), quer dizer que deve-se limpar a partir do
 * comando do Linux, e vice-versa.
 *
 * */
void limpa_tela() {
	if (system("clear") != 0) {system("cls");}
	if (system("cls") != 0) {system("clear");}
}

/**
 * Funcao simples que apenas faz a impressao de um determinado registro
 * de Game, recebendo o registro que sera' impresso e um parametro logico
 * que determina se a impressao apresentara' um separador entre as
 * impressoes (util para muitas impressoes em sequencia).
 *
 * */
void imprime_game(Game valor, bool separador) {
	cout << "- Codigo: " << valor.codigo << endl;
	cout << "\t- Nome do Jogo: " << valor.nome << endl;
	cout << "\t- Ano de Lancamento: " << valor.ano_lancamento << endl;
	cout << "\t- Plataformas: " << valor.plataforma << endl;
	cout << "\t- Descricao: " << valor.descricao << endl;
	if (separador)
		cout << "--------------------------------------------------------" << endl;
}

/**
 * Procedimento que faz a listagem dos registros armazenados no arquivo.
 *
 * Seu processo eh dado a partir da obtencao do tamanho do arquivo (buffer)
 * e tambem pela quantidade propriamente dita de registros presentes no
 * arquivo (qtd_buffer/bytes_um_registro).
 *
 * A partir disso, basta usar a funcao read, presente no stream de
 * entrada (ifstream), que ira preencher o vetor de Registros com as
 * alocacoes corretas de bytes pertencentes a cada registro, em ordem
 * sequencial.
 *
 * */
void listar(ifstream *leitor) {
	limpa_tela();

	// qtd de bytes no arquivo binario
	int buffer = tamanho_buffer(leitor);

	// qtd de registros presentes (dados integros)
	unsigned int qtd = qtd_cadastrados(buffer);
	
	Game *valores = new Game[qtd];

	(*leitor).read((char *) (valores), buffer);

	cout << " ****** Listagem dos Games cadastrados ******" << endl;

	cout << endl;

	for(unsigned int i = 0; i < qtd; i++) {
		imprime_game(valores[i], true);
	}
	
	cout << "Qtd de Registros Cadastrados: " << qtd << endl;

	cout << endl;
	// apenas para a listagem aparecer e ir direto para o menu principal
	// ter um tempo de delay...
	char escolha;
	do {
		cout << "Digite Y para voltar ao menu principal...";
		cin >> escolha;
	} while(escolha != 'Y');
	
	delete [] valores;
}

/**
 * Funcao responsavel por pegar todos os valores presentes no arquivo
 * binario e converter para vetor de registros validos para as PESQUISAS.
 * */
Game * busca_todos(ifstream * leitor, int qtd) {
	Game *valores = new Game[qtd];

	(*leitor).read((char *) (valores), qtd * sizeof(Game));

	return valores;
}

/**
 * Funcao que, dado um determinado codigo, mostra as informacoes do
 * registro que possui este codigo (caso exista).
 * 
 * */
void busca_pelo_codigo(ifstream *leitor) {
	limpa_tela();

	cout << "Informe o codigo que deseja procurar: ";
	int codigo;
	cin >> codigo;

	int qtd = qtd_cadastrados(leitor), posicao = -1;

	Game *valores = busca_todos(leitor, qtd);

	
	// se o codigo for maior que a quantidade disponivel, nem procura
	if (codigo <=qtd) {	
		
		for(int i = 0; i < qtd and posicao == -1; i++) {
			if (valores[i].codigo == codigo) {
				posicao = i;
			}
		}
	}
	
	if (posicao != -1) {
		char op;
		do {
			limpa_tela();
			cout << "Game encontrado! Seguem os dados abaixo: " << endl;
			imprime_game(valores[posicao], false);
			cout << "Pressione Y para voltar as buscas...";
			cin >> op;
		} while (op != 'Y');
	} else {
		cout << "Desculpe! Nao existe nenhum Game cadastrado com o codigo " << codigo << endl;
		cout << "Deseja procurar novamente (1-SIM, 0-NAO)? ";
		int op;
		cin >> op;
		if (op == 1)
			busca_pelo_codigo(leitor);
	}

	delete valores;
}

void busca_pelo_nome(ifstream *leitor) {
	limpa_tela();

	cout << "Informe o nome do Game que deseja encontrar: ";
	char *nome = new char[MAX_NOME];
	cin >> nome;

	int qtd = qtd_cadastrados(leitor), posicao = -1;

	Game *valores = busca_todos(leitor, qtd);

	// se o codigo for maior que a quantidade disponivel, nem procura
	
		
	for(int i = 0; i < qtd and posicao == -1; i++) {
		if (strcmp(valores[i].nome, nome) == 0) {
			posicao = i;
		}
	}
	
	if (posicao != -1) {
		char op;
		do {
			limpa_tela();
			cout << "Game encontrado! Seguem os dados abaixo: " << endl;
			imprime_game(valores[posicao], false);
			cout << "Pressione Y para voltar as buscas...";
			cin >> op;
		} while (op != 'Y');
	} else {
		cout << "Desculpe! Nao existe nenhum Game cadastrado com o nome " << nome << endl;
		cout << "Deseja procurar novamente (1-SIM, 0-NAO)? ";
		int op;
		cin >> op;
		if (op == 1)
			busca_pelo_nome(leitor);
	}

	delete valores;

}

/**
 * Funcao principal que mostra as opcoes disponiveis e tambem faz a
 * preparacao de leitura e escrita do arquivo binario.
 *
 * Tambem eh responsavel por fechar toda instancia do arquivo que foi
 * aberta.
 * */
int main() {
	int escolha;

	do {
		limpa_tela();
		
		cout << endl;
		cout << "\t Gerenciador de Games \t" << endl;
		cout << "Selecione uma opcao para prosseguir..." << endl;
		cout << endl;
		cout << "------------------------------------------" << endl;
		cout << "|         Lista de opcoes validas:       |" << endl;
		cout << "------------------------------------------" << endl;
		cout << "| 1 | Cadastrar novo game                |" << endl;
		cout << "| 2 | Modificar um game existente        |" << endl;
		cout << "| 3 | Buscar um determinado game         |" << endl;
		cout << "| 4 | Mostrar todos os games cadastrados |" << endl;
		cout << "| 0 | Sair do programa                   |" << endl;
		cout << "------------------------------------------" << endl;
		cout << "Escolha uma opcao: ";
		cin >> escolha;

		switch(escolha) {
			case 1: {
				int retornar;
				do {
					// vejo a quantidade de registros e faco um novo codigo
					// para o atual... 
					ifstream leitor(nome_arquivo, ios::binary | ios::app);
					int proximo_codigo = qtd_cadastrados(&leitor);
					leitor.close();

					// preparo para gravacao
					ofstream gravador(nome_arquivo, ios::binary | ios::app);

					// passa o gravador e o proximo codigo para a funcao
					cadastrar(&gravador, proximo_codigo+1);

					// fecha o gravador
					gravador.close();

					cout << "Game cadastrado com sucesso!" << endl;
					cout << "Deseja cadastrar outro game? (1-SIM, 0-NAO)";
					cin >> retornar;
				} while(retornar != 0);
				break;
			}
			case 2: {
				cout << "Em construcao..." << endl;
				break;
			}
			case 3: {
				int opcao_pesquisa;
				ifstream leitor(nome_arquivo, ios::binary);
				do{
					limpa_tela();
					cout << "Qual é o parametro de busca? " << endl;
					cout << "1 - Codigo de cadastro" << endl;
					cout << "2 - Nome do Game" << endl;
					cout << "3 - Ano de Lancamento" << endl;
					cout << "4 - Plataforma" << endl;
					cout << "0 - Voltar para o menu principal" << endl;

					cin >> opcao_pesquisa;

					switch (opcao_pesquisa) {
						case 1: {
							busca_pelo_codigo(&leitor);
							break;
						}
						case 2: {
							busca_pelo_nome(&leitor);
							break;
						}
					}

				} while(opcao_pesquisa!=0);

				leitor.close();
				break;
			}
			case 4: {
				ifstream arquivo(nome_arquivo, ios::binary);

				listar(&arquivo);

				arquivo.close();
				break;
			}
		}
		
	} while (escolha != 0);

	cout << endl;
	cout << "Tchau!" << endl;
	cout << "Desenvolvido por 1/3 do grupo Cervejava.";

	return 0;
}

