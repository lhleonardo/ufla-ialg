#include <iostream>

using namespace std;

int main (){
    int questoes = 1, letra, resposta, count = 0;
    
    while(questoes != 0){
        cin >> questoes;

        if (questoes != 0){
            for(int i = 1; i <= questoes; ++i){
                for(int i = 1; i <= 5; ++i){
                    cin >> resposta;
                    if(resposta <= 127){
                        count = count + 1;
                        letra = i;
                    }
                }
                if(letra == 1 && count == 1){
                    cout << 'A' << endl;
                }else if(letra == 2 && count == 1){
                    cout << 'B' << endl;
                }else if(letra == 3 && count == 1){
                    cout << 'C' << endl;
                }else if(letra == 4 && count == 1){
                    cout << 'D' << endl;
                }else if(letra == 5 && count == 1){
                    cout << 'E' << endl;
                }else{
                    cout << "*" << endl;
                }
                count = 0;
            }
        }
    }
}
