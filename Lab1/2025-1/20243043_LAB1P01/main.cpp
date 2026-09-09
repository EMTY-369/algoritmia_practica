#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

void conver(int tamanio, int num, int * cromo, int base) {
    int i=0;

    for (int j=0; j<tamanio; j++) cromo[j]=0;

    while (num>0) {
        cromo[i] = num%base;
        num = num/base;
        i++;
    }
}

int determinar_menor_velocidad(int * cromo, int * tablas, int * discos, int n_tablas, int n_discos) {
    int suma_t[n_discos]{};
    for (int i = 0; i < n_tablas; i++) {
        int numD = cromo[i];
        if (numD!=0) suma_t[numD-1] += tablas[i];
        else return -1;
    }

    int menor = INT_MAX;
    for (int i = 0; i < n_discos; i++) {
        if (suma_t[i] > discos[i] or suma_t[i]<=0) return -1;
        if ((discos[i]-suma_t[i]) < menor) menor = discos[i]-suma_t[i];
    }
    return menor;
}

void optimizacion(int *tablas, int *discos, int n_tablas, int n_discos, int options, int *cromo) {
    int mayorVM=0, mejor_comp=0;

    for (int i = 0; i < options; i++) {
        conver(n_tablas, i, cromo, n_discos+1);
        int menor_v=determinar_menor_velocidad(cromo, tablas, discos, n_tablas, n_discos);

        if (menor_v==-1) continue;

        if (menor_v>mayorVM) {
            mayorVM = menor_v;
            mejor_comp = i;
        }
    }

    conver(n_tablas, mejor_comp, cromo, n_discos+1);

    for (int i = 0; i < n_discos; i++) {
        cout << "Disco "<< i+1 <<": ";
        for (int j = 0; j < n_tablas; j++) {
            if (cromo[j]==i+1) cout << j+1 << " ";
        }
        cout << endl;
    }
    cout << mayorVM << endl;
}

int main() {
    int tablas[] = {150, 100, 80, 50, 120, 10};
    int discos[] = {250, 200, 200};

    int n_discos = sizeof(discos)/sizeof(discos[0]), n_tablas = sizeof(tablas)/sizeof(tablas[0]);
    int options = (int)pow(n_discos+1, n_tablas);
    int cromo[n_tablas]{};

    optimizacion(tablas, discos, n_tablas, n_discos, options, cromo);

    return 0;
}