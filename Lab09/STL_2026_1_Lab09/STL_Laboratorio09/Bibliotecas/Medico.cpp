//
// Created by alulab14 on 26/06/2026.
//

#include "Medico.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int Medico::get_codigo() const {
    return codigo;
}

void Medico::set_codigo(int codigo) {
    this->codigo = codigo;
}

string Medico::get_nombre() const {
    return nombre;
}

void Medico::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

double Medico::get_tarifa() const {
    return tarifa;
}

void Medico::set_tarifa(double tarifa) {
    this->tarifa = tarifa;
}

string Medico::get_especialidad_nombre() const {
    return especialidadNombre;
}

void Medico::set_especialidad_nombre(const string &especialidad_nombre) {
    especialidadNombre = especialidad_nombre;
}

vector<class Atencion> Medico::get_atenciones() const {
    return atenciones;
}

void Medico::set_atenciones(const vector<class Atencion> &atenciones) {
    this->atenciones = atenciones;
}

double Medico::get_pagos_por_atencion() const {
    return pagosPorAtencion;
}

void Medico::set_pagos_por_atencion(double pagos_por_atencion) {
    pagosPorAtencion = pagos_por_atencion;
}

Medico::Medico() {
    codigo = 0;
    nombre = "";
    tarifa = 0.0;
    especialidadNombre = "";
    pagosPorAtencion = 0.0;
}

Medico::~Medico() = default;

void Medico::leer(ifstream &arch) {
    getline(arch, especialidadNombre, ',');
    if (arch.eof()) return;
    while (true) {
        arch >> codigo;
        arch.get(); //coma
        getline(arch, nombre, ',');
        arch >> tarifa;
        if (arch.get() == '\n') break;
    }
}

void Medico::imprimir(ofstream &arch) const {
    arch << "MEDICO: " << endl;
    arch << "CODIGO: " << codigo << endl;
    arch << "NOMBRE: " << nombre << endl;
    arch << "ESPECIALIDAD: " << especialidadNombre << endl;
    arch << "TARIFA: " << tarifa << endl;
}

void operator>>(ifstream &arch, class Medico &med) {
    med.leer(arch);
}

void operator<<(ofstream &arch, const class Medico &med) {
    med.imprimir(arch);
}

bool Medico::operator<(const class Medico &med) const {
    if (especialidadNombre == med.especialidadNombre) {
        return nombre < med.nombre;
    }
    return especialidadNombre < med.especialidadNombre;
}

void Medico::agregarAtencion(const class Atencion &med) {
atenciones.push_back(med);
}