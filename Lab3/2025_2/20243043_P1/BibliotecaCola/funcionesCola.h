//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef COLA_FUNCIONESCOLA_H
#define COLA_FUNCIONESCOLA_H
#include <iostream>
#include "Cola.h"
using namespace std;

void construir(struct Cola & colaTAD);
void encolar(struct Cola &cola, const struct EleC &colaTAD);
struct EleC desencolar(struct Cola & colaTAD);
bool esColaVacia(const struct Cola & colaTAD);
void imprimir(const struct Cola & colaTAD);

#endif //COLA_FUNCIONESCOLA_H