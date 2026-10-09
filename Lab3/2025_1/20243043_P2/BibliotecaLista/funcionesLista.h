//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal 

#ifndef LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H
#define LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H
#include <iostream>
#include <iomanip>
#include "Lista.h"
#include <climits>
#include "funcionesLista.h"
using namespace std;

void construir(struct Lista & listaTAD);
bool esListaVacia(const struct Lista & listaTAD);
void insertarAlInicio(struct Lista & listaTAD, const struct Ele & elemento);
void insertarAlFinal(struct Lista & listaTAD, const struct Ele & elemento);
struct Nodo * obtenerUltimoNodo(const struct Lista & listaTAD);
void insertarEnOrden(struct Lista & listaTAD, const struct Ele & elemento);
struct Nodo * obtenerNodoAnterior(const struct Lista & lista, const struct Ele & elemento);
void eliminaNodo(struct Lista & listaTAD, const struct Ele & elemento);
void destruir(struct Lista & listaTAD) ;
void imprimir(const struct Lista & listaTAD);

#endif //LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H