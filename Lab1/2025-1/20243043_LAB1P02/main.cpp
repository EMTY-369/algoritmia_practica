#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void converBin(int * cromo, int tamanio, int num) {
    int i=0;
    for (int j = 0; j < tamanio; j++) cromo[j] = 0; // reseteamos el cromo
    while (num > 0) {
        cromo[i] = num % 2;
        num = num / 2;
        i++;
    }
}

bool valid_num(int * cromo) {
    return ((cromo[3]==1 and cromo[0]==0) or (cromo[4]==1 and cromo[0]==0) or
           (cromo[5]==1 and (cromo[0]==0 or cromo[1]==0)) or (cromo[6]==1 and cromo[1]==0) or
           (cromo[7]==1 and (cromo[1]==0 or cromo[2]==0)) or (cromo[9]==1 and (cromo[0]==0 or cromo[1]==0 or cromo[4]==0)));
}

int calcularGasto(int * cromo, int n_recursos, int * costos) {
    int monto=0;
    for (int i = 0; i < n_recursos; i++) monto += cromo[i]*costos[i];
    return monto;
}

void listadoCombiRestriPresupuesto(int *costos, int P, int n_recursos, int options, int *cromo) {
    cout<<"Combinaciones validas (Costo entre "<<P*0.8<<" y "<<P<<" miles):"<<endl;

    for (int i = 0; i < options; i++) {
        converBin(cromo, n_recursos, i);

        if (valid_num(cromo)) continue;
        int gasto = calcularGasto(cromo, n_recursos, costos);

        if (gasto <= P and gasto >= (P*0.8)) {
            cout << "Combinacion "<<i+1<<": Recursos: ";
            for (int j = 0; j < n_recursos; j++) {
                if (cromo[j]==1) cout << "R" <<j+1 <<" ";
            }
            cout << "| Costo: "<<gasto<<" miles"<<endl;
        }
    }

}

int calcularNS(int * cromo, int n_recursos, int * s_nivel) {
    int suma=0;
    for (int i = 0; i < n_recursos; i++) suma += cromo[i]*s_nivel[i];
    return suma;
}

void filtradoNivelSeguridadMin(int * costos, int *s_nivel, int P, int min_seg, int n_recursos, int options,
                               int * cromo) {
    cout<<"Combinaciones validas (Costo entre "<<P*0.8<<" y "<<P<<" miles y Nivel de seguridad >="<<min_seg<<"):"<<endl;
    int n=0;
    for (int i = 0; i < options; i++) {
        converBin(cromo, n_recursos, i);

        if (valid_num(cromo)) continue;
        int gasto = calcularGasto(cromo, n_recursos, costos);
        int nivel_seguridad = calcularNS(cromo, n_recursos, s_nivel );

        if (gasto <= P and gasto >= (P*0.8) and nivel_seguridad >= min_seg) {
            cout << "Combinacion "<<i+1<<": Recursos: ";
            for (int j = 0; j < n_recursos; j++) {
                if (cromo[j]==1) cout << "R" <<j+1 <<" ";
            }
            cout << "| Costo: "<<gasto<<" miles | Nivel de Seguridad: "<<nivel_seguridad<<endl;
            n++;
        }
    }
    if (n==0) cout << "No se encontraron combinaciones que cumplan con lo solicitado."<<endl;
}

int main() {
    int costos[]={50, 40, 80, 70, 85, 140, 55, 130, 30, 150};
    int s_nivel[]={120, 110, 140, 130, 160, 250, 100, 240, 90, 300};

    int n_recursos = sizeof(costos)/sizeof(costos[0]);
    int options = (int)pow(2,n_recursos);
    int cromo[n_recursos];

    int P, min_seg;;
    cout << "Ingrese el presupuesto (en miles de soles): ";
    cin >> P;
    listadoCombiRestriPresupuesto(costos, P, n_recursos, options, cromo);

    cout << "Ingrese el presupuesto (en miles de soles): ";
    cin >> P;
    cout << "Ingrese el nivel de seguridad minimo requerido: ";
    cin >> min_seg;

    filtradoNivelSeguridadMin(costos, s_nivel, P, min_seg, n_recursos, options, cromo);

    return 0;
}
