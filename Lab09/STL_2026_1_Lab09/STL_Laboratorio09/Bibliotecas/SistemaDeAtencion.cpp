//
// Created by alulab14 on 26/06/2026.
//

#include "SistemaDeAtencion.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Atencion.h"
#include "Triaje.h"
#include "Medico.h"
#include "Paciente.h"
using namespace std;
#define MAXL 150

void SistemaDeAtencion::cargarPacientes(const char *nombre) {
    ifstream arch(nombre, ios::in);
    if (!arch.is_open()) {
        cout << "no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
    class Paciente pac;
    while (true) {
        arch >> pac;
        if (arch.eof()) break;
        pacientes.push_back(pac);
        //requiere sobrecargador
    }
}

void SistemaDeAtencion::cargarMedicos(const char *nombre) {
    ifstream arch(nombre, ios::in);
    if (!arch.is_open()) {
        cout << "no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
    class Medico med;
    while (true) {
        arch >> med;
        if (arch.eof()) break;
        medicos.push_back(med);
    }
    medicos.sort(); //se requiere un operador para activar el sort
}

void SistemaDeAtencion::cargarTriajes(const char *nombre) {
    ifstream arch(nombre, ios::in);
    if (!arch.is_open()) {
        cout << "no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
    class Triaje tri;
    while (true) {
        arch >> tri;
        if (arch.eof()) break;
        triajes[tri.get_codigo_triaje()] = tri; //el primer elemento sera el codigo del triaje
    }
}

void SistemaDeAtencion::cargarAtenciones(const char *nombre) {
    ifstream arch(nombre, ios::in);
    if (!arch.is_open()) {
        cout << "no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
    class Atencion ate;
    while (true) {
        arch >> ate;
        if (arch.eof()) break;
        atenciones.push_back(ate);
    }
    atenciones.sort(); //se requiere un operador para activar el sort
}

void SistemaDeAtencion::llenarAtenciones() {
}

void SistemaDeAtencion::llenarAtencionesDePacientes() {
    for (auto a: atenciones) {
        for (auto p: pacientes) {
            if (p.get_codigo() == a.get_codigo_paciente())
                p.agregarAtencionP(a);
        }
    }
}

void SistemaDeAtencion::llenarAtencionesDeMedicos() {
    for (auto m: medicos) {
        for (auto a: atenciones) {
            if (m.get_codigo() == a.get_codigo_medico())
                m.agregarAtencion(a);
        }
    }
}

void SistemaDeAtencion::reporteDeAtencionesPorPaciente(const char *nombre) {
    ofstream archOut(nombre, ios::out);
    if (!archOut.is_open()) {
        cout << "no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }

    linea(archOut,MAXL, '=');
    archOut << right << setw(70) << "ATENCIONES POR PACIENTE" << endl;
    linea(archOut,MAXL, '-');
    for (auto p: pacientes) {
        p.imprimir(archOut);
        archOut << left << setw(20) << "FECHA" << setw(20) << "MEDICO" << setw(20) << "INICIO"
                << setw(20) << "ALTA" << setw(20) << "DURACION" << setw(20) << "F. CARDIACA"
                << setw(20) << "P. SIST." << setw(20) << "P. DIAST." << setw(20) << "TEMPERATURA" << setw(20) <<
                "SATURACION" << endl;
        llenarAtencionesDePacientes();
        archOut << "INGRESOS POR ATENCIONES:" << p.get_gastos_por_atencion()<<endl;
        linea(archOut,MAXL, '-');
    }
}

void SistemaDeAtencion::reporteDeAtencionesPorMedico(const char *nombre) {
    ofstream archOut(nombre, ios::out);
    if (!archOut.is_open()) {
        cout << "no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }

    linea(archOut,MAXL, '=');
    archOut << right << setw(70) << "ATENCIONES POR MEDICO" << endl;
    linea(archOut,MAXL, '-');
    for (auto m: medicos) {
        m.imprimir(archOut);
        archOut << "ATENCIONES:" << endl;
        archOut << left << setw(20) << "FECHA" << setw(20) << "PACIENTE" << setw(20) << "INICIO"
                << setw(20) << "ALTA" << setw(20) << "DURACION" << setw(20) << "F. CARDIACA"
                << setw(20) << "P. SIST." << setw(20) << "P. DIAST." << setw(20) << "TEMPERATURA" << setw(20) <<
                "SATURACION" << endl;
        llenarAtencionesDeMedicos();
        archOut << "INGRESOS POR ATENCIONES:" << m.get_pagos_por_atencion() << endl;
        linea(archOut,MAXL, '-');
    }
}

void SistemaDeAtencion::linea(ofstream &archOut, int space, char type) {
    for (int i = 0; i < space; i++) {
        archOut << type;
    }
    archOut << endl;
}
