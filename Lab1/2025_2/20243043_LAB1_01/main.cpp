#include <iostream>
#include <cmath>

using namespace std;

void conver_bin(int num, int * cromo, int n) {
    int res, i=0;

    for (int j=0; j<n; j++) cromo[j]=0;

    while (num>0) {
        res = num%2;
        num = num/2;
        cromo[i] = res;
        i++;
    }
}

void actualizar(int &p_parcial, int &b_parcial, int &fn_parcial, int * cromo, int *c, int *b, int *fn, int n) {
    for (int i=0; i<n; i++) {
        if (cromo[i] == 1) {
            p_parcial+=c[i];
            b_parcial+=b[i];
            fn_parcial+=fn[i];
        }
    }
}

void imprimir_recursos(int * cromo, int n) {
    bool coma = false;
    cout<<"Recursos: {";
    for (int i=0; i<n; i++) {
        if (cromo[i] == 1) {
            if (coma) cout<<",";
            cout<<i+1;
            coma = true;
        }
    }
    cout<<"}, ";
}

void imprimir_opciones(int *costo, int *beneficio, int *falsos_negativos, int options, int n, int *cromo, int P, int B, int F) {

    for (int i = 0; i < options; i++) {
        int p_parcial=0, b_parcial=0, fn_parcial=0;
        conver_bin(i, cromo, n);
        actualizar(p_parcial, b_parcial, fn_parcial, cromo, costo, beneficio, falsos_negativos,n);

        if (p_parcial <= P and b_parcial >= B and fn_parcial <= F) {
            imprimir_recursos(cromo, n);
            cout<<"Costo Total: "<<p_parcial<<", Beneficio: "<<b_parcial<<", Falsos Negativos:  "<<fn_parcial<<endl;
        }

    }
}

int main() {
    int costo[] = {35000, 24000, 30000, 27000, 10000, 7000, 6000, 40000};
    int beneficio[] = { 80, 60, 70, 48, 20, 35, 10, 40};
    int falsos_negativos[] = { 1, 3, 2, 1, 1, 2, 1, 3};

    int n = sizeof(costo) / sizeof(costo[0]);
    int options = (int)pow(2,n);
    int cromo[n];

    int P=70000, B=150, F=5;

    imprimir_opciones(costo, beneficio, falsos_negativos, options, n, cromo, P, B, F);

    return 0;
}
