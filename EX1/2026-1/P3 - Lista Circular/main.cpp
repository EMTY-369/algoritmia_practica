#include "BibliotecaLista/funcionesLista.h"


void desactivar_nodo(struct Lista &lista, int id) {
    cout << ">>> Nodo "<< id << " cae <<<" << endl;
    struct Nodo *recorrido=lista.inicio;
    for (int i = 0; i < lista.longitud; i++) {
        if (recorrido->ele.node_id == id) {
            recorrido->ele.is_active = false;
            return;
        }
        recorrido = recorrido->next;
    }
}

void calcular_skip_next(struct Lista &lista) {
    struct Nodo *recorrido=lista.inicio;
    for (int i = 0; i < lista.longitud; i++) {
        recorrido->skip_next = recorrido->next->next;
        recorrido = recorrido->next;
    }
}

void auto_healing(struct Lista & lista) {
    struct Nodo *recorrido=lista.inicio;

    for (int i = 0; i < lista.longitud; i++) {
        struct Nodo *analizado = recorrido->next;
        while (true) {
            if (not analizado->ele.is_active) {
                if (analizado == lista.inicio) lista.inicio = lista.inicio->next;
                recorrido->next = recorrido->skip_next;
                calcular_skip_next(lista);
                delete analizado;
                analizado = recorrido->next;
                lista.longitud--;
            } else break;
        }
        recorrido = recorrido->next;
    }
}

void agregar_nodo(struct Lista & listaTAD, const struct Ele & ele) {

    struct Nodo * nuevo;
    nuevo = new struct Nodo;
    nuevo->ele = ele;

    if (listaTAD.inicio == nullptr) listaTAD.inicio = nuevo;
    else {
        struct Nodo *recorrido=listaTAD.inicio;
        while (recorrido->next != listaTAD.inicio) recorrido = recorrido->next;
        recorrido->next = nuevo;
    }
    nuevo->next = listaTAD.inicio;
    listaTAD.longitud++;
}

void imprimir2(struct Lista &lista) {
    cout<<"Anillo ("<<lista.longitud<<" nodos):"<<endl;
    struct Nodo *recorrido=lista.inicio;
    for (int i = 0; i < lista.longitud; i++) {
        cout<<"Nodo "<<recorrido->ele.node_id;
        if (recorrido->ele.is_active) cout<<" [ACTIVO] ";
        else cout<<" [CAIDO] ";
        cout<<"siguiente="<<recorrido->next->ele.node_id<<" skip_next="<<recorrido->skip_next->ele.node_id<<endl;

        recorrido=recorrido->next;
    }
}

int main() {
    int n;
    cout << "N = ";
    cin >> n;

    struct Lista lista;
    construir(lista);

    for (int i = 1; i<=n; i++) {
        agregar_nodo(lista, {i*10, true});
    }
    calcular_skip_next(lista);
    cout << "===Estado inicial==="<< endl;
    imprimir2(lista);
    cout << endl;

    desactivar_nodo(lista, 20);
    cout << endl;
    desactivar_nodo(lista, 30);
    cout << endl;

    imprimir2(lista);
    cout << endl;

    auto_healing(lista);
    imprimir2(lista);

    return 0;
}
