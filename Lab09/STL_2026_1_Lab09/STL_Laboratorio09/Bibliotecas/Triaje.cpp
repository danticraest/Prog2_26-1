//
// Created by alulab14 on 26/06/2026.
//

#include "Triaje.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

string Triaje::get_codigo_triaje() const {
    return codigoTriaje;
}

void Triaje::set_codigo_triaje(const string &codigo_triaje) {
    codigoTriaje = codigo_triaje;
}

string Triaje::get_codigo_paciente() const {
    return codigoPaciente;
}

void Triaje::set_codigo_paciente(const string &codigo_paciente) {
    codigoPaciente = codigo_paciente;
}

int Triaje::get_frecuencia_cardiaca() const {
    return frecuenciaCardiaca;
}

void Triaje::set_frecuencia_cardiaca(int frecuencia_cardiaca) {
    frecuenciaCardiaca = frecuencia_cardiaca;
}

int Triaje::get_presion_sistolica() const {
    return presionSistolica;
}

void Triaje::set_presion_sistolica(int presion_sistolica) {
    presionSistolica = presion_sistolica;
}

int Triaje::get_presion_diastolica() const {
    return presionDiastolica;
}

void Triaje::set_presion_diastolica(int presion_diastolica) {
    presionDiastolica = presion_diastolica;
}

double Triaje::get_temperatura() const {
    return temperatura;
}

void Triaje::set_temperatura(double temperatura) {
    this->temperatura = temperatura;
}

int Triaje::get_saturacion_de_oxigeno() const {
    return saturacionDeOxigeno;
}

void Triaje::set_saturacion_de_oxigeno(int saturacion_de_oxigeno) {
    saturacionDeOxigeno = saturacion_de_oxigeno;
}

Triaje::Triaje() {
    codigoTriaje = "";
    codigoPaciente = "";
    frecuenciaCardiaca = 0;
    presionSistolica = 0;
    presionDiastolica = 0;
    temperatura = 0.0;
    saturacionDeOxigeno = 0;
}

Triaje::~Triaje() = default;

void Triaje::leer(ifstream &arch) {
    char c;
    getline(arch, codigoTriaje, ',');
    if (arch.eof()) return;
    getline(arch, codigoPaciente, ',');
    arch >> frecuenciaCardiaca >> c >> presionSistolica >> c >>
            presionDiastolica >> c >> temperatura >> c >> saturacionDeOxigeno;
}

void Triaje::imprimir(ofstream &arch) const {
    arch << left << setw(20) << codigoTriaje << setw(20) << codigoPaciente;
    
    arch<< setw(20)
            << frecuenciaCardiaca << setw(20) << presionSistolica << setw(20)
            << presionDiastolica << setw(20) << temperatura << setw(20) << saturacionDeOxigeno << endl;
}

void operator>>(ifstream &arch, class Triaje &tri) {
    tri.leer(arch);
}

void operator<<(ofstream &arch, const class Triaje &tri) {
    tri.imprimir(arch);
}
