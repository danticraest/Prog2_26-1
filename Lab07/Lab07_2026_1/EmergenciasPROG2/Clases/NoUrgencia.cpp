//
// Created by alulab14 on 12/06/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "NoUrgencia.h"

void NoUrgencia::get_especialidad(char *espe) const {
    if (especialidad == nullptr)espe[0] = 0;
    else strcpy(espe, especialidad);
}

void NoUrgencia::set_especialidad(const char *espe) {
    if (especialidad)delete especialidad;
    especialidad = new char[strlen(espe) + 1];
    strcpy(especialidad, espe);
}

bool NoUrgencia::is_es_consulta_programada() const {
    return es_consulta_programada;
}

void NoUrgencia::set_es_consulta_programada(bool es_consulta_programada) {
    this->es_consulta_programada = es_consulta_programada;
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

NoUrgencia::~NoUrgencia() {
    delete especialidad;
}
