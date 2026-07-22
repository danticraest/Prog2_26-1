//
// Created by alulab14 on 19/06/2026.
//

#include "NodoListaDoble.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

class Par NodoListaDoble::get_dato() const {
    return dato;
}

void NodoListaDoble::set_dato(const class Par &dato) {
    this->dato = dato;
}

class NodoListaDoble *NodoListaDoble::get_anterior() const {
    return anterior;
}

void NodoListaDoble::set_anterior(class NodoListaDoble *anterior) {
    this->anterior = anterior;
}

class NodoListaDoble *NodoListaDoble::get_siguiente() const {
    return siguiente;
}

void NodoListaDoble::set_siguiente(class NodoListaDoble *siguiente) {
    this->siguiente = siguiente;
}

NodoListaDoble::NodoListaDoble() {
    anterior = nullptr;
    siguiente = nullptr;
}

NodoListaDoble::NodoListaDoble(const class NodoListaDoble &nod) {
    anterior = nullptr;
    siguiente = nullptr;
    *this = nod;
}
void NodoListaDoble::operator=(const class NodoListaDoble &nod) {
    set_anterior(nod.get_anterior());
    set_siguiente(nod.get_siguiente());
}

NodoListaDoble::~NodoListaDoble() {
    delete anterior;
    delete siguiente;
}
