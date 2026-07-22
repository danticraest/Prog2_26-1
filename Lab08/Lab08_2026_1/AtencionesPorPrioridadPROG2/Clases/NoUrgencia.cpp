//
// Created by alulab14 on 19/06/2026.
//
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
#include "NoUrgencia.h"

void NoUrgencia::get_especialidad(char *especialidad) const {
    if (this->especialidad == nullptr) especialidad[0] = '\0';
    else strcpy(especialidad, this->especialidad);
}

void NoUrgencia::set_especialidad(const char *especialidad) {
    if (this->especialidad != nullptr) delete [] this->especialidad;
    this->especialidad = new char[strlen(especialidad) + 1];
    strcpy(this->especialidad, especialidad);
}

bool NoUrgencia::get_es_consulta_programada() const {
    return es_consulta_programada;
}

void NoUrgencia::set_es_consulta_programada(bool es_consulta_programada) {
    this->es_consulta_programada = es_consulta_programada;
}

void NoUrgencia::leer(ifstream &input, int hh) {
    //3,1005,Luis Torres,Dermatitis,Dermatologia,0
    Atencion::leer(input, hh);
    char buffer[100];
    input.getline(buffer, 100, ',');
    set_especialidad(buffer);
    input >> es_consulta_programada;
    input.ignore();
}

void NoUrgencia::imprimir(ofstream &output) const {
    Atencion::imprimir(output);
    output << setw(20) << especialidad;
    output << setw(20) << (es_consulta_programada ? "SI" : "NO") << "\n";
}

int NoUrgencia::obtenerPrioridad() const {
    return 3;
}

NoUrgencia::NoUrgencia() {
    especialidad = nullptr;
    es_consulta_programada = false;
}

NoUrgencia::NoUrgencia(const class NoUrgencia &nour) {
    especialidad = nullptr;
    es_consulta_programada = false;
    *this = nour;
}

void NoUrgencia::operator=(const class NoUrgencia &nour) {
    char aux[200];
    set_especialidad(aux);
    nour.get_especialidad(aux);
    set_es_consulta_programada(nour.get_es_consulta_programada());
}

NoUrgencia::~NoUrgencia() {
    if (especialidad != nullptr) delete [] especialidad;
    cout << "Destruyendo NoUrgencia" << endl;
}
