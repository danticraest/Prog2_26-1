//
// Created by alulab14 on 15/05/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "VacunaAplicada.h"

void VacunaAplicada::get_nombre(char *nom) const {
    if (nombre == nullptr)nom[0] = 0;
    else strcpy(nom, nombre);
}

void VacunaAplicada::set_nombre(const char *nom) {
    if (nombre != nullptr)delete[]nombre;
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);
}

int VacunaAplicada::get_fecha() const {
    return fecha;
}

void VacunaAplicada::set_fecha(int fecha) {
    this->fecha = fecha;
}

double VacunaAplicada::get_dosis() const {
    return dosis;
}

void VacunaAplicada::set_dosis(double dosis) {
    this->dosis = dosis;
}

void VacunaAplicada::get_colegiatura(char *cole) const {
    if (colegiatura == nullptr)cole[0] = 0;
    else strcpy(cole, colegiatura);
}

void VacunaAplicada::set_colegiatura(const char *cole) {
    if (colegiatura != nullptr)delete[]colegiatura;
    colegiatura = new char[strlen(cole) + 1];
    strcpy(colegiatura, cole);
}

VacunaAplicada::VacunaAplicada() {
    nombre = nullptr;
    fecha = 0;
    dosis = 0.0;
    colegiatura = nullptr;
}

VacunaAplicada::VacunaAplicada(const class VacunaAplicada &vac) {
    nombre = nullptr;
    fecha = 0;
    dosis = 0.0;
    colegiatura = nullptr;
    *this = vac;
}


VacunaAplicada::~VacunaAplicada() {
    if (nombre != nullptr)delete[]nombre;
    if (colegiatura != nullptr)delete[]colegiatura;
}

void VacunaAplicada::operator=(const class VacunaAplicada &vac) {
    char aux[200];
    vac.get_nombre(aux);
    set_nombre(aux);
    fecha = vac.get_fecha();
    dosis = vac.get_dosis();
    vac.get_colegiatura(aux);
    set_colegiatura(aux);
}

void operator>>(ifstream &arch, class VacunaAplicada &vac) {
    char cadena[200], c;
    int dniCliente, fecha, dosis;

    arch.getline(cadena, 200, ',');
    arch >> dniCliente >> c;

    arch.getline(cadena, 200, ',');
    vac.set_nombre(cadena);
    arch >> fecha >> c >> dosis;
    vac.set_fecha(fecha);
    vac.set_dosis(dosis);
    arch.getline(cadena, 200, ',');
    vac.set_colegiatura(cadena);
}


void operator<<(ofstream &rep, class VacunaAplicada &vac) {
    char vacuna[200], colegiatura[200];
    vac.get_nombre(vacuna);
    vac.get_colegiatura(colegiatura);
    rep << left << setprecision(2) << fixed << vacuna << " : ";
    int aa = vac.get_fecha() / 10000;
    int mm = vac.get_fecha() % 10000 / 100;
    int dd = vac.get_fecha() % 100;
    rep << right << setfill('0')
            << setw(2) << dd << "/" << setw(2) << mm << "/" << aa << setfill(' ')
            << " (" << vac.get_dosis() << " ml, " << colegiatura << ")" << endl;
}
