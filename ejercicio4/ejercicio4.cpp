#include "ejercicio4.h"


constexpr bool compararTextos(const char* texto1, const char* texto2) {       
     if (*texto1 != *texto2) return false;    // si los caracteres no son iguales, false
     if (*texto1 == '\0' && *texto2 == '\0') return true; // si ambos llegan al final, son iguales
     return compararTextos(texto1 + 1, texto2 + 1);  } // si no, comparo los siguientes caracteres
     






