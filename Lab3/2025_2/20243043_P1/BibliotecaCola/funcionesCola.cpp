//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal


#include "funcionesCola.h"

void construir(struct Cola & colaTAD){
    colaTAD.inicio = nullptr;
    colaTAD.fin = nullptr;
    colaTAD.longitud = 0;
}

/*devuelve la longitud de la cola*/
int longitud(const struct Cola & colaTAD) {
    return colaTAD.longitud;
}

void encolar(struct Cola &colaTAD, const struct EleC & elemento){
    struct NodoCola *nuevo;
    nuevo = new NodoCola{};
    nuevo->ele = elemento;
    if(esColaVacia(colaTAD)){
        colaTAD.inicio = nuevo;
        colaTAD.fin = nuevo;
    }
    else {
        colaTAD.fin->siguiente = nuevo;
        colaTAD.fin = nuevo;
    }
    colaTAD.longitud++;
}

struct EleC desencolar(struct Cola & colaTAD){
    struct NodoCola * pSale;
    struct EleC elemento;
    pSale = colaTAD.inicio;
    colaTAD.inicio = colaTAD.inicio->siguiente;
    elemento = pSale->ele;
    colaTAD.longitud--;
    delete pSale;
    return elemento;
}

bool esColaVacia(const struct Cola & colaTAD){
    return colaTAD.inicio == nullptr;
}

void imprimir(const struct Cola & colaTAD) {
    if (esColaVacia(colaTAD)) {
        cout << "La cola esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoCola * recorrido = colaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despues del inicio*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->ele.num;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}