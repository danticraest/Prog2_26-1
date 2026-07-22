//
// Created by alulab14 on 15/05/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Mascota.h"

int Mascota::get_dni() const {
    return dni;
}

void Mascota::set_dni(int dni) {
    this->dni = dni;
}

void Mascota::get_nombre(char *nom) const {
    if (nombre == nullptr)nom[0] = 0;
    else strcpy(nom, nombre);
}

void Mascota::set_nombre(const char *nom) {
    if (nombre != nullptr)delete[]nombre;
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);
}

void Mascota::get_especie(char *espe) const {
    if (especie == nullptr)espe[0] = 0;
    else strcpy(espe, especie);
}

void Mascota::set_especie(const char *espe) {
    if (especie != nullptr)delete[]especie;
    especie = new char[strlen(espe) + 1];
    strcpy(especie, espe);
}

int Mascota::get_edad() const {
    return edad;
}

void Mascota::set_edad(int edad) {
    this->edad = edad;
}

double Mascota::get_peso() const {
    return peso;
}

void Mascota::set_peso(double peso) {
    this->peso = peso;
}

void Mascota::get_colegiatura(char *cole) const {
    if (colegiatura == nullptr)cole[0] = 0;
    else strcpy(cole, colegiatura);
}

void Mascota::set_colegiatura(const char *cole) {
    if (colegiatura != nullptr)delete[]colegiatura;
    colegiatura = new char[strlen(cole) + 1];
    strcpy(colegiatura, cole);
}

int Mascota::get_num_vacunas() const {
    return numVacunas;
}

void Mascota::set_num_vacunas(int num_vacunas) {
    numVacunas = num_vacunas;
}

Mascota::Mascota() {
    dni = 0;
    nombre = nullptr;
    especie = nullptr;
    edad = 0;
    peso = 0.0;
    colegiatura = nullptr;
    numVacunas = 0;
}

Mascota::Mascota(const class Mascota &masc) {
    dni = 0;
    nombre = nullptr;
    especie = nullptr;
    edad = 0;
    peso = 0.0;
    colegiatura = nullptr;
    numVacunas = 0;
    *this = masc;
}

Mascota::~Mascota() {
    if (nombre != nullptr)delete[] nombre;
    if (especie != nullptr)delete[] especie;
    if (colegiatura != nullptr)delete[] colegiatura;
}

void Mascota::operator=(const class Mascota &masc) {
    char aux[200];
    dni = masc.dni;
    masc.get_nombre(aux);
    set_nombre(aux);
    masc.get_especie(aux);
    set_especie(aux);
    edad = masc.edad;
    peso = masc.peso;
    masc.get_colegiatura(aux);
    set_colegiatura(aux);
    numVacunas = masc.numVacunas;
}

void operator>>(ifstream &arch, class Mascota &masc) {
    char cadena[200], c;
    int dniCliente, edad;
    double peso;
    arch >> dniCliente;
    masc.set_dni(dniCliente);
    if (arch.eof()) return;
    arch >> c;
    arch.getline(cadena, 200, ',');
    masc.set_nombre(cadena);
    arch.getline(cadena, 200, ',');
    masc.set_especie(cadena);
    arch >> edad >> c >> peso >> c;
    masc.set_edad(edad);
    masc.set_peso(peso);
    arch.getline(cadena, 200, '\n');
    masc.get_colegiatura(cadena);
}

void operator<<(ofstream &rep, class Mascota &masc) {
    char nombre[200], especie[200];
    masc.get_nombre(nombre);
    masc.get_especie(especie);
    rep <<left<< setprecision(2) << fixed << "Mascota : " << nombre <<
            "(" << especie << "," << masc.get_edad() << "años," << masc.get_peso() << " kg" << ")" << endl;
}
