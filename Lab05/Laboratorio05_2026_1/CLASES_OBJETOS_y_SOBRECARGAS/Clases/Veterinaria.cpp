//
// Created by alulab14 on 15/05/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Veterinaria.h"

Veterinaria::Veterinaria() {
    numMascotas = 0;
}

Veterinaria::~Veterinaria() {
}

void Veterinaria::operator<=(const char *nombreMascotas) {
    ifstream archMascotas(nombreMascotas, ios::in);
    if (!archMascotas.is_open()) {
        cout << "No se pudo abrir el archivo " << nombreMascotas << endl;
        exit(1);
    }
    class Mascota aux[200];
    int numAux = 0;
    while (true) {
        archMascotas >> aux[numAux];
        if (archMascotas.eof())break;
        numAux++;
    }
    numMascotas = numAux;
    for (int i = 0; i < numAux; i++) listaDeMascotas[i] = aux[i];
}

// int Veterinaria::operator+=(int mascota, class VacunaAplicada &vac) {
//
// }

// int buscarNombreMascota(char *nombreMascota, class Mascota &masc) {
//     for (int i = 0; i < mascnumMascotas; i++) {}
// }

void Veterinaria::operator<<=(const char *nombreVacunas) {
    class Mascota masc;
    // class VacunaAplicada &vac;
    ifstream archVacunas(nombreVacunas, ios::in);
    if (!archVacunas.is_open()) {
        cout << "No se pudo abrir el archivo " << nombreVacunas << endl;
        exit(1);
    }
    //leer los dos primeros datos, VacunasAplicadas y DNI, buscar por mascota y cliente y leer el resto de datos

    // char nombMasc[200],c;
    // int dni;
    // archVacunas.getline(nombMasc, 200, ',');
    // archVacunas>> dni >> c;
    // int posMascota=buscarNombreMascota(nombMasc, masc);
    // archVacunas>>VacunaAplicada &vac);

}

void Veterinaria::operator<<(const char *reporteFinal) {
    ofstream archOut(reporteFinal, ios::out);
    if (!archOut.is_open()) {
        cout << "no se pudo abrir el archivo " << reporteFinal << endl;
        exit(1);
    }

    archOut << "REPORTE DE CARTILLAS - VETERINARIA HUELLITAS Y PLUMITAS" << endl;
    for (int i = 0; i < numMascotas; i++) {
        archOut << listaDeMascotas[i];
    }
}
