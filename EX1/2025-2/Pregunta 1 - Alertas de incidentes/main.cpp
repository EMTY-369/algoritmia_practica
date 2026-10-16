#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define N 13 //cambiar en caso de agregar más filas
#define M 4
#define CANT_PRI 3
#define HORA_ENTRADA 8
#define HORA_SALIDA 17
#define ALMUERZO_INI 13
#define ALMUERZO_FIN 14
enum Columns {COD, PRI, HINI, DUR};

void conver(int num, int tamanio, int * cromo) {
    int i=0;
    for (int j = 0; j < tamanio; j++) cromo[j] = 0;

    while (num > 0) {
        cromo[i] = num % 2;
        num = num / 2;
        i++;
    }
}

bool validar_tiempo(int horai,int horaf, int *horario) {
    if (((horai >= HORA_ENTRADA and horai < ALMUERZO_INI) or (horai >= ALMUERZO_FIN and horai < HORA_SALIDA))
        and ((horaf > HORA_ENTRADA and horaf <= ALMUERZO_INI) or (horaf > ALMUERZO_FIN and horaf<=HORA_SALIDA))) {

        for (int i=horai; i<horaf; i++) if (horario[i-1] == 1) return false;
        for (int i=horai; i<horaf; i++) horario[i-1] = 1;
        return true;
    }
    return false;
}

bool validar(int *cromo, int *cants_pri, int arr[][M]) {
    int horario[24]{}, contador[CANT_PRI]{};
    for (int i = 0; i < N; i++) {
        if (cromo[i] == 1) {
            if (not validar_tiempo(arr[i][HINI],arr[i][HINI]+arr[i][DUR] + (arr[i][PRI]==1), horario)) return false;
            contador[arr[i][PRI]-1] ++;
        }
    }

    for (int i = 0; i < CANT_PRI; i++) {
        if (cants_pri[i] != contador[i]) return false;
    }
    return true;
}

void atencion_alertas(int lista_alertas[][M], int *cants_pri, int *cromo, int opciones) {

    for (int i = 0; i < opciones; i++) {
        conver(i, N, cromo);

        if (validar(cromo, cants_pri, lista_alertas)) {
            cout << "| ";
            for (int j = 0; j < N; j++) {
                if (cromo[j]==1) {
                    cout << lista_alertas[j][COD]<<" P"<<lista_alertas[j][PRI]<<" | ";
                }
            }
            cout << endl;
        }
    }
}

int main() {

    int lista_alertas[N][M] = {
        {1801, 2, 8, 1},
        {1802, 1, 8, 1},
        {1803, 1, 9, 1},
        {1804, 3, 9, 3},
        {1805, 1, 10, 1},
        {1806, 1, 11, 1},
        {1807, 3, 12, 1},
        {1808, 1, 14, 1},
        {1809, 2, 14, 2},
        {1810, 3, 14, 1},
        {1811, 2, 15, 1},
        {1812, 3, 16, 1},
        {1813, 2, 16, 2}
    };
    int cants_pri[CANT_PRI] = {1, 1, 3};
    int cromo[N]{};
    int opciones = (int)pow(2, N);

    atencion_alertas(lista_alertas, cants_pri, cromo, opciones);

    return 0;
}
