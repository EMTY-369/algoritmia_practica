#include <iostream>
using namespace std;

#define N 5
#define M 5

int robor_almacen(int x, int y, int mayor, int matriz[N][M]) {
    //if (x == N - 1 and y == M - 1) return mayor;

    if (matriz[x][y] > mayor and y<N and x<M) mayor = matriz[x][y];

    if (y<M-1 and x<N) mayor = robor_almacen(x, y+1, mayor, matriz);
    if (y==M-1 and x<N) mayor = robor_almacen(x+1, 0, mayor, matriz);

    matriz[x][y] = mayor - matriz[x][y];
    return mayor;
}

int main() {

    int matriz[N][M] {
        {4,3,6,8,7},
        {6,3,8,4,10},
        {2,15,1,2,13},
        {5,1,10,11,2},
        {10,4,7,9,4}
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    int max_valor = robor_almacen(0,0, INT_MIN,matriz);
    cout << max_valor << endl<<endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
