#include "main.h"

struct Node{
    int data;
    shared_ptr<Node> next;
};

struct ListaEnlazada{
    shared_ptr<Node> head;
    size_t size;
};

shared_ptr<Node> Create_node(int data){
    shared_ptr<Node> newNode = make_shared<Node>();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

shared_ptr<ListaEnlazada> Create_list(){
    shared_ptr<ListaEnlazada> List = make_shared<ListaEnlazada>();
    List->head = nullptr;
    List->size = 0;
    return List;
}

void push_front(shared_ptr<ListaEnlazada> List, int data){
    shared_ptr<Node> newNode = Create_node(data);
    if(List->head == nullptr){
        List->head = newNode;
    }else{
        newNode->next = List->head;
        List->head = newNode;
    }
    List->size++;
}

void push_back(shared_ptr<ListaEnlazada> List, int data){
    shared_ptr<Node> newNode = Create_node(data);
    if(List->head == nullptr){
        List->head = newNode;
    }else{
        shared_ptr<Node> temp = List->head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    List->size++;
}
      
 void insert(shared_ptr<ListaEnlazada> List, int data, size_t pos){
    if(pos >= List->size){
        cout << "Posicion invalida se incertará al final" << endl;
        push_back(List, data);
        return;
    }
    if(pos == 0){
        push_front(List, data);
        return;
    
    }else{
        shared_ptr<Node> newNode = Create_node(data);
        shared_ptr<Node> temp = List->head;
        for(size_t i = 0; i < pos-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        List->size++;
    }
    
}


void erase(shared_ptr<ListaEnlazada> List, size_t pos) {
    if (List->head == nullptr) {
        cout << "la lista está vacía." << endl;
        return;
    }
    if (pos >= List->size) {
        cout << "Posición inválida, se borrará el último." << endl;
        if (List->size == 1) {
            List->head = nullptr;  
        } else {
            shared_ptr<Node> temp = List->head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nullptr;  
        }
        List->size--;
        return;
    }
    if (pos == 0) {
        List->head = List->head->next;  
        List->size--;
        return;
    }
    shared_ptr<Node> temp = List->head;
    for (size_t i = 0; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }
    temp->next = temp->next->next;  
    List->size--;
}


void print_list(shared_ptr<ListaEnlazada> List){
    if (List->head == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }

    shared_ptr<Node> temp = List->head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}




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
