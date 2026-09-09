#include <iostream>

#define N 7

using namespace std;

int buscaServidor(int posible, int oponente, int n, int  mapa[][N]) {
    if (oponente == N) {
        int fil=0, col=0;
        for (int i = 0; i < n; i++) {
            if (i != posible) {
                if (mapa[posible][i] > 0) fil++;
            }
            if (mapa[i][posible] > 0) col++;
        }
        if (fil == n-1 and col ==0) return posible+1;
        return -1;
    }

    if (mapa[posible][oponente]>0) return buscaServidor(posible, oponente+1, n, mapa);
    else return buscaServidor(oponente, oponente+1, n, mapa);
}

int main() {
    int mapa[N][N]={
        {0,0,0,0,0,0,0},
        {10,0,20,30,0,20,40},
        {0,0,0,0,0,100,0},
        {0,0,0,0,0,80,0},
        {50,10,5,10,0,100,4},
        {100,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}
    };


    cout << buscaServidor(0,1,N,mapa) << endl;

    return 0;
}
