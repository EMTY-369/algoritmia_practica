#include <iostream>
#include <cstring>
using namespace std;

int contador_palabras(char *texto, char *palabra, int contador, int indice_palabra, int tamanio, bool posible) {
    if (texto[contador] == '\0') {
        if (indice_palabra == tamanio) return 1;
        return 0;
    }

    if (indice_palabra == tamanio and texto[contador] == ' ') return contador_palabras(texto, palabra, contador+1, 0, tamanio, true)+1;
    else {
        if (texto[contador] == ' ') {
            return contador_palabras(texto, palabra, contador+1, 0, tamanio, true);
        } else {
            if (texto[contador] == palabra[indice_palabra] and posible) {
                return contador_palabras(texto, palabra, contador+1, indice_palabra+1, tamanio, true);
            } else {
                return contador_palabras(texto, palabra, contador+1, 0, tamanio, false);
            }
        }
    }
}

int main() {
    char texto[] = "hola mundo hola holanda" ;
    char palabra[] = "hola";
    int n = strlen(palabra);

    int cant = contador_palabras(texto, palabra, 0, 0, n, true);

    cout << cant << endl;

    return 0;
}
