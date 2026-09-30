#include <iostream>
#define N 10
using namespace std;

void contar(int &fil, int &col, int matriz[N][N], int n, int i, int posible) {
    if (i==n) return;
    if (matriz[posible][i] == 0 and i!=posible) col++;
    if (matriz[i][posible]!=0) fil++;
    contar(fil, col, matriz, n, i+1, posible);
}

int encontrar_canario_ancestral(int posible, int oponente, int n, int matriz[N][N]) {
    if (oponente == n) {
        int fil=0, col=0;
        contar(fil, col, matriz, n, 0, posible);

        if (col == n-1 and fil == n) return posible;
        return -1;
    }

    if (matriz[posible][oponente] == 0) return encontrar_canario_ancestral(posible, oponente+1, n, matriz);
    else return encontrar_canario_ancestral(oponente, oponente+1,n, matriz);
}

int main() {

    int matriz[N][N] {
        {100, 0, 50, 40, 30, 20, 30, 0, 80, 0},
        {50, 100, 0, 40, 30, 20, 20, 0, 10, 25},
        {80, 30, 100, 40, 30, 0, 30, 20, 10, 60},
        {50, 0, 0, 100, 30, 0, 50, 30, 30, 90},
        {50, 10, 10, 10, 100, 0, 10, 50, 10, 50},
        {20, 0, 0, 0, 0, 100, 90, 20, 40, 20},
        {0, 0, 0, 0, 0, 0, 100, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 50, 100, 50, 20},
        {20, 0, 0, 40, 0, 0, 90, 0, 100, 10},
        {0, 10, 0, 0, 0, 0, 10, 0, 60, 100},
    };

    cout<<encontrar_canario_ancestral(0,1,N,matriz)<<endl;
    return 0;
}
