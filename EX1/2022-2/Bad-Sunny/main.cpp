#include "BibliotecaPila/funcionesPila.h"

void dj_robot(int * arr, int n) {
    struct Pila aux;
    construir(aux);
    int max_f = 0, max_dura=0, max_area=0;

    for (int i = 0; i <= n; i++) {
        int actual = (i == n) ? 0 : arr[i];

        while (not esPilaVacia(aux) and cima(aux).frecuencia > actual) {
            struct Ele e;
            while (not esPilaVacia(aux)) {
                e = desapilar(aux);
                if (esPilaVacia(aux)) break;
                if (e.frecuencia != cima(aux).frecuencia) break;
            }
            int duracion;
            if (esPilaVacia(aux)) duracion = i;
            else duracion = i - cima(aux).tiempo;

            if (e.frecuencia * duracion > max_area) {
                max_area = e.frecuencia * duracion;
                max_dura = duracion;
                max_f = e.frecuencia;
            }
        }

        if (i < n) apilar(aux, {i + 1, arr[i]});
    }
    cout << max_dura << "  "<<max_f << endl;
}

int main() {

    struct Pila aux;
    construir(aux);

    int frecuencia[] = {1,2,1,4,5,6,4,5,2,2,1};
    int n = sizeof(frecuencia)/sizeof(frecuencia[0]);

    dj_robot(frecuencia, n);

    return 0;
}
