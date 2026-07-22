//
// Created by alulab14 on 5/06/2026.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Cita.h"
#include "Control.h"
#include "Mascota.h"
#include "Operacion.h"
#include "Vacuna.h"
#include "Veterinaria.h"
#define INC 5

Vacuna Veterinaria::get_arr_vacuna() const {
    return arrVacuna;
}

void Veterinaria::set_arr_vacuna(const Vacuna &arr_vacuna) {
    arrVacuna = arr_vacuna;
}

Operacion Veterinaria::get_arr_operacion() const {
    return arrOperacion;
}

void Veterinaria::set_arr_operacion(const Operacion &arr_operacion) {
    arrOperacion = arr_operacion;
}

Control *Veterinaria::get_arr_control() const {
    return arrControl;
}

void Veterinaria::set_arr_control(Control *arr_control) {
    arrControl = arr_control;
}

int Veterinaria::get_numdat_control() const {
    return numdatControl;
}

void Veterinaria::set_numdat_control(int numdat_control) {
    numdatControl = numdat_control;
}

int Veterinaria::get_capa_control() const {
    return capaControl;
}

void Veterinaria::set_capa_control(int capa_control) {
    capaControl = capa_control;
}

Veterinaria::Veterinaria() {
    arrControl = nullptr;
    numdatControl = 0;
    capaControl = 0;
}

Veterinaria::Veterinaria(const class Veterinaria &vet) {
    arrControl = nullptr;
    numdatControl = 0;
    capaControl = 0;
    *this = vet;
}

void Veterinaria::operator=(const class Veterinaria &vet) {
    set_arr_control(vet.get_arr_control());
    numdatControl = vet.get_numdat_control();
    capaControl = vet.get_capa_control();
}

Veterinaria::~Veterinaria() {
    delete[]arrControl;
}

void Veterinaria::cargacitas() {
    ifstream arch("ArchivosDeDatos/Atenciones.csv", ios::in);
    if (!arch.is_open()) {
        cout << "no se pudo abrir el archivo atenciones.csv" << endl;
        exit(1);
    }
    char tipoCita;
    class Vacuna vacuna[200]{};
    class Operacion operacion[200]{};
    numdatControl = 0, capaControl = 0;
    while (true) {
        arch >> tipoCita;
        if (arch.eof()) break;
        arch.get(); //coma
        if (tipoCita == 'C') {
            //metodo de memoria por incrementos
            if (numdatControl == capaControl) incremetarCapacidadC(numdatControl, capaControl);
            //leerControl trata de todos los datos de Cita, Mascota, codMedico
            //se requiere que leerControl pueda leer toda la linea correspondiente
            arrControl[numdatControl].leerControl(arch);
            numdatControl++;
        }
        // else if (tipoCita == 'V') {
        // } else if (tipoCita == 'O') {
        // }
    }
}

void Veterinaria::incremetarCapacidadC(int &numdatControl, int &capaControl) {
    capaControl += INC;
    class Control *aux = new class Control[capaControl]{};
    if (arrControl != nullptr) {
        for (int i = 0; i < numdatControl; i++) aux[i] = arrControl[i];
        delete [] arrControl;
    }
    arrControl = aux;
}

void Veterinaria::muestracitas() {
    ofstream arch("ArchivosDeReporte/reporte.txt", ios::out);
    if (!arch.is_open()) {
        cout << "no se pudo abrir el archivo reporte.txt" << endl;
        exit(1);
    }
    arch << "Citas de Control:" << endl;
    for (int i = 0; i < numdatControl; i++) citasControl(arch,i);
    arch << "Citas de Vacunas:" << endl;
    // for (int i = 0; i < numdatVacuna; i++)    citasVacuna(arch);
    arch << "Citas de Operaciones:" << endl;
    // for (int i = 0; i < numdatOperacion; i++)    citasOperacion(arch);
}

void Veterinaria::citasControl(ofstream &arch, int i) {
    //se estaria imprimiendo la fecha y hora por cada mascota i= 0 1 2 3 4
    arrControl[i].imprimirCita(arch);
    // get_fecha() <<
    //         setw(15) << arrControl[numdatControl].get_hora();
    // // arch<<setw(15)<< arrControl[numdatControl].get_amascota();
    // arch << setw(15) << arrControl[numdatControl].get_codmed();
}

void Veterinaria::citasVacuna(ofstream &arch) {
}

void Veterinaria::citasOperacion(ofstream &arch) {
}
