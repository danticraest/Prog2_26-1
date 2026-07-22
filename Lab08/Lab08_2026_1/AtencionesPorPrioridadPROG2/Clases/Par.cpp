//
// Created by alulab14 on 19/06/2026.
//
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Par.h"


int Par::get_llave() const {
    return llave;
}

void Par::set_llave(int llave) {
    this->llave = llave;
}

class Atencion *Par::get_valor() const {
    return valor;
}

void Par::set_valor(class Atencion *valor) {
    this->valor = valor;
}

Par::Par() {
    llave = 0;
    valor = nullptr;
}

Par::~Par() {
    if (valor != nullptr) delete valor;
}

Par::Par(const class Par &pa) {
    llave = 0;
    valor = nullptr;
    *this = pa;
}

void Par::operator=(const class Par &pa) {
    set_llave(pa.get_llave());
    set_valor(pa.get_valor());
}
