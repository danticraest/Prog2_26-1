//
// Created by alulab14 on 26/06/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#include "Atencion.h"


int Atencion::get_fecha() const {
    return fecha;
}

void Atencion::set_fecha(int fecha) {
    this->fecha = fecha;
}

string Atencion::get_codigo_paciente() const {
    return codigoPaciente;
}

void Atencion::set_codigo_paciente(const string &codigo_paciente) {
    codigoPaciente = codigo_paciente;
}

class Hora Atencion::get_hora_ingreso() const {
    return horaIngreso;
}

void Atencion::set_hora_ingreso(const class Hora &hora_ingreso) {
    horaIngreso = hora_ingreso;
}

class Hora Atencion::get_hora_alta() const {
    return horaAlta;
}

void Atencion::set_hora_alta(const class Hora &hora_alta) {
    horaAlta = hora_alta;
}

int Atencion::get_codigo_medico() const {
    return codigoMedico;
}

void Atencion::set_codigo_medico(int codigo_medico) {
    codigoMedico = codigo_medico;
}

string Atencion::get_codigo_triaje() const {
    return CodigoTriaje;
}

void Atencion::set_codigo_triaje(const string &codigo_triaje) {
    CodigoTriaje = codigo_triaje;
}

class Hora Atencion::get_duracion() const {
    return duracion;
}

void Atencion::set_duracion(const class Hora &duracion) {
    this->duracion = duracion;
}

class Triaje Atencion::get_triaje() const {
    return triaje;
}

void Atencion::set_triaje(const class Triaje &triaje) {
    this->triaje = triaje;
}

Atencion::Atencion() {
    fecha = 0;
    codigoPaciente = "";
    codigoMedico = 0;
    CodigoTriaje = "";
}

Atencion::~Atencion() = default;

void Atencion::leer(ifstream &arch) {
    int dia, mes, ano;
    char c;
    arch >> dia;
    if (arch.eof()) return;
    arch >> c >> mes >> c >> ano;
    arch.get(); //coma
    fecha = ano * 10000 + mes * 100 + dia;
    while (true) {
        horaIngreso.leer(arch);
        arch.get(); //coma
        getline(arch, codigoPaciente, ',');
        horaAlta.leer(arch);
        arch.get(); //coma
        // duracion=horaAlta-horaIngreso;
        arch >> codigoMedico >> c;
        //codigo triaje esta que se come el resto del archivo, genera bucle
        getline(arch, CodigoTriaje,',');
        if (arch.get()== '\n') break;
    }
}

void Atencion::imprimir(ofstream &arch) const {
    arch<<left<<setw(20)<< fecha <<setw(20)<< codigoPaciente<<setw(20);
    horaIngreso.imprimir(arch);
    arch<<setw(20);
    horaAlta.imprimir(arch);
    arch<<setw(20);
    duracion.imprimir(arch);
    arch<<setw(20);

}
void operator>>(ifstream &arch, class Atencion &ate) {
    ate.leer(arch);
}

void operator<<(ofstream &arch, const class Atencion &ate) {
    ate.imprimir(arch);
}

bool Atencion::operator<(const class Atencion &ate) const {
    if (fecha == ate.fecha) {
        return CodigoTriaje < ate.CodigoTriaje;
    }
    return fecha < ate.fecha;
}
