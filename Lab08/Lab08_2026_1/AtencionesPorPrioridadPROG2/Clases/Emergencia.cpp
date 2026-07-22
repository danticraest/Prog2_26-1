//
// Created by alulab14 on 19/06/2026.
//
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Emergencia.h"

bool Emergencia::get_requiere_rcp() const {
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

Emergencia::Emergencia(const class Emergencia &eme) {
    requiere_rcp = false;
    minutos_sin_pulso = 0;
    *this = eme;
}

void Emergencia::operator=(const class Emergencia &eme) {
    Atencion::operator=(eme);
    set_requiere_rcp(eme.get_requiere_rcp());
    set_minutos_sin_pulso(eme.get_minutos_sin_pulso());
}

Emergencia::~Emergencia() {
    cout << "Destruyendo Emergencia" << endl;
}

void Emergencia::leer(ifstream &input, int hh) {
    //1,1001,Juan Perez,Paro Cardiaco,1,3
    Atencion::leer(input, hh);
    input >> requiere_rcp;
    input.ignore();
    input >> minutos_sin_pulso;
    input.ignore();
}

void Emergencia::imprimir(ofstream &output) const {
    Atencion::imprimir(output);
    // atributos propios
    output << setw(10) << (requiere_rcp ? "SI" : "NO");
    output << setw(10) << minutos_sin_pulso;
    output << setw(30) << "Nivel: CRITICO (0 min)\n";
}

int Emergencia::obtenerPrioridad() const {
    return 1;
}
