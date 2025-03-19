#include "ejercicio2.h"


void logMessage(string mensaje, int NivelSeveridad) {
    try {
        ofstream logFile("log.txt", ios::app);
        if (!logFile) {
            throw runtime_error("No se pudo abrir el archivo de log.");
        }

        // Escribo el mensaje en el log según su nivel de severidad
        switch (NivelSeveridad) {
            case 0: logFile << "[INFO] " << mensaje << endl; break;
            case 1: logFile << "[WARNING] " << mensaje << endl; break;
            case 2: logFile << "[ERROR] " << mensaje << endl; break;
            case 3: logFile << "[DEBUG] " << mensaje << endl; break;
            case 4: logFile << "[CRITICAL] " << mensaje << endl; break;
            default:
                throw runtime_error("Nivel de severidad inválido."); // Lanzamos una excepción si el nivel no es válido
        }

        logFile.close(); 
    } catch (const exception&) {
        cerr << "Error: No se pudo procesar el mensaje de log." << endl;
    }
}

void logMessage(string Mensage_de_Error, string archivo, int Línea_de_Código) {
    try {
        ofstream logFile("log.txt", ios::app);
        if (!logFile) {
            throw runtime_error("No se pudo abrir el archivo de log.");
        }
        // Escribo el mensaje de error con detalles del archivo y la línea
        logFile << "[ERROR] " << Mensage_de_Error << " | Archivo: " << archivo << " | Línea: " << Línea_de_Código << endl;
        logFile.close(); // 
    } catch (const exception&) {
        cerr << "Error: No se pudo registrar el error en el log." << endl;
    }
}

void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario) {
    try {
        ofstream logFile("log.txt", ios::app);
        if (!logFile) {
            throw runtime_error("No se pudo abrir el archivo de log.");
        }
        // Escribo el mensaje de acceso con el nombre del usuario
        logFile << "[SECURITY] " << Mensaje_De_Acceso << " | Usuario: " << Nombre_de_Usuario << endl;

        // Si el acceso fue denegado, lanzo una excepción
        if (Mensaje_De_Acceso == "Access Denied") {
            throw runtime_error("Intento de acceso denegado.");
        }

        logFile.close(); 
    } catch (const exception&) {
        cerr << "ALERTA: Se ha detectado un problema en la seguridad." << endl;
    }
}
