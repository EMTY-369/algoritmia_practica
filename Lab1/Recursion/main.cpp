#include <iostream>

using namespace std;

void triangulo (int a, int b) {
    //if (a>b) return;
    for (int i=0; i<a; i++) cout << "* ";
    cout << endl;
    if (a>=b) return;
    triangulo (a+1, b);
    for (int i=0; i<a; i++) cout << "* ";
    cout << endl;
}

int main() {
    triangulo (3, 5);
    return 0;
}
