#include "main.h"


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




int main() {
    string usuario;
    string acceso;
    cout << "Ingrese su nombre de usuario: ";
    cin >> usuario;
    
    cout << "El usuario tiene acceso? (si/no): ";
    cin >> acceso;
    
    try {
        if (acceso == "no") {
            logMessage("Access Denied", usuario);
            return 1; // Salir del programa
        }
        logMessage("Access Granted", usuario);
        
        int opcion;
        cout << "Seleccione una opcion:\n";
        cout << "1. Registrar un error en un archivo y linea especifica\n";
        cout << "2. Registrar un mensaje general con nivel de severidad\n";
        cout << "Opcion: ";
        cin >> opcion;
        
        if (opcion == 1) {
            string archivo;
            int linea;
            string mensaje;
            
            cout << "Ingrese el nombre del archivo: ";
            cin >> archivo;
            cout << "Ingrese el numero de linea: ";
            cin >> linea;
            cin.ignore(); 
            cout << "Ingrese el mensaje de error: ";
            getline(cin, mensaje);
            
            logMessage(mensaje, archivo, linea);
        } else if (opcion == 2) {
            string mensaje;
            int severidad;
            
            cout << "Ingrese el mensaje: ";
            cin.ignore(); 
            getline(cin, mensaje);
            cout << "Ingrese el nivel de severidad (0-4): ";
            cin >> severidad;
            
            logMessage(mensaje, severidad);
        } else {
            cout << "Opcion no valida." << endl;
        }
    } catch (const exception& e) {
        cerr << "Error en la ejecucion: " << e.what() << endl;
    }
    
    return 0;
}
