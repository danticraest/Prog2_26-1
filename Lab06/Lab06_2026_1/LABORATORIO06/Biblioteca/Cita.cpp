//
// Created by alulab14 on 5/06/2026.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Cita.h"

int Cita::get_fecha() const {
    return fecha;
}

void Cita::set_fecha(int fecha) {
    this->fecha = fecha;
}

int Cita::get_hora() const {
    return hora;
}

void Cita::set_hora(int hora) {
    this->hora = hora;
}

class Mascota Cita::get_amascota() const {
    return Amascota;
}

void Cita::set_amascota(const class Mascota &amascota) {
    Amascota = amascota;
}

Cita::Cita() {
    fecha = 0;
    hora = 0;
}

Cita::~Cita() {
}

void Cita::leerCita(ifstream &arch) {
    int dd, mm, aa;
    char c;
    arch >> dd >> c >> mm >> c >> aa >> c >> hora >> c;
    fecha = aa * 10000 + mm * 100 + dd;
    // Mascota::Amascota.leerMascota();
    // Amascota.get_nombre();
}

void Cita::imprimirCita(ofstream &arch) {
    arch << left << setw(15) << fecha << setw(10) << hora;
}
