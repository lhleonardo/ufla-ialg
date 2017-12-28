#include <iostream>
#include <limits>

using namespace std;

void PressEnterToContinue() {
    cout << "Press ENTER to continue... " << flush;
    cin.ignore(numeric_limits<streamsize> ::max(), '\n' );
}
int main () {
    cout << "Olá!" << endl;
    PressEnterToContinue();
    cout << "Tchau!" << endl;
    return 0;
}
