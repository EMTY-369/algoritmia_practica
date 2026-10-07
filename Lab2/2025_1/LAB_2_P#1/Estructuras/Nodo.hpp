//
// Created by User on 25/09/2026.
//

#ifndef LAB_2_P_1_NODO_HPP
#define LAB_2_P_1_NODO_HPP
#include "Elemento.hpp"
struct Nodo {
    struct Elemento ele;
    struct Nodo *sig;
};
#endif //LAB_2_P_1_NODO_HPP
