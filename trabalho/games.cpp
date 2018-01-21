#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>
#include <stdlib.h>

// TAMANHO MAXIMO PERMITIDO PARA UM TEXTO, FINS DE NORMALIZACAO
#define MAX_TEXTO 300

using namespace std;

// CONSTANTE PARA FACIL MANUTENCAO E TROCA DO ARQUIVO BINARIO 
char nome_arquivo[] = {"games.dat"};

// ESTRUTURA QUE REPRESENTA UM DETERMINADO GAME
struct Game {
    int codigo;
    char nome[MAX_TEXTO];
    int ano_lancamento;
    char plataforma[MAX_TEXTO];
    char descricao[MAX_TEXTO];
};

/**
 * Procedimento responsavel por fazer a leitura de uma cadeia de caracteres,
 * com espacos incluidos, e o retorno dessa leitura sendo manipulado no
 * vetor passado por parametro.
 * */
void getstring(char value[]) {
    cin.ignore();
    cin.getline(value, MAX_TEXTO);
}

/**
 * Funcao responsavel por fazer a leitura de um numero inteiro valido 
 * obtido pelo usuario. Enquanto esse numero nao for valido, a leitura 
 * eh repetida, ate que seja informado o numero, e este sera retornardo.
 * 
 * */
int getint() {
    int x=0;

    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Entrada invalida! Digite um numero valido: ";
    }
    
    return x;
}

/**
 * Procedimento auxiliar e padrao que simula o comando PAUSE dos sistemas
 * Windows, executando de forma simples e sem depender de seu sistema 
 * operacional. Pode haver falhas.
 * */
void press_enter() {
    cin.ignore();
    cout << "Pressione ENTER para continuar... " << flush;
    cin.ignore(numeric_limits<streamsize> ::max(), '\n' );
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

/////////////////////////// CADASTRO ///////////////////////////////////
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
    
    limpa_tela();

    cout << endl << "Cadastrando novo game..." << endl;
    cout << endl;

    cout << "Preencha as informacoes abaixo: " << endl;
    cout << " - Nome (ate " << MAX_TEXTO << " caracteres): ";
    getstring(leitura->nome);
    cout << " - Ano de Lancamento: ";
    leitura->ano_lancamento = getint();
    cout << " - Plataforma (ate " << MAX_TEXTO << " caracteres e separada por - ): ";
    cin >> leitura->plataforma;
    cout << " - Descricao (ate " << MAX_TEXTO << " caracteres): ";
    getstring(leitura->descricao);

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
	if ((*arquivo).good()) {
		(*arquivo).seekg(0, (*arquivo).end);
		int tam = (*arquivo).tellg();
		(*arquivo).seekg(0, (*arquivo).beg);
		return tam;
	}
	return 0;
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
//////////////////////// FIM DO CADASTRO ///////////////////////////////

/////////////////////////// LISTAGEM ///////////////////////////////////


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
void listar(ifstream *leitor, bool rotular) {
    if (rotular)
        limpa_tela();

    // qtd de bytes no arquivo binario
    int buffer = tamanho_buffer(leitor);

    // qtd de registros presentes (dados integros)
    unsigned int qtd = qtd_cadastrados(buffer);
    
    Game *valores = new Game[qtd];

    (*leitor).read((char *) (valores), buffer);

    if (rotular)
        cout << " ****** Listagem dos Games cadastrados ******" << endl;

    cout << endl;

    for(unsigned int i = 0; i < qtd; i++) {
        imprime_game(valores[i], true);
    }
    
    if (rotular) {
        cout << "Total: " << qtd << " registros." << endl;
        cout << endl;
    }
    delete [] valores;
}
//////////////////////// FIM DA LISTAGEM ////////////////////////////////




/////////////////////////// PESQUISAS ///////////////////////////////////
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
    int codigo = getint();

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
        limpa_tela();
        cout << "Game encontrado! Seguem os dados abaixo: " << endl;
        cout << endl;
        imprime_game(valores[posicao], false);
        cout << endl;
        press_enter();
    } else {
        cout << endl;
        cout << "Desculpe! Nao existe nenhum Game cadastrado com o codigo " << codigo << endl;
        cout << endl;
        cout << "Deseja procurar novamente (y/n)? ";
        char op;
        cin >> op;
        if (op == 'y' and op == 'Y')
            busca_pelo_codigo(leitor);
    }

    delete valores;
}

/**
 * Procedimento padrao de busca, utilizando como parametro de pesquisa
 * o nome INTEGRO (nome igual ao informado) do game.
 *
 * */
