//
// Created by alulab14 on 12/06/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Emergencia.h"

bool Emergencia::is_requiere_rcp() const {
    return requiere_rcp;
}

void Emergencia::set_requiere_rcp(bool requiere_rcp) {
    this->requiere_rcp = requiere_rcp;
}

int Emergencia::get_minutos_sin_pulso() const {
    return minutos_sin_pulso;
}

void Emergencia::set_minutos_sin_pulso(int minutos_sin_pulso) {
    this->minutos_sin_pulso = minutos_sin_pulso;
}

Emergencia::Emergencia() {
    requiere_rcp = false;
    minutos_sin_pulso = 0;
}
Emergencia::Emergencia(const class Emergencia& em) {
    requiere_rcp = false;
    minutos_sin_pulso = 0;
    *this = em;
}

Emergencia::~Emergencia() {
}
