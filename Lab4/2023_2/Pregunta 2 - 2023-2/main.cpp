#include <iostream>
using namespace std;
#define N 11
#define M 8
#define L 5


char encontrarBocaditoExtra(char * arr, int ini, int fin) {
    if (ini == fin) return arr[ini];

    if (ini == fin) return arr[ini];
    int med = (ini + fin) / 2;
    if (med % 2 == 1) med--;                                   // med par
    if (arr[med] == arr[med+1]) return encontrarBocaditoExtra(arr, med + 2, fin);
    return encontrarBocaditoExtra(arr, ini, med);
}

void identificadorBocaditoExtra(char bocaditos[][N], int filas, int col) {

    for (int i = 0; i < filas; i++) {
        if (bocaditos[i][col-1]==' ') continue;

        char bocadito = encontrarBocaditoExtra(bocaditos[i], 0, col-1);

        if (bocadito!=' ') cout << "La fila " << i+1 << " tiene un " << bocadito << "adicional" << endl;
    }

}

int encontrarAsiento(int *arr, int ini, int fin) {
    if (ini == fin) return ini+1;

    int med = (ini + fin) / 2;
    if (ini==med and arr[med]<arr[fin]) return fin+1;
    if (ini==med and arr[med]>arr[fin]) return med+1;


    if (arr[med]<=arr[med+1] and arr[med]>=arr[med-1]) return encontrarAsiento(arr,med, fin);
    else return encontrarAsiento(arr,ini,med);
}

void asientosBocaditosMayorPrecio(int precios[][L], int filas, int col) {

    for (int i = 0; i < filas; i++) {
        int asiento = encontrarAsiento(precios[i], 0, col-1);
        cout << "En la fila " << i+1 << ", el pasajero del asiento " << asiento << " tiene el bocadito más caro que sus 2 vecinos" << endl;
    }
}

int main() {
    char bocaditos[M][N] = {
        {'O','O','C','C','A','A','E','E','R','R','R'},
        {'C','C','A','A','R','R','E','E','B','B',' '},
        {'R','R','E','E','C','C','F','F','A','A',' '},
        {'E','E','F','F','A','A','A','B','B','R','R'},
        {'C','C','C','A','A','R','R','O','O','E','E'},
        {'O','O','C','C','A','A','R','R','E','E',' '},
        {'A','A','F','F','R','R','E','E','O','O',' '},
        {'E','E','A','A','O','O','B','B','F','F',' '},
    };

    identificadorBocaditoExtra(bocaditos, M, N);

    int precios[M][L] = {
        {1,2,3,2,1},
        {2,3,2,2,1},
        {1,2,2,5,3},
        {2,5,3,3,1},
        {2,2,3,2,1},
        {1,2,3,2,1},
        {3,5,2,1,1},
        {2,3,2,1,1},
    };

    asientosBocaditosMayorPrecio(precios, M, L);

    return 0;
}
