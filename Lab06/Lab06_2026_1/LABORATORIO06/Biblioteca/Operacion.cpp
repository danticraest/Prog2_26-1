//
// Created by alulab14 on 5/06/2026.
//

#include "Operacion.h"

bool Operacion::is_anestesiageneral() const {
    return anestesiageneral;
}

void Operacion::set_anestesiageneral(bool anestesiageneral) {
    this->anestesiageneral = anestesiageneral;
}

int Operacion::get_nummedicos() const {
    return nummedicos;
}

void Operacion::set_nummedicos(int nummedicos) {
    this->nummedicos = nummedicos;
}

double Operacion::get_total() const {
    return total;
}

void Operacion::set_total(double total) {
    this->total = total;
}

Operacion::Operacion() {
    anestesiageneral = false;
    nummedicos = 0;
    total = 0.0;
}

Operacion::Operacion(const class Operacion &ope) {
    anestesiageneral = false;
    nummedicos = 0;
    total = 0.0;
    *this = ope;
}

Operacion::~Operacion() {
}
