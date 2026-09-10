#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void converBin(int * cromo, int num, int tamanio) {
    int i=0;
    for (int j=0; j<tamanio; j++) cromo[j] = 0;

    while (num>0) {
        cromo[i] = num%2;
        num = num/2;
        i++;
    }
}

void combinaciones(char *letras, int n_letras, char **palabras, int n_palabras, int * cromo, int options) {
    int cant_comb[n_palabras]{};

    for (int i = 0; i < options; i++) {
        converBin(cromo, i , n_letras);
        char buffer[9]{};
        int n=0;
        for (int j = 0; j < n_letras; j++) {
            if (cromo[j]==1) {
                buffer[n] = letras[j];
                cout << letras[j];
                buffer[n+1] = '\0';
                n++;
            }
        }
        cout << endl;

        for (int j = 0; j < n_palabras; j++) {
            int cont=0;
            if (strlen(palabras[j]) != strlen(buffer)) continue;
            char buffer2[9]{};
            strcpy(buffer2, buffer);
            for (int k = 0; palabras[j][k]; k++) {
                for (int l = 0; buffer2[l]; l++) if (palabras[j][k]==buffer2[l]) {
                    cont++;
                    buffer2[l] = ' ';
                    break;
                }
            }
            if (cont==strlen(palabras[j])) cant_comb[j]++;
        }
    }

    for (int i = 0; i < n_palabras; i++) {
        cout << "La palabra "<<palabras[i]<<" tiene "<<cant_comb[i]<<" combinaciones de Letras."<<endl;
    }
}

int main() {
    int n_letras, n_palabras;
    char letras[10]{};
    char *palabras[8]{}, buffer[9]{};
    cout << "Digite la cantidad y las letras de produccion: ";
    cin >> n_letras;
    cout << endl;
    for (int j = 0; j < n_letras; j++) {
        cin >> letras[j];
    }

    cout << "Ingrese la cantidad y las palabras a formar: ";
    cin >> n_palabras;
    cout << endl;
    for (int i = 0; i < n_palabras; i++) {
        palabras[i] = new char[9];
        cin >> buffer;
        strcpy(palabras[i], buffer);
    }

    int options = (int) pow(2,n_letras);
    int cromo[n_letras];

    combinaciones(letras, n_letras, palabras, n_palabras, cromo, options);

    return 0;
}
