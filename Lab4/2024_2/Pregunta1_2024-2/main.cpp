#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

void mergE(int * arr, int ini, int med, int fin) {
    int lizq = med-ini+1;
    int lder = fin-med;

    int izq[lizq+1];
    int der[lder+1];

    for (int i = ini; i <= med; i++) izq[i-ini] = arr[i];
    izq[lizq]=INT_MAX;

    for (int i = med+1; i <= fin; i++) der[i-med-1] = arr[i];
    der[lder]=INT_MAX;

    int p=0, q=0;
    for (int i = ini; i <= fin; i++) {
        if (izq[p] < der[q]) {
            arr[i]=izq[p];
            p++;
        } else {
            arr[i]=der[q];
            q++;
        }
    }
}

void merge_sort(int * arr, int ini, int fin) {
    if (ini == fin) return;
    int med = (ini + fin) / 2;
    merge_sort(arr, ini, med);
    merge_sort(arr, med + 1, fin);
    mergE(arr, ini, med, fin);
}

int encontrar_empleado(int * arr, int ini, int fin) {
    if (ini >= fin) return 0;
    int med = (ini + fin) / 2;
    if (arr[med+1]==arr[med] and arr[med]==arr[med-1]) return arr[med];

    if (med%2==0) {
        if (arr[med]==arr[med+1]) return encontrar_empleado(arr, med, fin);
        else return encontrar_empleado(arr, ini, med);
    } else {
        if (arr[med]==arr[med-1]) return encontrar_empleado(arr, med+1, fin);
        else return encontrar_empleado(arr, ini, med-1);
    }
}

int main() {
    int bitacora[]={1,6,3,4,5,6,3,7,5,4,3,1,7};
    int n=sizeof(bitacora)/sizeof(int);

    merge_sort(bitacora,0, n-1);
    for (int i = 0; i < n; i++) cout<<bitacora[i]<<" ";
    cout<<endl;

    if (n%2!=0) cout << "Culpable: " << encontrar_empleado(bitacora,0,n-1)<<endl;
    else cout << "No hay empleado"<<endl;

    return 0;
}
