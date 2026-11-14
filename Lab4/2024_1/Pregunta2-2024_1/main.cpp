#include <iostream>
using namespace std;

int encontrarPosEmpiezaRadiacion(int * arr, int ini, int fin) {

    int med = (ini + fin) / 2;

    if (arr[med]<=0 and arr[med+1]>0) return med+1;
    else if (arr[med]>0) return encontrarPosEmpiezaRadiacion(arr, ini,med);
    else return encontrarPosEmpiezaRadiacion(arr, med,fin);
}

int maxPotencia(int * arr, int ini, int fin) {
    if (ini == fin) return arr[ini];
    int med = (ini + fin) / 2;

    if (arr[med]<=arr[med+1] and arr[med]>=arr[med-1]) return maxPotencia(arr, med+1, fin);
    else return maxPotencia(arr, ini, med);
}

int main() {
    int explosiones[] = {0,-1,0,-1,0,1,1,2,2,3,2,2,1,1};
    int n = sizeof(explosiones)/sizeof(explosiones[0]);

    int pos = encontrarPosEmpiezaRadiacion(explosiones, 0, n-1);
    cout << "La radiación empieza a "<<pos<<" km"<<endl;
    cout << "Potencia máxima " << maxPotencia(explosiones, pos, n-1) << " megatones" << endl;

    int explosiones2[] = {-1,0,-1,0,1,1,2,2,3,3,4,3,3,2,2,1,1};
    n = sizeof(explosiones2)/sizeof(explosiones2[0]);
    pos = encontrarPosEmpiezaRadiacion(explosiones2, 0, n-1);
    cout << "La radiación empieza a "<<pos<<" km"<<endl;
    cout << "Potencia máxima " << maxPotencia(explosiones2, pos, n-1) << " megatones" << endl;

    return 0;
}
