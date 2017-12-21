#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream arq1("arquivoA.txt"), arq2("arquivoB.txt");
	ofstream destino("arquivoC.txt");

	string l1, l2;
	while(arq1 >> l1 and arq2 >> l2) {
		destino << l1 << " " << l2 << " ";
		l1 = "";
		l2 = "";
	}


	// pode ser que o arquivo l2 acabou primeiro q l1, mas fez a leitura
	if (l1 != "") {
		destino << l1 << " ";
		l1 = "";
	}

	// pode ser q o arquivo l1 acabou primeiro q l2, mas fez a sua leitura
	if (l2 != "") {
		destino << l2 << " ";
		l2 = "";
	}

	while (arq1 >> l1) {
		destino << l1 << " ";
	}

	while (arq2 >> l2) {
		destino << l2 << " ";
	}
	
	return 0;
}
