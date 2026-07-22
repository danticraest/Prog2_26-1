//
// Created by alulab14 on 19/06/2026.
//

#include "ListaDoble.h"

class NodoListaDoble *ListaDoble::get_cabeza() const {
    return cabeza;
}

void ListaDoble::set_cabeza(class NodoListaDoble *cabeza) {
    this->cabeza = cabeza;
}

ListaDoble::ListaDoble() {
    cabeza = nullptr;
}

ListaDoble::ListaDoble(const class ListaDoble &lis) {
    cabeza = nullptr;
    *this = lis;
}


ListaDoble::~ListaDoble() {
    class NodoListaDoble *p;
    while (cabeza) {
        p = cabeza;
        cabeza = cabeza->siguiente;
        delete p;
    }
    cabeza = nullptr;
    cout << "Destruyendo ListaDoble" << endl;
}

void ListaDoble::insertar(GestorAtenciones *p,int  llave) {
    class NodoListaDoble *nuevo= new class NodoListaDoble;
    nuevo->siguiente=nullptr;
    nuevo->anterior=nullptr;
    nuevo->siguiente=nullptr;
    if (cabeza) {
        class NodoListaDoble *rec=cabeza;
        while (rec->siguiente!=nullptr) rec=rec->siguiente;
        rec->siguiente=nuevo;
    }else cabeza=nuevo;
    // insertar(*&p,  llave);
}

void ListaDoble::imprimir(GestorAtenciones *p) {
    class NodoListaDoble *pt=cabeza;

    // imprimir();
}

void ListaDoble::destruir() {
    class NodoListaDoble *p;
    while (cabeza) {
        p = cabeza;
        cabeza = cabeza->siguiente;
        delete p;
    }
    cabeza = nullptr;
    cout << "Destruyendo ListaDoble" << endl;
}