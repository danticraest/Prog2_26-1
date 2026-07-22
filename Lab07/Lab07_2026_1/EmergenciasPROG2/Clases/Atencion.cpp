//
// Created by alulab14 on 12/06/2026.
//

#include "Atencion.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

int Atencion::get_codigo() const {
    return codigo;
}

void Atencion::set_codigo(int codigo) {
    this->codigo = codigo;
}

void Atencion::get_paciente(char *pac) const {
    if (paciente==nullptr) pac[0]=0;
    else strcpy(pac, paciente);
}

void Atencion::set_paciente(const char *pac) {
    if (paciente)delete paciente;
    paciente = new char[strlen(pac) + 1];
    strcpy(paciente, pac);
}

void Atencion::get_descripcion(char *desc) const {
    if (descripcion==nullptr) desc[0]=0;
    else strcpy(desc, descripcion);
}

void Atencion::set_descripcion(const char *desc) {
    if (descripcion)delete descripcion;
    descripcion = new char[strlen(desc) + 1];
    strcpy(descripcion, desc);
}

int Atencion::get_hora() const {
    return hora;
}

void Atencion::set_hora(int hora) {
    this->hora = hora;
}

Atencion::Atencion() {
    codigo = 0;
    paciente = nullptr;
    descripcion = nullptr;
    hora = 0;
}
Atencion::Atencion(const class Atencion &ate) {
    codigo = 0;
    paciente = nullptr;
    descripcion = nullptr;
    hora = 0;
    *this = ate;
}
Atencion::~Atencion() {
    if (paciente)delete paciente;
    if (descripcion)delete descripcion;
}

void Atencion::leer() {
// ifstream arch(nombre_archivo,ios::in);


}

void Atencion::imprimir(){

}

void Atencion::obtener_prioridad(){

}