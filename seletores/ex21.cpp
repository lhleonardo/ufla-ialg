#include <iostream>

using namespace std;

int main(){
	int horaInicio, minutoInicio, horaFinal, minutoFinal, horaDuracao, minutoDuracao;
	
	cin >> horaInicio >> minutoInicio >> horaFinal >> minutoFinal;
	
	horaDuracao = horaFinal - horaInicio;
	
	minutoDuracao = minutoFinal - minutoInicio;
	
	if (horaDuracao < 0){
		horaDuracao = horaDuracao + 24;
	}
	if(minutoDuracao < 0){
		horaDuracao = horaDuracao - 1;
		minutoDuracao = minutoDuracao + 60;
	}
	
	cout << horaDuracao << " " << minutoDuracao;
}
