//
// Created by alulab14 on 26/06/2026.
//

#include "Paciente.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

string Paciente::get_codigo() const {
    return codigo;
}

void Paciente::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

string Paciente::get_nombre() const {
    return nombre;
}

void Paciente::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

char Paciente::get_sexo() const {
    return sexo;
}

void Paciente::set_sexo(char sexo) {
    this->sexo = sexo;
}

int Paciente::get_edad() const {
    return edad;
}

void Paciente::set_edad(int edad) {
    this->edad = edad;
}

double Paciente::get_gastos_por_atencion() const {
    return gastosPorAtencion;
}

void Paciente::set_gastos_por_atencion(double gastos_por_atencion) {
    gastosPorAtencion = gastos_por_atencion;
}

Paciente::Paciente() {
    codigo = "";
    nombre = "";
    sexo = ' ';
    edad = 0;
    gastosPorAtencion = 0.0;
}

Paciente::~Paciente() = default;


void Paciente::leer(ifstream &arch) {
    char c;
    getline(arch, codigo, ',');
    getline(arch, nombre, ',');
    arch >> sexo >> c >> edad;
}

void Paciente::imprimir(ofstream &arch) const {
    arch << "PACIENTE: " << endl;
    arch << "CODIGO: " << codigo << endl;
    arch << "NOMBRE: " << nombre << endl;
    arch << "SEXO: " << sexo << endl;
    arch << "EDAD: " << edad << endl;
}

void operator>>(ifstream &arch, class Paciente &pac) {
    pac.leer(arch);
}

void operator<<(ofstream &arch, const class Paciente &pac) {
    pac.imprimir(arch);
}

void Paciente::agregarAtencionP(const class Atencion &med) {
    atenciones.push_back(med);
}