#include <iostream>
#include <cstring>
using namespace std;
#include "Estructuras/Lista.hpp"


void insertar_final(struct Lista &lista, int id, const char *nombre, const char *color) {
    struct Nodo *nuevo_nodo = new Nodo{};
    nuevo_nodo->ele.id = id;
    strcpy(nuevo_nodo->ele.nombre, nombre);
    strcpy(nuevo_nodo->ele.color, color);
    nuevo_nodo->sig = nullptr;

    if (lista.ultimo == nullptr) {
        lista.inicio = nuevo_nodo;
        lista.ultimo = nuevo_nodo;
    } else {
        lista.ultimo->sig = nuevo_nodo;
        lista.ultimo = nuevo_nodo;
    }
}

void imprimir(const struct Lista & lista) {
    struct Nodo *recorrido = lista.inicio;

    while (recorrido != nullptr) {
        cout <<"[ID: "<< recorrido->ele.id <<", Nombre: "<<recorrido->ele.nombre<<", Equipo: "<<recorrido->ele.color<<"]"<<endl;
        recorrido = recorrido->sig;
    }
}

void ordenar( struct Lista & lista) {
    struct Nodo *recorrido = lista.inicio, *aux = nullptr;
    lista.inicio = nullptr;
    lista.ultimo = nullptr;
    while (recorrido != nullptr) {
        aux = recorrido->sig;
        recorrido->sig = nullptr;
        if (lista.inicio == nullptr) {
            lista.inicio = recorrido;
            lista.ultimo = recorrido;
            if (recorrido->ele.id%2 == 0) lista.fin_pares =recorrido;
        } else {
            if (recorrido->ele.id%2==0) {
                if (lista.fin_pares == nullptr) {
                    recorrido->sig = lista.inicio;
                    lista.inicio = recorrido;
                } else {
                    recorrido->sig = lista.fin_pares->sig;
                    lista.fin_pares->sig = recorrido;
                }
                lista.fin_pares = recorrido;
            } else {
                lista.ultimo->sig = recorrido;
                lista.ultimo = recorrido;
            }
        }
        recorrido = aux;
    }
}

int main() {
    struct Lista lista;
    lista.inicio = nullptr;
    lista.ultimo = nullptr;
    lista.fin_pares = nullptr;

    insertar_final(lista, 12, "Artax", "verde");
    insertar_final(lista, 9, "Erick", "Blanco");
    insertar_final(lista, 17, "Messala", "Rojo");
    insertar_final(lista, 4, "Ben-Hur", "Azul");
    insertar_final(lista, 7, "Drusus", "Negro");

    cout << endl << "Lista: " << endl << endl;
    imprimir(lista);

    ordenar(lista);
    cout << endl << "Lista: " << endl << endl;
    imprimir(lista);
    return 0;
}
