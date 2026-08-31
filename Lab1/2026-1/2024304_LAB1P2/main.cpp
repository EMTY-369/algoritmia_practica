#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>

using namespace std;


void inicializar_arreglos_int(int * arr, int n, int valor) {
    for (int i = 0; i < n; i++) arr[i] = valor;
}

void conver(int num, int tamanio, int base, int * cromo) {
    int res, i=0;

    inicializar_arreglos_int(cromo, tamanio, 0);

    while (num>0) {
        res = num % base;
        num = num / base;
        cromo[i] = res;
        i++;
    }
}

bool validar(int * d_parcial, int * citas, int * g_parcial, int * max_ganancias, int n) {

    for (int i = 0; i < n; i++) {
        if (d_parcial[i] > citas[i]) return false;
    }

    for (int i = 0; i < n; i++) {
        if (g_parcial[i] < max_ganancias[i]) return false;
    }

    return true;
}


void actualizar(int * d_parcial, int * g_parcial, int * cromo, int * tipo, int * cantidad_caries, int * duracion,
               int * ganancia, int n_dientes) {
    for (int j = 0; j < n_dientes; j++) {
        int cita = cromo[j], ubi = j;
        if (cita>0) {
            d_parcial[cita-1] += duracion[tipo[ubi] - 1];
            g_parcial[cita-1] += ganancia[tipo[ubi] - 1] * cantidad_caries[ubi];
        }
    }
}

void imprimir_respuesta(int * cromo, int * g_mejor, int * d_mejor, int n_dientes, int n_citas) {
    for (int i = 0; i < n_citas; i++) {
        cout << "CITA #" << i+1 << " LOS DIENTES SON:";
        for (int j = 0; j < n_dientes; j++) {
            if (cromo[j] == i+1) cout << setw(4) << j+1;
        }
        cout <<"  CON GANANCIA DE: "<<g_mejor[i]<<"  CON DURACION DE: "<<d_mejor[i]<< endl;
    }
}

void maximizar(int *tipo, int *duracion, int *ganancia, int *cantidad_caries, int *citas, int n_dientes,
               int n_citas, int opciones, int *cromo) {
    int mejor_combinacion = 0, max_ganancias[n_citas];
    int g_mejor[n_citas], d_mejor[n_citas];
    inicializar_arreglos_int(max_ganancias, n_citas, INT_MIN);
    inicializar_arreglos_int(g_mejor, n_citas, 0);
    inicializar_arreglos_int(d_mejor, n_citas, 0);

    for (int i = 0; i < opciones; i++) {
        int g_parcial[n_citas], d_parcial[n_citas];
        inicializar_arreglos_int(g_parcial, n_citas, 0);
        inicializar_arreglos_int(d_parcial, n_citas, 0);

        if (i == 37984) {
            cout<<endl;
        }

        conver(i, n_dientes, n_citas+1, cromo);

        actualizar(d_parcial, g_parcial, cromo, tipo, cantidad_caries, duracion, ganancia, n_dientes);


        if (validar(d_parcial, citas, g_parcial, max_ganancias, n_citas)) {
            mejor_combinacion = i;
            for (int j = 0; j < n_citas; j++) {
                max_ganancias[j] = g_parcial[j];
            }
        }
    }


    conver(mejor_combinacion, n_dientes, n_citas+1, cromo);
    actualizar(d_mejor, g_mejor, cromo, tipo, cantidad_caries, duracion, ganancia, n_dientes);

    imprimir_respuesta(cromo, g_mejor, d_mejor, n_dientes, n_citas);
}

int main() {
    int tipo[] = {1, 1, 2, 3, 3, 4, 4, 4};
    int cantidad_caries[] = {3, 1, 0, 1, 2, 1, 2, 3};

    int duracion[] = {5, 7, 10, 12};
    int ganancia[] = {20, 30, 35, 42};

    int citas[] = {60, 45, 50};

    int n_dientes = sizeof(tipo) / sizeof(tipo[0]), n_citas = sizeof(citas) / sizeof(citas[0]);
    int opciones = (int)pow(n_citas+1, n_dientes);
    int cromo[n_dientes];

    maximizar(tipo, duracion, ganancia, cantidad_caries,
              citas, n_dientes, n_citas, opciones, cromo);

    return 0;
}
