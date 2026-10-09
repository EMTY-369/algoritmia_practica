#include "BibliotecaLista/funcionesLista.h"

void buscar_mayor_menor(struct Lista &lista, int &pos_mayor, int &pos_menor, int i) {
    struct Nodo *recorrido = lista.inicio;
    //pos_mayor = 0; pos_menor = 0;
    int num, n=1, mayor = INT_MIN, menor = INT_MAX;
    while (recorrido != nullptr) {
        if (i==1) num = recorrido->elemento.cant_likes;
        if (i==2) num = recorrido->elemento.unid_vendidas;

        if (num > mayor) {
            mayor = num;
            pos_mayor = n;
        }
        if (num < menor) {
            menor = num;
            pos_menor = n;
        }
        n++;
        recorrido = recorrido->siguiente;
    }
}

void intercambiar_posiciones(struct Lista &lista, int pos_mayor, int pos_menor) {
    struct Nodo *mayor_atras, *menor_atras, *mayor, *menor, *recorrido=lista.inicio;
    int i=1;
    bool inicio_mayor = false, inicio_menor = false;
    while (recorrido != nullptr) {
        if (i == (pos_menor-1)) menor_atras = recorrido;
        else if (pos_menor-1==0) inicio_menor = true;
        if (i == (pos_mayor-1)) mayor_atras = recorrido;
        else if (pos_mayor-1==0) inicio_mayor = true;
        if (i == pos_mayor) mayor = recorrido;
        if (i == pos_menor) menor = recorrido;

        i++;
        recorrido = recorrido->siguiente;
    }
    if (inicio_menor) lista.inicio = mayor;
    else menor_atras->siguiente = mayor;

    if (inicio_mayor) lista.inicio = menor;
    else mayor_atras->siguiente = menor;

    recorrido = mayor->siguiente;
    mayor->siguiente=menor->siguiente;
    menor->siguiente=recorrido;
}

void ordenar_lista(struct Lista &lista) {
    int pos_mayor, pos_menor;

    buscar_mayor_menor(lista, pos_mayor, pos_menor, 1);
    intercambiar_posiciones(lista, pos_mayor, pos_menor);
    buscar_mayor_menor(lista, pos_mayor, pos_menor, 2);
    intercambiar_posiciones(lista, pos_mayor, pos_menor);

}

int main() {
    struct Lista libros;
    construir(libros);

    insertarAlFinal(libros, {"L001", "Cien Años de Soledad", 200, 400});
    insertarAlFinal(libros, {"L002", "1984", 600, 5000});
    insertarAlFinal(libros, {"L003", "El Principito", 120, 7500});
    insertarAlFinal(libros, {"L004", "Harry Potter", 1200, 12000});
    insertarAlFinal(libros, {"L005", "Sapiens", 350, 1000});
    insertarAlFinal(libros, {"L006", "Don Quijote", 400, 780});
    insertarAlFinal(libros, {"L007", "Fahrenheit 451", 250, 4500});
    insertarAlFinal(libros, {"L008", "Orgullo y Prejuicio", 678, 23000});

    imprimir(libros);

    ordenar_lista(libros);
    cout << endl;
    imprimir(libros);

    destruir(libros);
    return 0;
}
