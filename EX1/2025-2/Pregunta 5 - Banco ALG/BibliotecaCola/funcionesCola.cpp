//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include "funcionesCola.h"

void construir(struct Cola & colaTAD){
    colaTAD.inicio = nullptr;
    colaTAD.last1 = nullptr;
    colaTAD.fin = nullptr;
    colaTAD.longitud = 0;
}

/*devuelve la longitud de la cola*/
int longitud(const struct Cola & colaTAD) {
    return colaTAD.longitud;
}

void encolar(struct Cola &colaTAD, const struct ElementoCola & elemento){
    cout << "Llegada "<<elemento.cod;
    if (elemento.tipo == 'P') cout << " preferente";
    else cout << " regular";
    cout << endl;

    struct NodoCola *nuevo;
    nuevo = new NodoCola{};
    nuevo->elemento = elemento;
    if(esColaVacia(colaTAD)){
        if (elemento.tipo == 'P') {
            colaTAD.last1 = nuevo;
        }
        colaTAD.inicio = nuevo;
        colaTAD.fin = nuevo;
    }
    else {
        if (elemento.tipo == 'P') {
            if (colaTAD.last1 == nullptr) {
                nuevo->siguiente = colaTAD.inicio;
                colaTAD.inicio = nuevo;
                colaTAD.last1 = nuevo;
            } else {
                nuevo->siguiente = colaTAD.last1->siguiente;
                colaTAD.last1->siguiente = nuevo;
            }
        } else {
            colaTAD.fin->siguiente = nuevo;
            colaTAD.fin = nuevo;
        }
    }
    colaTAD.longitud++;
}

struct ElementoCola desencolar(struct Cola & colaTAD){
    struct NodoCola * pSale;
    struct ElementoCola elemento;
    pSale = colaTAD.inicio;
    colaTAD.inicio = colaTAD.inicio->siguiente;
    elemento = pSale->elemento;
    colaTAD.longitud--;
    delete pSale;
    return elemento;
}

bool esColaVacia(const struct Cola & colaTAD){
    return colaTAD.inicio == nullptr;
}

void imprimir(const struct Cola & colaTAD) {
    cout << "Imprimiendo..."<<endl;
    if (esColaVacia(colaTAD)) {
        cout << "Estado: [P1:][P2:]" << endl;
    } else {
        struct NodoCola * recorrido = colaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "Estado: [P1: ";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despues del inicio*/
            if (recorrido == colaTAD.last1) {
                cout << "][P2: ";
                estaImprimiendoLaCabeza = 1;
            }
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.cod;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}