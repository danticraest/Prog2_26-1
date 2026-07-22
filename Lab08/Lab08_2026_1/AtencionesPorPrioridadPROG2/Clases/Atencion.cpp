//
// Created by alulab14 on 19/06/2026.
//
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "GestorAtenciones.h"
using namespace std;
#include "Atencion.h"

int Atencion::get_codigo() const {
    return codigo;
}

void Atencion::set_codigo(int codigo) {
    this->codigo = codigo;
}

int Atencion::get_hora_ingreso() const {
    return hora_ingreso;
}

void Atencion::set_hora_ingreso(int hora_ingreso) {
    this->hora_ingreso = hora_ingreso;
}

string Atencion::get_paciente() const {
    return paciente;
}

void Atencion::set_paciente(const string &paciente) {
    this->paciente = paciente;
}

string Atencion::get_descripcion() const {
    return descripcion;
}

void Atencion::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}

Atencion::Atencion() {
    codigo = 0;
    hora_ingreso = 0;
    paciente = "";
    descripcion = "";
}

Atencion::Atencion(const class Atencion &ate) {
    codigo = 0;
    hora_ingreso = 0;
    paciente = "";
    descripcion = "";
    *this = ate;
}

void Atencion::operator=(const class Atencion &ate) {
    set_codigo(ate.get_codigo());
    set_hora_ingreso(ate.get_hora_ingreso());
    set_paciente(ate.get_paciente());
    set_descripcion(ate.get_descripcion());
}


void Atencion::leer(ifstream &input, int hh) {
    /*
    * 1,1001,Juan Perez,Paro Cardiaco,1,3
    * 2,1002,Ana Ruiz,Dificultad Respiratoria,88,1
    * 3,1003,Carlos Diaz,Fractura Brazo,Brazo Derecho,1
     */

    int _codigo;
    char buffer[100];
    input >> _codigo;
    if (input.eof()) return;
    input.ignore();
    input.getline(buffer, 100, ',');
    set_codigo(_codigo);
    set_paciente(buffer);
    input.getline(buffer, 100, ',');
    set_descripcion(buffer);
    set_hora_ingreso(hh);
    conseguir_llave(_codigo);
}

void Atencion::imprimir(ofstream &output) const {
    output << setw(10) << codigo;
    output << setw(20) << paciente;
    output << setw(60) << descripcion;
}

int Atencion::conseguir_llave(int codigo) {
    //si una atencion es prioridad 1, codigo=5202 entonces retorna 15202
    return (obtenerPrioridad() * 10000 + codigo);
}

void Atencion::clonar() {
}
