//
// Created by alulab14 on 19/06/2026.
//

#include "Urgencia.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

void Urgencia::get_zona_lesion(char *zona_lesion) const {
    if (this->zona_lesion == nullptr) zona_lesion[0] = '\0';
    else strcpy(zona_lesion, this->zona_lesion);
}

void Urgencia::set_zona_lesion(const char *zona_lesion) {
    if (this->zona_lesion != nullptr) delete [] this->zona_lesion;
    this->zona_lesion = new char[strlen(zona_lesion) + 1];
    strcpy(this->zona_lesion, zona_lesion);
}

bool Urgencia::get_necesita_rx() const {
    return necesita_rx;
}

void Urgencia::set_necesita_rx(const bool necesita_rx) {
    this->necesita_rx = necesita_rx;
}

void Urgencia::leer(ifstream &input, int hh) {
    //2,1003,Carlos Diaz,Fractura Brazo,Brazo Derecho,1
    Atencion::leer(input, hh);
    char buffer[100];
    input.getline(buffer, 100, ',');
    set_zona_lesion(buffer);
    input >> necesita_rx;
    input.ignore();
}

void Urgencia::imprimir(ofstream &output) const {
    Atencion::imprimir(output);
    output << setw(20) << zona_lesion;
    output << setw(10) << (necesita_rx ? "SI" : "NO");

    output << setw(30) << "Tiempo max: 30 min\n";
}

int Urgencia::obtenerPrioridad() const {
    return 2;
}

Urgencia::Urgencia() {
    zona_lesion = nullptr;
    necesita_rx = false;
}

Urgencia::Urgencia(const class Urgencia &urg) {
    zona_lesion = nullptr;
    necesita_rx = false;
    *this = urg;
}

void Urgencia::operator=(const class Urgencia &urg) {
    char aux[100];
    Atencion::operator=(urg);
    set_zona_lesion(aux);
    urg.get_zona_lesion(aux);
    set_necesita_rx(urg.get_necesita_rx());
}

Urgencia::~Urgencia() {
    if (zona_lesion != nullptr) delete [] zona_lesion;
    cout << "Destruyendo Urgencia" << endl;
}
