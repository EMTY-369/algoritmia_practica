#include "BibliotecaPila/funcionesPila.h"
#define N 5
#define M 6

void robot_minero(char mina[N][M], int xi, int yi, int xf, int yf) {
    struct Pila p_aux;
    construir(p_aux);
    apilar(p_aux,{xi, yi});
    mina[cima(p_aux).y][cima(p_aux).x] = 'R';
    while(true) {
        if (esPilaVacia(p_aux)) break;
        if (cima(p_aux).x >= xf and cima(p_aux).y >= yf) break;
        if (mina[cima(p_aux).y+1][cima(p_aux).x] == '*' or mina[cima(p_aux).y+1][cima(p_aux).x] == 'R' or cima(p_aux).y>=yf) {
            if (mina[cima(p_aux).y][cima(p_aux).x+1] == '*' or mina[cima(p_aux).y][cima(p_aux).x+1] == 'R' or cima(p_aux).x>=xf) {
                struct Ele e = desapilar(p_aux);
            } else {
                apilar(p_aux, {cima(p_aux).x+1,cima(p_aux).y});
                mina[cima(p_aux).y][cima(p_aux).x] = 'R';
            }
        } else {
            apilar(p_aux, {cima(p_aux).x,cima(p_aux).y+1});
            mina[cima(p_aux).y][cima(p_aux).x] = 'R';
        }
    }
}

int main() {
    char mina[N][M] = {
        {'0', '0', '*', '0', '0', '*'},
        {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '*', '0', '0'},
        {'0', '*', '0', '0', '*', '0'},
        {'*', '0', '0', '*', '0', '0'}
    };

    robot_minero(mina, 0, 0, M-1, N-1);

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << mina[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
