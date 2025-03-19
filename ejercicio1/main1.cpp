#include <iostream>
#include "ejercicio1.cpp"

using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz cuadrada: ";
    cin >> n;

    int** matriz = matrizCuadrada(n);

    if (matriz == nullptr) {
        cout << "Error: No se pudo crear la matriz" << endl;
        return 1;
    }
    contenidoMatriz(matriz, n);
    liberarMatriz(matriz, n);

    return 0;
}
