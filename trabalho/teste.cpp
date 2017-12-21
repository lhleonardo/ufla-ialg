/*
Faça um programa que receba N números inteiros digitados pelo usuário. 
Feito isso, ordene-os de forma crescente e os salve em um arquivo 
"entrada.dat". Em seguida, leia o arquivo "entrada.dat", faça uma busca 
binária nos números lidos e salve, em outro arquivo como "saida.dat" a 
posição no vetor do número buscado. Salve -1 se o número não for 
encontrado */

#include <iostream>     
#include <fstream>   
using namespace std;

int buscaBin (int entrada[], int ini, int fim, int buscado)
{
    int meio = (ini+fim)/2;
    cout<<ini<<"\t"<<meio<<"\t"<<fim<<endl;
    
    if (ini<=fim)
    {
        cout<<"Meio: "<<entrada[meio]<<endl;
        if (entrada[meio] == buscado)
            return meio;
        else
            if (buscado < entrada[meio])
            {
                cout<<"Meio: "<<entrada[meio]<<endl;
                return buscaBin (entrada, ini, meio-1, buscado);
            }
            else
                return buscaBin (entrada, meio+1, fim, buscado);
    }
    else
        return -1;    

}

void flutuacao (int entrada[], int tam)
{
    int i = 0;
    bool troca = true;
    int aux;
    
    while ((troca) && (i < tam))
    {
        troca = false;
        for (int j=0; j < (tam-1) - i; j++)
        {
            if (entrada[j] > entrada[j+1])
            {
                aux = entrada[j];
                entrada[j] = entrada[j+1];
                entrada[j+1] = aux;
                
                troca = true;
            }    
        }
        i++;
    }
}



int main () 
{
    int qtd; 
    cin>>qtd;
    
    ofstream saida("entrada.dat", ios::binary);
    
    int dado[qtd];
  
    for (int i=0; i<qtd; i++)
    {
        cin>>dado[i];
    }
  
    flutuacao (dado, qtd);
    
    saida.write ((char *) (dado), sizeof(dado));
    saida.close();

    ifstream entrada("entrada.dat", ios::binary);
    ofstream resultado("saida.dat", ios::binary);
    
    if (entrada) 
    {
        entrada.seekg (0, entrada.end);
        int tam = entrada.tellg();
        entrada.seekg (0, entrada.beg);
        
        int busca[tam/sizeof(int)];
                    
        entrada.read ((char *) (busca), tam);
        entrada.close();
        
        for (int i=0; i<qtd; i++)
            cout<<busca[i]<<"\t";
        
        int procura, result;
        cin>>procura;
        
        result = buscaBin(busca,0,qtd-1,procura);
        cout<<result;
        resultado.write ((char *) (&result), sizeof(result));
        resultado.close();

    }
    else
    cout<<"Erro na abertura do arquivo";
  
  
  return 0;
}
