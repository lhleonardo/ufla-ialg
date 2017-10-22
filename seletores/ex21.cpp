#include <iostream>

using namespace std;

int main() {
	unsigned int horaInicio, minutoInicio;
	unsigned int horaFim, minutoFim;
	
	unsigned int horaTotal, minutoTotal;
	
	cin >> horaInicio >> minutoInicio;
	cin >> horaFim >> minutoFim;
	
	if (horaFim > horaInicio) {
		// mesmo dia
		horaTotal = horaFim - horaInicio;
		if (minutoFim > minutoInicio) {
			minutoTotal = minutoFim - minutoInicio;
		} else if (minutoInicio > minutoFim) {
			minutoTotal = minutoInicio - minutoFim;
			if (minutoTotal < 0) {
				minutoTotal *= -1;
				
			}
			horaTotal--;
		} else if (minutoFim == minutoInicio) {
			minutoTotal = 0;
		}		
	} else if (horaFim < horaInicio) {
		horaTotal = (24 - horaInicio) + horaFim;
		if (minutoFim > minutoInicio) {
			minutoTotal = minutoFim - minutoInicio;
		} else if (minutoInicio > minutoFim) {
			minutoTotal = minutoInicio - minutoFim;
			if (minutoTotal < 0) {
				minutoTotal *= -1;
				
			}
			horaTotal--;	
			//minutoTotal = 60 - minutoTotal;
		} else if (minutoFim == minutoInicio) {
			minutoTotal = 0;
		}			
		
	} else if (horaInicio == horaFim){
		// horas iguais e com minutos iguais ou diferentes
		horaTotal = 0;
		if (minutoFim > minutoInicio) {
			minutoTotal = minutoFim - minutoInicio;
		} else if (minutoInicio > minutoFim) {
			minutoTotal = minutoInicio - minutoFim;
			if (minutoTotal < 0) {
				minutoTotal *= -1;
				
			}
			//horaTotal--;
			//minutoTotal = 60 - minutoTotal;
		} else if (minutoFim == minutoInicio) {
			// minuto igual não passou nada na hora igual
			minutoTotal = 0;
		}			
	} else {
		// se digitar valores negativos...
		horaTotal = 0;
		minutoTotal = 0;
	}
	
	
	cout << horaTotal << " " << minutoTotal << endl;
	
	return 0;
}
