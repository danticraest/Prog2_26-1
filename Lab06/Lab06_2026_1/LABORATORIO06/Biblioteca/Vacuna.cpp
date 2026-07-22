//
// Created by alulab14 on 5/06/2026.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Vacuna.h"

int Vacuna::get_dosis() const {
    return dosis;
}

void Vacuna::set_dosis(int dosis) {
    this->dosis = dosis;
}

int Vacuna::get_meses() const {
    return meses;
}

void Vacuna::set_meses(int meses) {
    this->meses = meses;
}

Vacuna::Vacuna() {
    dosis = 0;
    meses = 0;
}

Vacuna::Vacuna(const Vacuna &vac) {
    dosis = 0;
    meses = 0;
    *this = vac;
}

void Vacuna::operator=(const Vacuna &vac) {
    Cita::operator=(vac);
    dosis = vac.get_dosis();
    meses = vac.get_meses();
}

Vacuna::~Vacuna() {
}
