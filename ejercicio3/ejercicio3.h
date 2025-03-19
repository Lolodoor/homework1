#include <iostream>
#include <memory>

using namespace std;

struct Node;
struct ListaEnlazada;

shared_ptr<Node> Create_node(int data);
shared_ptr<ListaEnlazada> Create_list();
void push_front(shared_ptr<ListaEnlazada> List, int data);
void push_back(shared_ptr<ListaEnlazada> List, int data);
void insert(shared_ptr<ListaEnlazada> List, int data, size_t pos);
void erase(shared_ptr<ListaEnlazada> List, size_t pos);
void print_list(shared_ptr<ListaEnlazada> List);
