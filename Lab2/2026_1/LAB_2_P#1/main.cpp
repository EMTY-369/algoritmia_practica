

#include "Estructuras.h"
#include "BibliotecaLista/funcionesLista.h"


NodoBaraja* extraer_en_posicion(Baraja &baraja,int posicion) {
    struct NodoBaraja *recorrido = baraja.inicio, *anterior = nullptr;
    int i=1;
    while (recorrido != nullptr) {
        if (i==posicion) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
        i++;
    }
    if (recorrido==nullptr) return nullptr;

    if (anterior == nullptr) baraja.inicio = recorrido->siguiente;
    else anterior->siguiente = recorrido->siguiente;
    if (recorrido == baraja.fin) baraja.fin = anterior;
    else recorrido->siguiente = nullptr;
    return recorrido;
}

void barajar(Baraja &baraja) {
    struct NodoBaraja *zona_barajado = nullptr;
    //siento que el final esta por las considerar ello
    int pendientes = baraja.longitud;
    while (pendientes!=1) {
        int pos = 1 + rand()%pendientes;
        struct NodoBaraja *nodo_extraido = extraer_en_posicion(baraja, pos);
        if (nodo_extraido == nullptr) continue;
        baraja.fin->siguiente = nodo_extraido;
        baraja.fin = nodo_extraido;
        if (zona_barajado == nullptr) zona_barajado = baraja.fin;

        pendientes--;
    }
}

void crear_baraja(struct Baraja & baraja) {
    construir_b(baraja);

    for (int i=0; i < 4; i++) {
        for (int j=0; j < 13; j++) {
            struct Carta c;
            c.numero=13-j;
            c.palo=(char)((i==0)*(int)'E'+(i==1)*(int)'T'+(i==2)*(int)'D'+(i==3)*(int)'C');
            insertarAlInicio_b(baraja, c);
        }
    }
}

int main() {
    srand(time(nullptr));
    struct Baraja baraja;

    crear_baraja(baraja);
    cout<<"BARAJA ORIGINAL"<<endl;
    imprimir(baraja);
    cout<<"BARAJADO"<<endl;
    barajar(baraja);
    imprimir(baraja);
    cout<<"LIBERAR MEMORIA"<<endl;
    destruir(baraja);
    imprimir(baraja);


    return 0;
}
