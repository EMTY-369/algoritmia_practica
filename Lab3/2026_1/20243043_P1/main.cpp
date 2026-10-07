#include "BibliotecaLista/funcionesLista.h"

int contarOcurrencias(struct Lista &lista, int codigo) {
    int i=0;
    struct NodoLista *recorrido = lista.inicio;
    while (recorrido != nullptr) {
        if (recorrido->elemento.codigo == codigo) i++;
        recorrido = recorrido->siguiente;
    }
    return i;
}

bool verificarExistencia(struct Lista lista, struct ELe ele) {
    struct NodoLista *recorrido = lista.inicio;
    while (recorrido != nullptr) {
        if (recorrido->elemento.codigo == ele.codigo) return true;
        recorrido = recorrido->siguiente;
    }
    return false;
}

int main() {
    int listado[] = {410, 102, 205, 102, 205, 330, 102, 205, 410, 205, 777};
    struct Lista fallidos, sospechosos;
    construir(fallidos);
    construir(sospechosos);
    insertarAlFinal(fallidos, {410});
    insertarAlFinal(fallidos, {102});
    insertarAlFinal(fallidos, {205});
    insertarAlFinal(fallidos, {102});
    insertarAlFinal(fallidos, {205});
    insertarAlFinal(fallidos, {330});
    insertarAlFinal(fallidos, {102});
    insertarAlFinal(fallidos, {205});
    insertarAlFinal(fallidos, {410});
    insertarAlFinal(fallidos, {205});
    insertarAlFinal(fallidos, {777});

    cout << "Lista de intentos fallidos: ";
    imprimir(fallidos);
    struct NodoLista *recorrido = fallidos.inicio;
    while (recorrido != nullptr) {
        int ocurrencias=contarOcurrencias(fallidos, recorrido->elemento.codigo);
        if (ocurrencias >= 3 or verificarExistencia(sospechosos, recorrido->elemento)) {
            if (not verificarExistencia(sospechosos, recorrido->elemento)) insertarAlFinal(sospechosos, recorrido->elemento);
            struct ELe copia = recorrido->elemento;
            recorrido = recorrido->siguiente;
            eliminaNodo(fallidos, copia);
        } else recorrido = recorrido->siguiente;
    }
    cout << "Lista de usuarios sospechosos: ";
    imprimir(sospechosos);
    cout << "Lista depurada: ";
    imprimir(fallidos);

    return 0;
}
