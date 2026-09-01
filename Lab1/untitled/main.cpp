#include <iostream>
#include <climits>
#define COL 4

using namespace std;

int robot(int x, int y, int n, int m, int table[][COL]) {
    int der=INT_MIN, aba=INT_MIN;
    if (x==n-1 and y==m-1) return table[x][y];
    //derecha
    if (y+1<m) der = robot(x, y+1, n, m, table);
    //abajo
    if (x+1<n) aba = robot(x+1, y, n, m, table);

    if (der>aba) return der+table[x][y];
    return aba+table[x][y];
}

int main() {
    int n=3;
    int m=4;

    int tablero[][COL]={
        {2,5,10,3},
        {6,1,2,1},
        {4,2,5,2},
    };

    int valor = robot(0,0,n,m,tablero);
    cout<< valor <<endl;

    return 0;
}
