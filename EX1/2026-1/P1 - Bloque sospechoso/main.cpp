#include <iostream>
#include <iomanip>
using namespace std;
#define F 5
#define C 6

int calcular_area(int arr[][C], int a, int b, int H, int W) {
    int suma = 0, limit1=F, limit2=C;
    if ((a+H)>F or (b+W)>C) return 0;
    for (int i = a; i < a+H; i++) {
        for (int j = b; j < b+W; j++) {
            suma += arr[i][j];
        }
    }
    return suma;
}

void imprimir_bloques_sospechoso(int arr[][C], int H, int W, int U) {
    int n = 1;
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {

            for (int k = 1; k <= H; k++) {
                for (int l = 1; l <= W; l++) {
                    int area = calcular_area(arr, i, j, k, l);

                    if (area > U) {
                        cout << "Bloque sospechoso "<<n<<":"<< endl;
                        cout << "Fila inicial: " << i << endl;
                        cout << "Columna inicial: " << j << endl;
                        cout << "Fila final: " << i+k-1 <<endl;
                        cout << "Columna final: " << j+l-1 <<endl;
                        cout << "Suma: "<< area << endl << endl;
                        n++;
                    }
                }
            }

        }
    }

}

int main() {
    int H=3, W=2, U=80;
    int trafico[][C] =  {{4, 1, 3, 2, 5, 1}, {10, 35, 2, 1, 4, 3}, {8, 30, 5, 2, 6, 4}, {1, 25, 20, 3, 2, 1}, {2, 1, 15, 40, 3, 2}};


    cout << "Matriz evaluada:"<< endl;
    for (int i=0; i<F; i++) {
        for (int j=0; j<C; j++) {
            cout <<setw(2)<< trafico[i][j] << "      ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Altura máxima del bloque: "<<H<<endl;
    cout << "Ancho máximo del bloque: "<<W<<endl;
    cout << "Umbral sospechoso: "<<U<<endl<<endl;

    imprimir_bloques_sospechoso(trafico,H,W,U);

    return 0;
}
