//
// Created by alulab14 on 24/04/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "funcionesAuxiliares.h"
#define INC 5
#define MAXL 200

void verifyLec(const char *nombre, ifstream &arch) {
    arch.open(nombre, ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
}

void verifyEsc(const char *nombre, ofstream &arch) {
    arch.open(nombre, ios::out);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
}

void cargarPacientes(const char *nombrePacientes, void *&pacientes) {
    ifstream archPacientes;
    verifyLec(nombrePacientes, archPacientes);
    int capacidad = 0, numDatos = 0;
    void **pacientesPadre = nullptr;
    while (true) {
        void *pacientesDatos = leerPacientes(archPacientes);
        if (archPacientes.eof()) break;
        if (capacidad == numDatos) incrementarCapacidad(pacientesPadre, capacidad, numDatos);
        pacientesPadre[numDatos] = pacientesDatos;
        numDatos++;
    }
    pacientesPadre[numDatos] = nullptr;
    pacientes = pacientesPadre;
}

void *leerPacientes(ifstream &archPacientes) {
    int *id = new int;
    char *nombre, *genero;
    int *edad = new int;
    double *costoTotal = new double;
    char cadena[200], c;
    archPacientes >> *id;
    if (archPacientes.eof()) return nullptr;
    archPacientes >> c;
    archPacientes.getline(cadena, 200, ',');
    asignarCadena(nombre, cadena);
    archPacientes >> *edad >> c;
    archPacientes.getline(cadena, 200, '\n');
    asignarCadena(genero, cadena);
    void **pacientesDatos = new void *[6]{};
    pacientesDatos[0] = id;
    pacientesDatos[1] = nombre;
    pacientesDatos[2] = edad;
    pacientesDatos[3] = genero;
    pacientesDatos[4] = nullptr;
    *costoTotal = 0.0; //de acuerdo al enunciado
    pacientesDatos[5] = costoTotal;
    return pacientesDatos;
}

void incrementarCapacidad(void **&padre, int &capacidad, int &numDatos) {
    capacidad += INC;
    if (padre == nullptr) {
        padre = new void *[capacidad]{};
    } else {
        void **aux = new void *[capacidad]{};
        for (int i = 0; i < numDatos; i++) {
            aux[i] = padre[i];
        }
        delete padre;
        padre = aux;
    }
}

void asignarCadena(char *&destino, char *origen) {
    destino = new char[strlen(origen) + 1];
    strcpy(destino, origen);
}


void reportePacientes(const char *repPacientes, void *pacientes) {
    ofstream outPacientes;
    verifyEsc(repPacientes, outPacientes);
    void **pacientesPadre = (void **) pacientes;
    outPacientes << left
           << setw(15) << "ID"
           << setw(17) << "Nombre"
           << setw(15) << "Edad"
           << setw(15) << "Genero"
           << setw(15) << "costo total" << endl;
    for (int i = 0; pacientesPadre[i]; i++) {
        void **pacientesDatos = (void **) pacientesPadre[i];
        outPacientes << left
                << setw(15) << *(int *) pacientesDatos[0]
                << setw(17) << (char *) pacientesDatos[1]
                << setw(15) << *(int *) pacientesDatos[2]
                << setw(15) << (char *) pacientesDatos[3]
                << setprecision(2) << fixed
                << setw(15) << *(double *) pacientesDatos[5] << endl;
    }
}

void cargarVisitas(const char *nombreVisitas, void *&pacientes) {
    ifstream archVisitas;
    verifyLec(nombreVisitas, archVisitas);
    int ano, mes, dia, hh, idPacienteVisita, costoAtencion, n;
    char c;
    while (true) {
        archVisitas >> ano;
        if (archVisitas.eof()) break;
        archVisitas >> c >> mes >> c >> dia >> c >> hh >> c >> n >> c >> idPacienteVisita >> c >> costoAtencion;

        void **pacientesPadre = (void **) pacientes;
        void **visitasSubPadre = (void **) pacientesPadre[5];

        for (int i = 0; pacientesPadre[i]; i++) {
            void **pacientesDatos = (void **) pacientesPadre[i];
            int capacidad = 0, numDatos = 0;
            if (*(int *) pacientesDatos[0] == idPacienteVisita) {
                void *visitasDatos = leerVisitas(ano, mes, dia, hh, costoAtencion);
                // double*costoAtencion2Aux = new double;
                // pacientesDatos[5]+=(double*)visitasDatos[2];

                if (capacidad == numDatos) incrementarCapacidad(visitasSubPadre, capacidad, numDatos);
                visitasSubPadre[numDatos] = visitasDatos;
                numDatos++;
            }
            visitasSubPadre[numDatos] = nullptr;
            pacientes = visitasSubPadre;

            if (numDatos > 0) pacientesPadre[4] = visitasSubPadre;
        }
    }
}

void *leerVisitas(int ano, int mes, int dia, int hh, double costoAtencion) {
    int *fechaAux = new int;
    *fechaAux = ano * 10000 + mes * 100 + dia;
    int *horaAux = new int;
    *horaAux = hh * 100;
    double *costoAtencionAux = new double;
    *costoAtencionAux = costoAtencion;

    void **visitasDatos = new void *[4]{};
    visitasDatos[0] = fechaAux;
    visitasDatos[1] = horaAux;
    visitasDatos[2] = costoAtencionAux;
    return visitasDatos;
}

void generarReporte(const char *nombreRep, void *&pacientes) {
    ofstream output;
    verifyEsc(nombreRep, output);
    void **pacientesPadre = (void **) pacientes;
    titulares(output);
    for (int i = 0; pacientesPadre[i]; i++) {
        void **pacientesDatos = (void **) pacientesPadre[i];
        output << left
                << setw(15) << *(int *) pacientesDatos[0]
                << setw(17) << (char *) pacientesDatos[1]
                << setw(15) << *(int *) pacientesDatos[2]
                << setw(15) << (char *) pacientesDatos[3];

        void **visitasSubPadre = (void **) pacientesPadre[4];
        for (int j = 0; visitasSubPadre[j]; j++) {
            void **visitasDatos = (void **) visitasSubPadre[j];
            output <<setw(15)<<"0"<< visitasDatos[2];
        }
        output << endl;
    }
}

void titulares(ofstream &output) {
    linea('=', MAXL, output);
    output << "REPORTE DEL SISTEMA DE URGENCIAS" << endl;
    linea('=', MAXL, output);
    linea('-', MAXL, output);
    output << left
            << setw(15) << "ID"
            << setw(17) << "Nombre"
            << setw(15) << "Edad"
            << setw(15) << "Genero"
            << setw(15) << "Visitas"
            << setw(15) << "Total (S/)" << endl;
    linea('-', MAXL, output);
}

void linea(char type, int space, ofstream &output) {
    for (int i = 0; i < space; i++) {
        output << type;
    }
    output << endl;
}
