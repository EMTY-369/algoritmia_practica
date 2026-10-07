#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaPila/funcionesPila.h"


bool ordenarColaProductos(struct Cola & cola) {
    struct Pila p_aux;
    construir(p_aux);
    int n=1, m = cola.longitud;
    for (int i = 0; i < m; i++) {
        struct EleC ele = desencolar(cola);
        if (ele.num == n) {
            encolar(cola, ele);
            n++;
        }
        else apilar(p_aux, {ele.num});
    }

    while (not esPilaVacia(p_aux)) {
        if (cima(p_aux).num == n) {
            encolar(cola, {desapilar(p_aux).num});
            n++;
        } else return false;
    }
    return true;
}

int main() {
    struct Cola productos;
    construir(productos);
    encolar(productos, {1});
    encolar(productos, {5});
    encolar(productos, {6});
    encolar(productos, {2});
    encolar(productos, {4});
    encolar(productos, {7});
    encolar(productos, {3});

    imprimir(productos);
    bool ordenado = ordenarColaProductos(productos);
    imprimir(productos);
    if (ordenado) cout << "Si se puede ordenar";
    else cout << "No se puede ordenar";

    return 0;
}
