//
// Created by alulab14 on 10/04/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#include "EstructuraHuellitas.h"
using namespace std;
#include "sobreCargadores.h"

void operator >>(ifstream &archMascota, struct Mascota &arrMascota) {
    int dia, mes, ano;
    char c;
    archMascota >> arrMascota.idMascota;
    if (archMascota.eof()) return;
    archMascota.get(); //coma
    archMascota.getline(arrMascota.nombre, 20, ',');
    archMascota.getline(arrMascota.raza, 20, ',');
    archMascota.getline(arrMascota.color, 20, ',');
    archMascota.getline(arrMascota.tipo, 20, ',');
    archMascota >> dia >> c >> mes >> c >> ano >> ws;
    arrMascota.fechaNaci = ano * 10000 + mes * 100 + dia;
}

void operator>>(ifstream &archVet, struct Veterinario &arrVet) {
    archVet >> arrVet.idVeterinario;
    if (archVet.eof()) return;
    archVet.get(); //coma
    archVet.getline(arrVet.nombre, 40, ',');
    archVet.getline(arrVet.especialidad, 20, '\n');
}

void operator>>(ifstream &archAten, struct Atencion &arrAten) {
    int dia, mes, ano;
    char c;
    static int correlativo = 1001;
    archAten >> arrAten.idMascota;
    if (archAten.eof()) return;
    archAten.get(); //coma
    archAten >> arrAten.idVeterinario;
    archAten.get(); //coma
    archAten >> dia >> c >> mes >> c >> ano;
    archAten.get(); //coma
    arrAten.fecha = ano * 10000 + mes * 100 + dia;
    archAten.getline(arrAten.tipoAtencion, 30, ',');
    archAten >> arrAten.hora >> c >> arrAten.min;
    archAten.get();
    archAten.getline(arrAten.estado, 20, '\n');
    arrAten.idAtencion = correlativo++;
}

// arrAten[0]==arrAten[1];
//son iguales si es a la misma hora y misma fecha (regla #2)
bool operator==(struct Atencion &aten1, struct Atencion &aten2) {
    if (aten1.fecha == aten2.fecha and aten1.hora == aten2.hora) return true;
    else return false;
}

bool operator<=(struct Mascota &arrMascotas, int hoy) {
    if (arrMascotas.fechaNaci <= hoy) return true;
    else return false;
}

void operator<<(ofstream &output, struct Mascota arrMascot) {
    output << "ID: " << arrMascot.idMascota << endl;
    output << "Nombre: " << arrMascot.nombre << endl;
    output << "Raza: " << arrMascot.raza << endl;
    output << "Color: " << arrMascot.color << endl;
    output << "Tipo: " << arrMascot.tipo << endl;
}

void operator<<(ofstream &output, struct Atencion arrAten) {
    output << "Fecha: " << arrAten.fecha << ", ID: " << arrAten.idAtencion << ", Veterinario: "
            << arrAten.idVeterinario << ", Tipo: " << arrAten.tipoAtencion << ", Estado: " << arrAten.estado << endl;
}
