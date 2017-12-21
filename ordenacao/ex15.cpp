#include <iostream>
using namespace std;

void Troca(int &A, int &B)
{
	int aux = A;
	A = B;
	B = aux;
}

//A função Merge abaixo está incorreta
void Merge(int V[], int p, int q, int r, int U[])
{
	int a = p;
	int b = q+1;

	for(int i = p; i <= q; i++)
		if( b < r || (a <= q && V[a] < V[b]) )
			U[i] = V[a++];
		else
			U[i] = V[b++];

	for(int i = p; i <= q; i++)
		V[i] = U[i];
}

void MergeSort(int V[], int primeira, int ultima, int U[])
{
	if((primeira-ultima) < 2) return;

	int p = primeira;
	int r = ultima;
	int q = (p+r)/2;
	
	MergeSort(V, p, q, U);
	MergeSort(V, q+1, r, U);
	Merge(V, p, q, r, U);
}


int main() {
	int tam;
	cin >> tam;

	int valores[tam];
	int vetorAux[tam];
	for(int i = 0; i < tam; i++)
		cin >> valores[tam];


	MergeSort(valores, 0, tam, vetorAux);

	for (int i = 0; i < tam; i++)
	{
		cout << valores[i] << " ";
	}
	
	return 0;
}
