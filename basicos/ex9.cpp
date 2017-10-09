#include <iostream>

using namespace std;

int main() {
    // largura da janela e altura da janela nas suas coordenadas
    int largura_janela, altura_janela; 
    // posicao x e y do mouse em relacao as coordenadas da janela            
    int x_mouse, y_mouse;
    // pontos x e y nas coordenadas dos dados, plano cartesiano
    double x, y;
    

    cin >> largura_janela >> altura_janela;
    cin >> x_mouse >> y_mouse;

    // pega o valor do x na janela e faz sua proporcao 
    x = (double) (2*x_mouse - largura_janela)/largura_janela;
    // pega o valor do y na janela e faz sua proporcao
    // negativo pelas suas coordenadas serem ao contrário das padroes
    y = (double) (2*y_mouse - altura_janela) / altura_janela;
    y = y * (-1.0);

    cout << x << endl;
    cout << y << endl;

    return 0;
}