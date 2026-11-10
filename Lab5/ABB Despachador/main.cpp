#include <iostream>
using namespace std;
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"

void despachoTAD(ABB &arbol, int cantidad) {
    if (cantidad==0) return;
    if (esArbolVacio(arbol) and cantidad>0) {
        cout<<"No hay stock para despachar"<<endl;
        cout<<"Faltan "<<cantidad<<endl;
        return;
    }
    NodoABB *izq = minimoArbol(arbol.raiz);

    if (cantidad>=izq->elemento.stock) {
        int faltante = cantidad-izq->elemento.stock;
        arbol.raiz=eliminarRecursivo(arbol.raiz,izq->elemento);
        despachoTAD(arbol,faltante);
    } else izq->elemento.stock -= cantidad;
}

void despacha(NodoABB *&raiz, int cant) {
    if (cant==0) return;
    if (raiz==nullptr and cant>0) {
        cout<<"No hay stock para despachar"<<endl;
        cout<<"Faltan "<<cant<<endl;
        return;
    }

    NodoABB *izq  = minimoArbol(raiz);
    if (cant >= izq->elemento.stock) {
        int faltante = cant-izq->elemento.stock;
        raiz=eliminarRecursivo(raiz, izq->elemento); //esto devuelve el nuevo arbol con el nodo eliminado no modifica la TAD
        despacha(raiz, faltante);
    } else izq->elemento.stock -= cant;
}

int main() {
    ABB arbol;
    int cant=120;
    construir(arbol);
    insertar(arbol,{20261101,100});
    insertar(arbol,{20261015,50});
    insertar(arbol,{20261018,50});
    insertar(arbol,{20261109,100});
    insertar(arbol,{20261220,100});
    recorrerEnOrden(arbol);
    despachoTAD(arbol, cant);
    cout << endl;
    recorrerEnOrden(arbol);

    return 0;
}
