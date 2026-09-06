#include <complex>
#include <iostream>
#define N 6
#define M 11
using namespace std;

bool robot_minero(int x,int y, int galeria,char matriz[N][M]) {
    //es una modificiacion del ejercio, mejora el rellenado de las galerias.
    bool borrar=true;
    if (y==0) while (matriz[x][y]!=' ') x++;
    if (x>N) return borrar;
    matriz[x][y] = '0' + galeria;
    if (y+1>=M and matriz[x+1][y]!=' ') return false;

    if (matriz[x][y+1]!=' ' and x-1>=0 and matriz[x-1][y]!='*' and y+1<M) borrar=robot_minero(x-1, y, galeria, matriz);
    if (matriz[x][y+1]==' ' and matriz[x+1][y]!=' ') borrar=robot_minero(x, y+1, galeria, matriz);
    if (matriz[x+1][y]==' ') borrar=robot_minero(x+1, y, galeria, matriz);

    if (borrar) matriz[x][y]=' ';
    return borrar;
}

int main() {

    char matriz[N][M]{};
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            matriz[i][j]=' ';
        }
    }
    //matriz[5][8] = '*';
    matriz[4][5] = '*';
    matriz[3][5] = '*';

    for (int i=0;i<N;i++) robot_minero(N-i-1, 0,i+1,matriz);

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
