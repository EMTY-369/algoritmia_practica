#include <iostream>
using namespace std;
#define N 8
#define M 4


void encontrarMaxPolo(char * almacen, int ini, int fin, char * tipos, int * n_tipos) {
    if (ini == fin) {
        for (int i = 0; i < M; i++) {
            if (almacen[ini] == tipos[i]) n_tipos[i]=1;
        }
        return;
    }

    int med = (ini + fin) / 2;
    int izq[M]{}, der[M]{};
    encontrarMaxPolo(almacen, ini, med, tipos, izq);
    encontrarMaxPolo(almacen, med+1, fin, tipos, der);

    for (int i = 0; i < M; i++) n_tipos[i] = izq[i] + der[i];
}

void calcularMaxTipoPoloVendido(char * almacen, int n, char * tipos, int * n_tipos, char &tipo,
                               int &cantidad) {

    encontrarMaxPolo(almacen, 0, n-1, tipos, n_tipos);
    cantidad = 0;
    for (int i = 0; i < M; i++) {
        if (n_tipos[i]>cantidad) {
            cantidad = n_tipos[i];
            tipo = tipos[i];
        }
    }

}

int main() {
    char almacen[N] = {'A','F','B','F','F','C','C','F'};
    int n = sizeof(almacen)/sizeof(almacen[0]);
    char tipos[M] = {'A','B','C','F'};
    int n_tipos[M]{};

    char tipo;
    int cantidad;
    calcularMaxTipoPoloVendido(almacen, n, tipos, n_tipos, tipo, cantidad);

    cout << "Polos con más unidades: " << tipo << endl;
    cout << "Cantidad de polo: " << cantidad << endl;

    return 0;
}
