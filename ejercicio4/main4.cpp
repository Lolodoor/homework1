#include "ejercicio4.cpp"


int main() {
    
    constexpr const char text1[] = "Este es un texto largo para probar la comparacion recursiva en C++.";
    constexpr const char text2[] = "Este es un texto largo para probar la comparacion recursiva en C++.";
    constexpr const char text3[] = "esto es un texto random para que sea diferente al 1 y 2";

    auto startTime = std::chrono::high_resolution_clock::now();
    
    constexpr bool resultConstexpr1 = compararTextos(text1, text2);
    constexpr bool resultConstexpr2 = compararTextos(text1, text3);
    constexpr bool resultConstexpr3 = compararTextos(text2, text3);

    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    cout << "Resultados en tiempo de compilación:" << endl;
    cout << "Comparación 1: " << resultConstexpr1 << endl;
    cout << "Comparación 2: " << resultConstexpr2 << endl;
    cout << "Comparación 3: " << resultConstexpr3 << endl;
    cout << "Tiempo total:" << elapsedTime.count() << " Nanosegundos" << endl;

}
/*
conclusion: el que usa el tiempo de compilacion tarda menos y tiene sentido porque se ahorra en ejecucion hacer las comparaciones,
entonces al hacerlo en compilacion ya tiene el resultado y es mas rapido
aca dejo unos resultados donde compare a los dos.
ademas elegi const char en lugar de string porque string no se puede usar en tiempo de compilacion y ademas es un poco mas rapido

Resultados en tiempo de compilación:
Comparación 1: 1
Comparación 2: 0
Comparación 3: 0
Tiempo total: 84 Nanosegundos

Resultados en tiempo de ejecución:
Comparación 1: 1
Comparación 2: 0
Comparación 3: 0
Tiempo total: 1083 Nanosegundos

aclaracion: 1 es true y 0 es false
*/
