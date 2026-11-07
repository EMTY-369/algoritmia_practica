#include <iostream>
#include <iomanip>
using namespace std;
#define N 10

int max_pureza_muestra(int * arr, int ini, int fin) {
    if (ini == fin) return arr[ini];
    int med = (ini+fin)/2;

    int num1 = max_pureza_muestra(arr, ini, med);
    int num2 = max_pureza_muestra(arr, med+1, fin);
    if (num1>num2) return num1;
    else return num2;
}

int max_pureza(int mina[][N], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        int num=max_pureza_muestra(mina[i], 0, n-1);

        if (max<num) max = num;
    }
    return max;
}

int cant_niveles(int * arr, int ini, int fin, int is_end) {
    if (arr[ini]!=0 and arr[fin]!=0) return 0;

    int med = (ini+fin)/2;
    if (fin==ini+1) {
        if (arr[ini]==0) return med+1;
        else return N-med-1;
    }

    if (is_end) {
        if (arr[med]!=0) return cant_niveles(arr, med, fin, is_end);
        else return cant_niveles(arr, ini, med, is_end);
    } else {
        if (arr[med]!=0) return cant_niveles(arr, ini, med, is_end);
        else return cant_niveles(arr, med, fin, is_end);
    }
}

void muestras_mayor_niveles(int mina[][N], int n) {
    int dif_ceros[n], max=0;

    for (int i = 0; i < n; i++) {
        int num = cant_niveles(mina[i], 0, n-1, mina[i][n-1]==0);
        num = n-num;
        cout <<"Niveles de la muestra "<<i+1<<": "<< num << endl;
        dif_ceros[i]=num;
        if (max<num) max = num;
    }

    cout <<"Maximo de la muestra: "<<max<<endl;
    cout <<"Muestras con mayor cantidad de niveles: ";
    for (int i = 0; i < n; i++) {
        if (max==dif_ceros[i]) cout << i+1 << " ";
    }
    cout << endl;
}

int main() {
    int mina[N][N]={
        {0,0,0,3,3,7,5,5,1,1},
        {8,8,10,9,9,5,4,4,2,0},
        {3,5,8,9,7,6,4,2,0,0},
        {9,7,7,4,4,4,2,0,0,0},
        {0,2,2,3,3,4,4,5,3,3},
        {0,0,0,0,0,0,2,3,4,5},
        {1,2,2,3,3,4,3,2,0,0},
        {0,0,0,0,0,0,3,5,5,7},
        {6,5,5,2,2,1,0,0,0,0},
        {3,2,2,0,0,0,0,0,0,0},
    };

    cout<<"Máxima pureza de las muestras: "<<max_pureza(mina, N)<<endl;
    muestras_mayor_niveles(mina, N);

    return 0;
}
