//
// Created by alulab14 on 5/06/2026.
//

#include "Control.h"

double Control::get_costo() const {
    return costo;
}

void Control::set_costo(double costo) {
    this->costo = costo;
}

int Control::get_codmed() const {
    return codmed;
}

void Control::set_codmed(int codmed) {
    this->codmed = codmed;
}

Control::Control() {
    costo = 0.0;
    codmed = 0;
}

Control::~Control() {
}

void Control::leerControl(ifstream &arch) {
    //lectura de Fecha y hora
    Cita::leerCita(arch);
}

