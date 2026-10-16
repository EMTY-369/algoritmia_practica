#include "BibliotecaLista/funcionesLista.h"

NodoLista * buscar_elemento(NodoLista * buscador, char buscar) {
    NodoLista *anterior=nullptr;
    while (buscador != nullptr) {
        if (buscador->elemento.tipo == buscar) {
            anterior->siguiente = buscador->siguiente;
            buscador->siguiente = nullptr;
            return buscador;
        }
        anterior=buscador;
        buscador = buscador->siguiente;
    }
    return nullptr;
}

void reodernaLista(struct Lista &lista) {
    NodoLista *recorrido=lista.inicio, *anterior=nullptr;
    int i=1;

    while (recorrido!=nullptr) {
        char buscar;
        if (i%3==1) buscar = 'A';
        if (i%3==2) buscar = 'B';
        if (i%3==0) buscar = 'C';
        i++;

        if (recorrido->elemento.tipo != buscar) {
            NodoLista *ele = buscar_elemento(recorrido, buscar);
            if (ele == nullptr) continue;

            if (anterior==nullptr) lista.inicio = ele;
            else anterior->siguiente = ele;

            ele->siguiente = recorrido;

            if (anterior==nullptr) anterior = lista.inicio;
            else anterior = anterior->siguiente;
        } else {
            anterior = recorrido;
            recorrido = recorrido->siguiente;
        }
    }
}

int main() {
    struct Lista lista;
    construir(lista);

    insertarAlFinal(lista,{7,'B'});
    insertarAlFinal(lista,{2,'A'});
    insertarAlFinal(lista,{9,'C'});
    insertarAlFinal(lista,{5,'A'});
    insertarAlFinal(lista,{6,'B'});

    reodernaLista(lista);

    imprimir(lista);

    destruir(lista);

    construir(lista);

    insertarAlFinal(lista,{3,'C'});
    insertarAlFinal(lista,{9,'A'});
    insertarAlFinal(lista,{8,'C'});
    insertarAlFinal(lista,{4,'A'});

    reodernaLista(lista);

    imprimir(lista);

    return 0;
}
