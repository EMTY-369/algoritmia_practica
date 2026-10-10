#include "BibliotecaPila/funcionesPila.h"

void submario(char *ordenes, int n) {
    struct Pila aux;
    construir(aux);
    for (int i = 1; i <= n+1; i++) {
        if (ordenes[i-1] == 'S' or i==n+1) {
            cout << i << " ";
            while (not esPilaVacia(aux)) {
                cout << desapilar(aux).numero << " ";
            }
        } else apilar(aux, {i});
    }
}

int main() {
    char ordenes[] = {'S','B','S','S','B','B','B','B','S'};
    int n = sizeof(ordenes)/sizeof(ordenes[0]);

    submario(ordenes,n);
    return 0;
}
