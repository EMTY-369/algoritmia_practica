#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


void converBin(int * cromo, int num, int n_armas, int base) {
    int i=0;

    for (int j=0; j<n_armas; j++) cromo[j] = 0;

    while(num>0) {
        cromo[i] = num%base;
        num=num/base;
        i++;
    }
}

bool valid(int * cromo, int arma) {
    if (arma == 2 and cromo[1] != cromo[0]) return false;
    if (arma == 4 and cromo[3] != cromo[2]) return false;
    if (arma == 8 and cromo[7] != cromo[0] or cromo[7]!=cromo[4]) return false;
    if (arma == 9 and cromo[8] != cromo[2]) return false;
    if (arma == 11 and cromo[10] != cromo[0]) return false;

    return true;
}

void actualizar(int * suma_poder, int * cromo, int * poder_armas, int * tipo, int n_armas) {
    for (int j=0; j<n_armas; j++) {
        if (cromo[j] == 1 and tipo[j]==2 and valid(cromo, j+1)) suma_poder[0] += poder_armas[j];
        if (cromo[j] == 2 and (tipo[j]==1 or tipo[j]==3) and valid(cromo, j+1)) suma_poder[1] += poder_armas[j];
        if (cromo[j] == 3 and tipo[j]==3 and valid(cromo, j+1)) suma_poder[2] += poder_armas[j];
    }
}

void max_mochila_po(int *poder_enemigos, char *armas, int *poder_armas, int *tipo, int n_armas, int n_enemigos,
                    int options, int * cromo) {
    int mejor_combinación=-1;
    for (int i = 0; i < options; i++) {
        bool solution = true;
        int suma_poder[n_enemigos]{};
        converBin(cromo, i, n_armas, n_enemigos+1);

        actualizar(suma_poder, cromo, poder_armas, tipo, n_armas);

        for (int j = 0; j < n_enemigos; j++) {
            if (suma_poder[j] <= poder_enemigos[j]) solution = false;
        }

        if (solution) {
            mejor_combinación = i;
            for (int j = 0; j < n_enemigos; j++) {
                cout<<"GUERRERO "<<j+1<<" PODER: "<<poder_enemigos[j]<<" ARMAS EN MOCHILA PARA VENCERLO: ";
                for (int k = 0; k < n_armas; k++) {
                    if (cromo[k]==j+1) cout<<armas[k]<<" ";
                }
                cout<<endl;
            }
        }
    }

    // if (mejor_combinación>0) {
    //     converBin(cromo, mejor_combinación, n_armas, n_enemigos+1);
    //     for (int j = 0; j < n_enemigos; j++) {
    //         cout<<"GUERRERO "<<j+1<<" PODER: "<<poder_enemigos[j]<<" ARMAS EN MOCHILA PARA VENCERLO: ";
    //         for (int k = 0; k < n_armas; k++) {
    //             if (cromo[k]==j+1) cout<<armas[k]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // } else {
    //     cout<<"NO HAY SOLUCIONES"<<endl;
    // }

}

int main() {

    int poder_enemigos[]={120,160,80};

    char armas[]={'Z','P','R','D','E','F','G','H','I','J','K','L'};
    int poder_armas[]={60,80,38,25,49,57,68,35,62,42,36,54};
    int tipo[]={3,1,2,2,2,1,3,2,2,2,1,3};
    int n_armas = sizeof(armas)/sizeof(armas[0]), n_enemigos = sizeof(poder_enemigos)/sizeof(poder_enemigos[0]);
    int options = (int) pow(n_enemigos+1, n_armas);
    int cromo[n_armas];

    max_mochila_po(poder_enemigos, armas, poder_armas, tipo, n_armas, n_enemigos, options, cromo);

    return 0;
}
