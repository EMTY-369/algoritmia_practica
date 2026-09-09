#include <iostream>
#define N 5

using namespace std;

void imprime(int n, int matriz[N][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void pintar(int x, int y,int n, int colIni, int colFin, int matriz[N][N]) {
    if (x<0 or x>n or y<0 or y>n or matriz[x][y]!=colIni) return;

    matriz[x][y] = colFin;

    pintar(x-1,y,n,colIni,colFin,matriz);
    pintar(x,y+1,n,colIni,colFin,matriz);
    pintar(x+1,y,n,colIni,colFin,matriz);
    pintar(x,y-1,n,colIni,colFin,matriz);
}

int main() {

    int matriz[N][N] = {
        {1, 1, 2, 2, 3},
        {1, 2, 2, 0, 1},
        {0, 2, 1, 3, 1},
        {0, 2, 2, 3, 0},
        {0, 0, 1, 2, 3}
    };

    imprime(N, matriz);
    pintar(2,1,N,2,5,matriz);
    cout << endl << endl;
    imprime(N, matriz);

    return 0;
}
