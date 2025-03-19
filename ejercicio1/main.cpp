#include "main.h"

int** matrizCuadrada(int n) {
  
    if (n < 1) return NULL;
    int c = 1;  // Contador para llenar la matriz con valores en orden
    int** matriz = nullptr;  

    try {
        // Reservo memoria para las filas
        matriz = new int*[n]; 
        for (int i = 0; i < n; i++) {
            // Reservo memoria para cada columna de la fila
            matriz[i] = new int[n]; 
            for (int j = 0; j < n; j++) {
                // lleno la matriz con valores en orden
                matriz[i][j] = c++;
            }
        }
    } catch (const bad_alloc& e) {
        //  por si hay un error de asignación de memoria
        cerr << "Error de asignación de memoria: " << e.what() << endl;
        
        // Libero cualquier memoria que haya sido asignada antes del error(por ejemplo si no me fallan las primeras filas y si las ultimas o las columnas)
        if (matriz) {
            for (int i = 0; i < n; i++) {
                delete[] matriz[i];
            }
            delete[] matriz;
        }

        return nullptr;  
    }

    return matriz; 
}

void contenidoMatriz(int** matriz, int n) {
    if (!matriz) return;  

    // RecorrO la matriz de atrás hacia adelante
    for (int i = n * n - 1; i >= 0; i--) {
        int fila = i / n;      // CalculO la fila correspondiente
        int columna = i % n;   // CalculO la columna correspondiente
        cout << matriz[fila][columna] << " ";
    }
    cout << endl;  
}

// Función que libera la memoria asignada a la matriz
void liberarMatriz(int** matriz, int n) {
    if (!matriz) return;  

    // Libero la memoria de cada fila
    for (int i = 0; i < n; i++) {
        delete[] matriz[i];
    }
    // Libero la memoria de la matriz (arreglo de punteros)
    delete[] matriz;
}


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