void busca_pelo_nome(ifstream *leitor) {
    limpa_tela();

    cout << "Informe o nome do Game que deseja encontrar: ";

    char *nome = new char[MAX_TEXTO];
    getstring(nome);

    int qtd = qtd_cadastrados(leitor);

    int posicoes[qtd], contador = 0;

    Game *valores = busca_todos(leitor, qtd);

    for(int i = 0; i < qtd; i++) {
        if (strstr(valores[i].nome, nome) != NULL) {
            posicoes[contador] = i;
            contador++;
        }
    }
    
    if (contador > 0) {
        
        limpa_tela();
        cout << "Game encontrado! Seguem os dados abaixo: " << endl;
        int i = 0;
        int posicao;
        while(i < contador) {
            posicao = posicoes[i];
            if (i == 0 and contador == 1)
                imprime_game(valores[posicao], false);
            else
                imprime_game(valores[posicao], true);
            i++;
        }

        press_enter();
    } else {
        cout << endl;
        cout << "Desculpe! Nao existe nenhum Game cadastrado com o nome " << nome << endl;
        cout << endl;
        cout << "Deseja procurar novamente (y/n)? ";
        char op;
        cin >> op;
        if (op == 'y' or op == 'Y')
            busca_pelo_nome(leitor);
    }

    delete valores;

}

/**
 * Procedimento padrao de busca, utilizando como parametro de pesquisa
 * a plataforma INTEGRA (plataforma igual ao informado) do game.
 *
 * */
void busca_pela_plataforma(ifstream *leitor) {
    limpa_tela();

    cout << "Informe a plataforma (separados entre hifen): ";
    char *plataforma = new char[MAX_TEXTO];
    cin >> plataforma;

    int qtd = qtd_cadastrados(leitor);

    Game *valores = busca_todos(leitor, qtd);

    int *posicoes = new int[qtd], contador = 0;
        
    for(int i = 0; i < qtd; i++) {
        if (strstr(valores[i].plataforma, plataforma) != NULL) {
            posicoes[contador] = i;
            contador++;
        }
    }
    
    if (contador > 0) {
        limpa_tela();
        cout << "Games encontrados! Seguem os dados abaixo: " << endl;
        int i = 0;
        int posicao;
        while(i < contador) {
            posicao = posicoes[i];
            if (i == 0 and contador == 1)
                imprime_game(valores[posicao], false);
            else
                imprime_game(valores[posicao], true);
            i++;
        }

        press_enter();
    } else {
        cout << endl;
        cout << "Desculpe! Nao existe nenhum Game cadastrado que suporte SOMENTE a plataforma " << plataforma << endl;
        cout << endl;
        cout << "Deseja procurar novamente (y/n)? ";
        char op;
        cin >> op;
        if (op == 'y' or op == 'Y')
            busca_pela_plataforma(leitor);
    }

    delete [] posicoes;
    delete valores;
}

/**
 * Funcao que, dado um determinado ano de lancamento, mostra as todos os
 * games que foram lancados neste ano.
 * 
 * */
void busca_pelo_ano(ifstream *leitor) {
    limpa_tela();

    cout << "Informe o ano de lancamento do Game que deseja procurar: ";
    int ano = getint();

    int qtd = qtd_cadastrados(leitor), contador = 0;

    Game *valores = busca_todos(leitor, qtd);

    int *posicoes = new int[qtd];
    
    for(int i = 0; i < qtd; i++) {
        if (valores[i].ano_lancamento == ano) {
            posicoes[contador++] = i;
        }
    }
    
    
    if (contador > 0) {
        limpa_tela();       
        cout << "Games encontrados! Seguem os dados abaixo: " << endl;

        for(int i = 0; i < contador; i++) {
            int posicao = posicoes[i];
            imprime_game(valores[posicao], true);
        }

        press_enter();
    } else {
        cout << endl;
        cout << "Desculpe! Nao existe nenhum Game cadastrado com o ano de lancamento em " << ano << endl;
        cout << endl;
        cout << "Deseja procurar novamente (y/n)? ";
        char op;
        cin >> op;
        if (op == 'y')
            busca_pelo_codigo(leitor);
    }

    delete [] posicoes;

    delete valores;
}
/////////////////////// FIM DAS PESQUISAS //////////////////////////////

