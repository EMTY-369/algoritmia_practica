#include <iostream>
#include "BibliotecaPila/funcionesPila.h"
using namespace std;
#define N 4
#define M 5


int robot_jardinero(int jardin[N][M], int n, int m) {
    int max=0, arr_aux[m+1]{};
    struct Pila p_aux;
    construir(p_aux);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (jardin[i][j] == 1) arr_aux[j]++;
            else arr_aux[j] = 0;
        }
        int k=0, ancho, area;
        while (true) {
            if (k==m and esPilaVacia(p_aux)) break;
            struct Ele ele{};
            ele.col = k;
            ele.altura = arr_aux[k];
            if (esPilaVacia(p_aux)) {
                apilar(p_aux, ele);
                k++;
            }
            else {
                if (cima(p_aux).altura >= arr_aux[k]) {
                    struct Ele ele_aux=desapilar(p_aux);
                    if (esPilaVacia(p_aux)) ancho = ele.col;
                    else ancho = ele.col - cima(p_aux).col - 1;
                    area = ancho*ele_aux.altura;
                    if (max < area) max = area;
                } else {
                    apilar(p_aux, ele);
                    k++;
                }
            }
        }
    }
    return max;
}

int main() {
    int jardin[N][M] = {
        {1, 1, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 0}
    };

    int max = robot_jardinero(jardin, N, M);
    cout << max;

    return 0;
}
