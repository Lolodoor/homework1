#include <iostream>
#include <fstream>
#include <stdexcept> 

using namespace std;

void logMessage(string mensaje, int NivelSeveridad);
void logMessage(string Mensage_de_Error, string archivo, int Línea_de_Código);
void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario);