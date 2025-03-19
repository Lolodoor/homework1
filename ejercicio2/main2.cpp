#include "ejercicio2.cpp"

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
