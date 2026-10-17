#include "BibliotecaPila/funcionesPila.h"

bool determinar_secuencia_validaU(char * secuencia, int n) {
    struct Pila aux;
    construir(aux);
    for (int i = 0; i < n; i++) {

        if (secuencia[i]>='A' and secuencia[i]<='Z') {
            apilar(aux, {secuencia[i]});
        }
        if (secuencia[i]>='a' and secuencia[i]<='z') {
            if (cima(aux).empleado == (secuencia[i] - ('a'-'A'))) desapilar(aux);
            else return false;
        }
    }

    if (not esPilaVacia(aux)) return false;
    return true;
}

int main() {
    char secuencia[] = {'A','B','b','a','C','c','A','a'};
    int n = sizeof(secuencia)/sizeof(secuencia[0]);

    bool valid = determinar_secuencia_validaU(secuencia, n);
    if (valid) cout << "Salida: Secuencia válida" << endl;
    else cout << "Salida: Secuencia inválida" << endl;
    return 0;
}