///////////////////////// MODIFICACAO //////////////////////////////////
/**
 * Funcao que faz a validacao de um determinado codigo para um possivel
 * Game, que vai ser modificado.
 *
 * Seu funcionamento se baseia com a organizacao dos registros salvos
 * dentro do arquivo, ou seja, a quantidade de registros existentes dentro
 * do arquivo representa o ULTIMO cadastrado, e o PRIMEIRO registro assume
 * o primeiro valor.
 * */
bool codigo_valido(ifstream *leitor, int codigo) {
    return codigo <= qtd_cadastrados(leitor) and codigo > 0;
}

/**
 * Funcao que retorna um determinado registro a partir de seu codigo.
 *
 * A ideia principal eh posicionar o leitor na posicao em que se encontra
 * o codigo. Lembrando do particionamento de vetores (iniciando na posicao
 * zero), o codigo do Game 1 se encontra na posicao 0, do Game 2 na posicao
 * 1, e assim sucessivamente.
 * */
Game * obtem_unico_game(ifstream *leitor, int codigo) {
    int posicao = (codigo-1) * sizeof(Game);

    // posiciona o 'ponteiro' de leitura x posicoes pra frente do inicio
    // do arquivo, ou seja, a posicao do registro que interessa
    (*leitor).seekg(posicao, (*leitor).beg);

    Game  *selecionada = new Game;

    // coloca dentro de selecionada apenas o primeiro conteudo, ou seja,
    // o registro necessario
    (*leitor).read((char *) (selecionada), sizeof(Game));

    return selecionada;
}

/**
 * Procedimento responsavel por fazer a reescrita dos dados para simular
 * a alteracao de um determinado registro.
 *
 * O processo eh dado por fazer a leitura dos dados antes da alteracao do
 * registro selecionado, salvando eles na memoria. Apos esta leitura,
 * eh feita a reescrita dos dados (com o atualizado em seu devido lugar)
 * dos valores lidos anteriormente.
 *
 * Isso faz com que o arquivo nao tenha duplicacoes e apenas tenha os
 * registros integros. O preco a se pagar de trabalhar desta forma eh
 * o custo de reescrita de todos os dados. 
 *
 * */
void reescreve_arquivo(ifstream *leitor, ofstream *gravador, Game *selecionado) {
    int total = qtd_cadastrados(leitor);
    Game *valores = busca_todos(leitor, total);

    int posicao_selecionado = selecionado->codigo - 1;

    valores[posicao_selecionado] = *selecionado;

    // fecha o arquivo que antes estava aberto
    (*gravador).close();

    // abre novamente mas desta vez para substituir os valores...
    // opcao padrao do ofstream eh substituir o conteudo presente
    // quando abrir o arquivo
    (*gravador).open(nome_arquivo, ios::binary);

    for(int i = 0; i < total; i++) {
        (*gravador).write(reinterpret_cast<const char *> (&valores[i]), sizeof(Game));
    }

    // fecha o modo que foi aberto para reescrever, para nao dar problema
    // depois
    (*gravador).close();
    
    delete [] valores;
}

int seleciona_codigo_game(ifstream *leitor) {
    cout << "Escolha um dos Games abaixo para comecar a editar..." << endl;
    cout << endl;
    
    listar(leitor, false);

    cout << endl;
    cout << "Digite o codigo do game que deseja editar: ";
    int codigo;
    cin >> codigo;

    return codigo;
}

/**
 * Procedimento que modifica as informacoes de um Game ja salvo no arquivo
 * binario.
 *
 *
 * */
