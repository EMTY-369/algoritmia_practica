#include "BibliotecaCola/funcionesCola.h"

void generar_n_nums_binarios(int n) {
    struct Cola aux;
    construir(aux);
    int i = 0;

    while (true) {
        if (i == n) break;

        if (esColaVacia(aux)) {
            encolar(aux, {1});
            i++;
        }
        else {
            int p = aux.longitud;
            for (int j = 0; j < p; j++) {
                int num = desencolar(aux).num;
                cout << num << ",";
                encolar(aux, {num*10});
                i++;
                if (i == n) break;
                encolar(aux, {num*10+1});
                i++;
                if (i == n) break;
            }
        }
    }

    while (not esColaVacia(aux)) {
        int num = desencolar(aux).num;
        cout << num << ",";
    }

}

int main() {
    int n;
    cin >> n;

    cout << "Para N=" << n << ", => ";
    generar_n_nums_binarios(n);
    cout << endl;
    return 0;
}
