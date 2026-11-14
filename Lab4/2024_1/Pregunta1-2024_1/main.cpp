#include <iostream>
#include <climits>
using namespace std;

int cruceMaximo(int * marcas, int ini, int med, int fin, int &p_ini, int &p_fin) {
    int suma = 0, min_izq=INT_MAX, min_der=INT_MAX;

    for (int i = med; i >= ini; i--) {
        suma += marcas[i];
        if (suma < min_izq) {
            min_izq = suma;
            p_ini = i;
        }
    }
    suma = 0;
    for (int i = med+1; i <= fin; i++) {
        suma += marcas[i];
        if (suma < min_der) {
            min_der = suma;
            p_fin = i;
        }
    }
    int minimo = min(min_izq, min(min_der, min_izq+min_der));

    if (minimo == min_izq) p_fin = med;
    else if (minimo == min_der) p_ini = med+1;

    return minimo;
}

int calcularMayorAcumulaciónNegativa(int *marcas, int ini, int fin, int &p_ini, int &p_fin) {
    if (ini == fin) {
        p_ini = p_fin = ini;
        return marcas[ini];
    }
    int med = (ini + fin) / 2;
    int izq_ini, der_ini, izq_fin, der_fin, cru_ini, cru_fin;
    int miniIzq = calcularMayorAcumulaciónNegativa(marcas, ini, med, izq_ini, izq_fin);
    int miniDer = calcularMayorAcumulaciónNegativa(marcas, med + 1, fin, der_ini, der_fin);
    int miniMed = cruceMaximo(marcas, ini, med, fin, cru_ini, cru_fin);

    int minimo = min(miniIzq, min(miniDer, miniMed));

    if (minimo == miniIzq) {p_ini = izq_ini; p_fin = izq_fin;}
    else if (minimo == miniDer) {p_ini = der_ini; p_fin = der_fin;}
    else {p_ini = cru_ini; p_fin = cru_fin;}

    return minimo;
}

int main() {
    int marcas[] = {2,5,-6,2,3,-1,-5,6};
    int n = sizeof(marcas)/sizeof(marcas[0]);


    int p_ini, p_fin;
    cout <<"Acumulación negativa más alta: "<<calcularMayorAcumulaciónNegativa(marcas, 0, n-1, p_ini, p_fin)<<endl;
    cout << "Paquetes: ";
    for (int i = p_ini; i <=p_fin; i++) cout << i+1 << " ";
    cout << endl;

    int marcas2[] = {2,-3,4,-5,-7};
    n = sizeof(marcas2)/sizeof(marcas2[0]);
    cout <<"Acumulación negativa más alta: "<<calcularMayorAcumulaciónNegativa(marcas2, 0, n-1, p_ini, p_fin)<<endl;
    cout << "Paquetes: ";
    for (int i = p_ini; i <=p_fin; i++) cout << i+1 << " ";
    cout << endl;

    int marcas3[] = {-4,5,6,-4,3,-1,-5,6};
    n = sizeof(marcas3)/sizeof(marcas3[0]);
    cout <<"Acumulación negativa más alta: "<<calcularMayorAcumulaciónNegativa(marcas3, 0, n-1, p_ini, p_fin)<<endl;
    cout << "Paquetes: ";
    for (int i = p_ini; i <=p_fin; i++) cout << i+1 << " ";
    cout << endl;
    return 0;
}