void modifica(ifstream *leitor, ofstream *gravador) {
    int codigo = seleciona_codigo_game(leitor);
    
    if (codigo_valido(leitor, codigo)) {
        Game *selecionado = obtem_unico_game(leitor, codigo);

        int escolha;
        
        do {
            limpa_tela();
            cout << endl;
            cout << "Informacoes atuais..." << endl;

            cout << endl;
            imprime_game(*selecionado, false);

            cout << endl;
            cout << "O que deseja modificar?" << endl;
            cout << "1 - Nome do jogo" << endl;
            cout << "2 - Ano de Lancamento" << endl;
            cout << "3 - Plataforma" << endl;
            cout << "4 - Descricao" << endl;
            cout << "0 - Voltar" << endl;
            cout << endl << "Escolha: ";

            escolha = getint();
            
            cout << endl;
            limpa_tela();

            if (escolha > 0 and escolha <=4) 
				imprime_game(*selecionado, false);
            switch(escolha) {
                case 1: {
                    cout << endl;
                    cout << "Novo nome (ate " << MAX_TEXTO << " caracteres): ";
                    getstring(selecionado->nome);
                    break;
                }
                case 2: {
                    cout << endl;
                    cout << "Novo ano do lancamento: ";
                    selecionado->ano_lancamento = getint();
                    break;
                }
                case 3: {
                    cout << endl;
                    cout << "Nova plataforma (at� " << MAX_TEXTO << " caracteres e separada por - ): ";
                    getstring(selecionado->plataforma);
                    break;
                }
                case 4: {
                    cout << endl;
                    cout << "Nova descricao (at� " << MAX_TEXTO << " caracteres): ";
                    getstring(selecionado->descricao);
                    break;
                }
            }

            if (escolha != 0) {
                cout << endl;
                cout << "Deseja editar mais alguma informacao? (Y/n) ";
                char opcao;
                cin >> opcao;

                if (opcao == 'y' or opcao == 's' or opcao == 'Y') escolha = -1;
                else escolha = 0;
            }
        } while(escolha != 0);

        reescreve_arquivo(leitor, gravador, selecionado);

        delete selecionado;

        limpa_tela();
    } else {
        limpa_tela();
        cout << endl;
        cout << "Nao foi possivel modificar o Game com o codigo " << codigo << "." << endl;
        cout << "Motivo: Codigo invalido ou inexistente." << endl;
    }
}


/////////////////////// FIM DA MODIFICACAO /////////////////////////////


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

        escolha = getint();

        switch(escolha) {
            case 1: {
                char retornar;
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
                    cout << endl;
                    cout << "Game cadastrado com sucesso!" << endl;
                    cout << endl;
                    cout << "Deseja cadastrar outro game? (y/n)";
                    cin >> retornar;
                } while(retornar != 'n' and retornar != 'N');
                break;
            }
            case 2: {
                char escolha;
                do {
                    limpa_tela();
                    
                    ifstream leitor(nome_arquivo, ios::binary);
                    ofstream gravador(nome_arquivo, ios::binary | ios::app);

                    if (qtd_cadastrados(&leitor) >= 1) {
                        modifica(&leitor, &gravador);
                        cout << endl;
                        cout << "Deseja alterar outro Game? (y/n)";
                        cin >> escolha;
                    } else {
                        limpa_tela();
                        cout << "Cadastre algum Game antes de atualizar sua informacao." << endl;

                        press_enter();

                        // sair do loop
                        escolha = 'n';
                    }
                    // fecha os arquivos se estiverem ainda abertos
                    if (leitor) leitor.close();
                    if (gravador) gravador.close();
                    
                } while(escolha == 'y' or escolha == 'Y');
                break;
            }
            case 3: {
                int opcao_pesquisa;
                ifstream leitor(nome_arquivo, ios::binary);
                if (qtd_cadastrados(&leitor) > 0) {
                    do{
                        limpa_tela();
                        cout << "Busca de Registros" << endl;
                        cout << endl;
                        cout << "Qual � o parametro de busca? " << endl;
                        cout << "1 - Codigo de cadastro" << endl;
                        cout << "2 - Nome do Game" << endl;
                        cout << "3 - Ano de Lancamento" << endl;
                        cout << "4 - Plataforma" << endl;
                        cout << "0 - Voltar para o menu principal" << endl;
                        cout << endl;
                        cout << "Escolha: ";
                        opcao_pesquisa = getint();

                        switch (opcao_pesquisa) {
                            case 1: {
                                busca_pelo_codigo(&leitor);
                                break;
                            }
                            case 2: {
                                busca_pelo_nome(&leitor);
                                break;
                            }
                            case 3: {
                                busca_pelo_ano(&leitor);
                                break;
                            }
                            case 4: {
                                busca_pela_plataforma(&leitor);
                                break;
                            }
                        }
                    } while(opcao_pesquisa!=0);
                } else {
                    limpa_tela();
                    cout << "Cadastre algum Game para poder realizar a busca!" << endl;
                    press_enter();
                }
                leitor.close();
                break;
            }
            case 4: {
                ifstream arquivo(nome_arquivo, ios::binary);

                if(qtd_cadastrados(&arquivo) > 0) {
                    listar(&arquivo, true);
                } else {
                    limpa_tela();
                    cout << "Nenhum game foi cadastrado." << endl;
                }
                arquivo.close();
                press_enter();
                break;
            }
        }
        
    } while (escolha != 0);

    cout << endl;
    cout << "Ate breve!" << endl;

    return 0;
}
