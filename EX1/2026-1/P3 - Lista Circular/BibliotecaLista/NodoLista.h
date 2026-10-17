//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef LISTASIMPLEMENTEENLAZADA_NODOLISTA_H
#define LISTASIMPLEMENTEENLAZADA_NODOLISTA_H
#include "ElementoLista.h"
struct Nodo {
    struct Ele ele;
    struct Nodo * next;
    struct Nodo * skip_next;
};
#endif //LISTASIMPLEMENTEENLAZADA_NODOLISTA_H