#include <iostream>
using namespace std;
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"

void insertardv(struct NodoABB *&raiz, int * arr, int ini, int fin) {
    if (ini > fin) return;

    int med = (ini + fin) / 2;

    insertarRecursivo(raiz,{arr[med]});
    insertardv(raiz, arr, ini, med-1);
    insertardv(raiz, arr, med+1, fin);
}

void insertarArreglo(ABB &arbol, int *arr, int n) {

    insertardv(arbol.raiz, arr, 0, n-1);
}

int main() {

    struct ABB arbol;
    int arr[]={2,4,6,8,10,12,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    construir(arbol);
    insertarArreglo(arbol, arr, n);

    recorrerEnOrden(arbol);

    return 0;
}
