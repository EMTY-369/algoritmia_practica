#include <iostream>
#include <climits>
using namespace std;
#include "Empresa.hpp"
#define M 3

void merge(struct Pedido *&arr, int ini, int med, int fin) {
    int lizq = med-ini+1;
    int lder = fin - med;

    struct Pedido izq[lizq+1];
    struct Pedido der[lder+1];

    for (int i=ini; i<=med; i++)
        izq[i-ini] = arr[i];
    izq[lizq] = {-1, INT_MIN};

    for (int i=med+1; i<=fin; i++)
        der[i-med-1] = arr[i];
    der[lder] = {-1, INT_MIN};

    int p=0, q=0;
    for (int i=ini; i<=fin; i++) {
        if (izq[p].cantidad>der[q].cantidad) {
            arr[i] = izq[p];
            p++;
        } else {
            arr[i] = der[q];
            q++;
        }
    }
}

void mergeSort(struct Pedido *&pedidos, int ini, int fin) {
    if (ini >= fin)  return;

    int med = (ini + fin) / 2;
    mergeSort(pedidos, ini, med);
    mergeSort(pedidos, med + 1, fin);
    merge(pedidos, ini, med, fin);
}

int cantidadHorasProduccionMayor(struct Pedido *pedidos, int n_pedidos) {

    mergeSort(pedidos, 0, n_pedidos-1);
    int max = pedidos[0].cantidad;
    int cant = 0;

    for (int i=0; pedidos[i].cantidad==max; i++) cant++;

    return cant;
}

int buscarEmpresaHorasMenorPico(struct Empresa *empresas,int contador, int n_empresas) {
    static int min=0;
    if (contador==n_empresas) return 0;
    int frecuencia, candidato;

    frecuencia = cantidadHorasProduccionMayor(empresas[contador].pedidos, N);
    candidato = buscarEmpresaHorasMenorPico(empresas, contador+1, n_empresas);

    if (min>frecuencia or min==0) {
        min = frecuencia;
        return contador+1;
    }
    else return candidato;
}

int main() {
    struct Empresa empresas[M] = {
        {{{2,15},{3,12},{4,10},{5,17},{6,15},{7,18},{8,18},{9, 18},{10,12},{11,16}}},
        {{{2,14},{3,17},{4,17},{5,17},{6,17},{7,12},{8,14},{9, 14},{10,12},{11,12}}},
        {{{2,16},{3,18},{4,20},{5,20},{6,15},{7,18},{8,16},{9, 18},{10,18},{11,16}}},
    };


    cout << "Empresa elijida: "<<buscarEmpresaHorasMenorPico(empresas, 0,M) << endl;

    return 0;
}
