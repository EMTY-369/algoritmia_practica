#include <iostream>
using namespace std;

void imprimir_espacios(int i) {
    for (int j = 0; j < i; j++) cout << "  ";
}

void patron(int n, int i) {
    if (n == 1) {                  // ← caso base: detiene la recursión
        imprimir_espacios(i);
        cout << "*" << endl;
        return;
    }

    patron(n / 2, i);              // ← LLAMADA RECURSIVA #1 (la función se llama a sí misma)

    imprimir_espacios(i);
    for (int j = 0; j < n; j++) cout << "* ";
    cout << endl;

    patron(n / 2, i + n / 2);      // ← LLAMADA RECURSIVA #2 (la función se llama a sí misma otra vez)
}

int main() {
    patron(8, 0);
    return 0;
}