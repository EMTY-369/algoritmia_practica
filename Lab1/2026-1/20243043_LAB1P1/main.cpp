#include <iostream>

using namespace std;
#define N 10
#define M 10

int buscarArtefacto(int x, int y, int alcance, int direccion, char mapa[N][M]) {
    int cont=0;
    if (mapa[x][y]=='A') cont=1;
    mapa[x][y]='*';
    if (alcance < 0) return 0;
    if (direccion <= 0) {
        cont+=buscarArtefacto(x-1, y-1, alcance-1, -1, mapa);
        cont+=buscarArtefacto(x-1, y, alcance-1, -1, mapa);
        cont+=buscarArtefacto(x-1, y+1, alcance-1, -1, mapa);
    }
    if (direccion >=0 ) {
        cont+=buscarArtefacto(x+1, y-1, alcance-1, 1, mapa);
        cont+=buscarArtefacto(x+1, y, alcance-1, 1, mapa);
        cont+=buscarArtefacto(x+1, y+1, alcance-1, 1, mapa);
    }
    return cont;
}

int main() {
    char mapa[N][M]{};
    mapa[3][3]='A';
    mapa[3][4]='A';
    mapa[4][5]='A';
    mapa[5][4]='A';
    mapa[5][7]='A';
    mapa[7][5]='A';

    cout << buscarArtefacto(5, 5, 3, 0, mapa)<<endl;


    return 0;
}
