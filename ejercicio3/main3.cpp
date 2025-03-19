#include "ejercicio3.cpp"

int main() {
    shared_ptr<ListaEnlazada> lista = Create_list();

    cout << "Caso 1: Lista vacía" << endl;
    print_list(lista);

    cout << "Caso 2: Insertar 10 al principio" << endl;
    push_front(lista, 10);
    print_list(lista);

    cout << "Caso 3: Insertar 20 al final" << endl;
    push_back(lista, 20);
    print_list(lista);

    cout << "Caso 4: Insertar 15 en la posición 3" << endl;
    insert(lista, 15, 3);
    print_list(lista);

    cout << "Caso 5: Insertar 25 en la posición 10 (fuera de rango)" << endl;
    insert(lista, 25, 10);
    print_list(lista);

    cout << "Caso 6: Insertar 30 en la posición 1 (posición válida)" << endl;
    insert(lista, 30, 1);
    print_list(lista);

    cout << "Caso 7: Borrar el primer elemento" << endl;
    erase(lista, 0);
    print_list(lista);

    cout << "Caso 8: Borrar el elemento en la posición 2 (posición válida)" << endl;
    erase(lista, 2);
    print_list(lista);

    cout << "Caso 9: Borrar el último elemento" << endl;
    erase(lista, 1);
    print_list(lista);

    cout << "Caso 10: Borrar en posición 10 (fuera de rango)" << endl;
    erase(lista, 10);
    print_list(lista);

    cout << "Caso 11: Borrar el único elemento restante" << endl;
    erase(lista, 0);
    print_list(lista);

    return 0;
}
