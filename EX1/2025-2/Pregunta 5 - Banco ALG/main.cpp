#include "BibliotecaCola/funcionesCola.h"

void atender(int cant, struct Cola &cola) {
    cout << "Atender "<< cant << endl;
    for (int i = 0; i < cant; i++) {
        struct ElementoCola ele = desencolar(cola);
        cout << "Atendido: "<<ele.cod<<" (P"<<(int)(ele.tipo=='P' + (ele.tipo=='R')*2)<<")"<<endl;
    }
}

int main() {
    struct Cola fifo;
    construir(fifo);

    encolar(fifo,{1001,'R'});
    encolar(fifo,{1002,'P'});
    atender(1, fifo);
    encolar(fifo, {1004, 'R'});
    encolar(fifo, {1005, 'P'});
    imprimir(fifo);
    atender(3, fifo);
    imprimir(fifo);

    return 0;
}
