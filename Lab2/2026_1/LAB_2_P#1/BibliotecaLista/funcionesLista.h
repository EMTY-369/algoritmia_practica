//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal 

#ifndef LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H
#define LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Lista.h"
using namespace std;

void construir(struct Lista & listaTAD);
void construir_b(struct Baraja & b);
bool esListaVacia(const struct Lista & listaTAD);
bool esListaVacia(const struct Baraja & b);
void insertarAlInicio(struct Lista & listaTAD, const struct ElementoLista & elemento);
void insertarAlInicio_b(struct Baraja & b, const struct Carta & carta);
void insertarAlFinal(struct Lista & listaTAD, const struct ElementoLista & elemento);
struct NodoLista * obtenerUltimoNodo(const struct Lista & listaTAD);
void insertarEnOrden(struct Lista & listaTAD, const struct ElementoLista & elemento);
struct NodoLista * obtenerNodoAnterior(const struct Lista & lista, const struct ElementoLista & elemento);
void eliminaNodo(struct Lista & listaTAD, const struct ElementoLista & elemento);
void destruir(struct Lista & listaTAD) ;
void destruir(struct Baraja & b);
void imprimir(const struct Lista & listaTAD);
void imprimir(const struct Baraja &b);
#endif //LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H