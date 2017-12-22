#include <iostream>     
#include <fstream>   

using namespace std;

struct Pessoa {
	int codigo;
	char nome[60];
	int idade;

};

int main() {
	fstream arquivo("pessoas1.dat", ios::binary | ios::app | ios::in | ios::out);

	if (arquivo) {
		//Pessoa *p = new Pessoa;
		//cin >> p->codigo;
		//cin >> p->nome;
		//cin >> p->idade;

		//arquivo.write(reinterpret_cast<const char *> (p), sizeof(Pessoa));

		//delete p;

		arquivo.seekg(0, arquivo.end);
		int bytes = arquivo.tellg();
		arquivo.seekg(0, arquivo.beg);

		int total = bytes / sizeof(Pessoa);
		
		Pessoa *valores = new Pessoa[total];

		arquivo.read((char *) (valores), bytes);

		for(int i = 0; i < total; i++) {
			cout << "Codigo: " << valores[i].codigo << endl;
			cout << "Nome: " << valores[i].nome << endl;
			cout << "Idade: " << valores[i].idade << endl;
			cout << "-------------------------" << endl;
		}

		cout << "Total: " << total << endl;
		
		cout << endl;
		cout << "Digite o codigo de quem você deseja editar: ";
		int codigo;
		cin >> codigo;

		if (codigo <= total) {
			arquivo.seekg((codigo-1)*sizeof(Pessoa), arquivo.beg);
			
			Pessoa *selecionada = new Pessoa;
			arquivo.read((char *) (selecionada), sizeof(Pessoa));

			cout << "Pessoa selecionada: " << endl;
			cout << "Codigo: " << selecionada->codigo << endl;
			cout << "Nome: " << selecionada->nome << endl;
			cout << "Idade: " << selecionada->idade << endl;

			cout  << "******EDICAO*********" << endl;
			cout << "Informe novo nome:";
			cin >> selecionada->nome;
			cout << "Informe nova idade: ";
			cin >> selecionada->idade;

			valores[(selecionada->codigo)-1] = *selecionada;

			arquivo.close();

			arquivo.open("pessoas1.dat", ios::binary | ios::trunc | ios::out);

			for(int i = 0; i < total; i++) {
				Pessoa atual = valores[i];
				arquivo.write(reinterpret_cast<const char *> (&atual), sizeof(Pessoa));
			}

			cout << endl;
			cout << "Dados gravados! Reinicie e veja se foi alterado." << endl;
		} else {
			cout << "Não posso selecionar alguem que não existe. ";
			cout << "O codigo está fora do intervalo [1, " << total << "]." << endl;
		}
	} else {
		cout << "Arquivo fechado!";
	}

	

	return 0;
}
