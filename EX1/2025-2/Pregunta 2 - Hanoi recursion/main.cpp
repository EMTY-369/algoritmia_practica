#include <iostream>
using namespace std;

void mover(int n, char origen, char destino) {
    if (n==0) return;

    mover(n-1, origen, destino);
    cout << "Mover el paquete "<<n<<" del almacen "<<origen<<" hacia el almacen B"<<endl;
    mover(n-1, destino, origen);
    cout << "Mover el paquete "<<n<<" del almacen B hacia el almacen "<<destino<<endl;
    mover(n-1, origen, destino);
}

int main() {
    int n;
    cout << "Ingrese la cantidad de paquetes: ";
    cin >> n;

    mover(n, 'A', 'C');

    return 0;
}
