//
// Created by alulab14 on 26/06/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#include "Hora.h"


Hora::Hora() {
    hh = 0;
    mm = 0;
    ss = 0;
    segundos = 0;
}

Hora::~Hora() = default;

void Hora::leer(ifstream &arch) {
    char c;
    arch >> hh;
    if (arch.eof()) return;
    arch >> c >> mm >> c >> ss;
    segundos = hh * 3600 + mm * 60 + ss;
}

void Hora::imprimir(ofstream &arch) const {
    arch << right << setfill('0') << setw(2)
            << hh << ":" << setw(2) << mm << ":" << setw(2) << ss << setfill(' ') << endl;
}

void operator>>(ifstream &arch, class Hora &hor) {
    hor.leer(arch);
}

void operator<<(ofstream &arch, const class Hora &hor) {
    hor.imprimir(arch);
}
