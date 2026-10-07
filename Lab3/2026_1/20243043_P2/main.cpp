#include "BibliotecaPila/funcionesPila.h"


bool validarSiCumple(int *llegada, int *solicitado, int n) {
    struct Pila p_aux;
    construir(p_aux);
    int i=0;
    for (int j = 0; j < n; j++) {
        apilar(p_aux, {llegada[j]});
        while (true) {
            if (esPilaVacia(p_aux)) break;
            if (cima(p_aux).num == solicitado[i]) {
                desapilar(p_aux);
                i++;
            } else break;
        }
    }
    if (esPilaVacia(p_aux)) return true;
    else return false;
}

int main() {
    int llegada[] = {1,2,3,4,5}, solicitado[] = {5,3,4,2,1};
    int n=sizeof(llegada)/sizeof(llegada[0]);

    bool cumplir = validarSiCumple(llegada, solicitado, n);

    if (cumplir) cout <<"Se puede cumplir con lo solicitado";
    else cout << "No se puede cumplir con lo solicitado";

    return 0;
}
