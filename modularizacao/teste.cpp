#include <iostream>
#include <cstring>

using namespace std;

int main() {
	string nome = "Alexandre", existente = "Andre";

	cout << strcmp(nome.c_str(), existente.c_str());
	return 0;
}
