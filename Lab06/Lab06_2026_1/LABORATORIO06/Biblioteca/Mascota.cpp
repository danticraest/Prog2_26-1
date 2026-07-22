//
// Created by alulab14 on 5/06/2026.
//

#include "Mascota.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

int Mascota::get_codigo() const {
    return codigo;
}

void Mascota::set_codigo(int codigo) {
    this->codigo = codigo;
}

void Mascota::get_nombre(char *nom) const {
    if (nombre == nullptr)nom[0] = 0;
    else strcpy(nom, nombre);
}

void Mascota::set_nombre(const char *nom) {
    if (nombre) delete[] nombre;
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);
}

char Mascota::get_tipo() const {
    return tipo;
}

void Mascota::set_tipo(char tipo) {
    this->tipo = tipo;
}

void Mascota::get_raza(char *raz) const {
    if (raza == nullptr)raz[0] = 0;
    else strcpy(raz, raza);
}

void Mascota::set_raza(const char *raz) {
    if (raza) delete[] raza;
    raza = new char[strlen(raz) + 1];
    strcpy(raza, raz);
}

Mascota::Mascota() {
    codigo = 0;
    nombre = nullptr;
    tipo = ' ';
    raza = nullptr;
}

Mascota::Mascota(const class Mascota &mas) {
    codigo = 0;
    nombre = nullptr;
    tipo = ' ';
    raza = nullptr;
    *this = mas;
}

Mascota::~Mascota() {
    delete[]nombre;
    delete[]raza;
}

void Mascota::leerMascota(ifstream &arch) {
    char c;

    arch >> codigo >> c;
    // arch>>nombre >> c >> tipo >> c >> raza;
}
