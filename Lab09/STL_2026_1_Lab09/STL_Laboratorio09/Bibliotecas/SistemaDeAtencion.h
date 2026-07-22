//
// Created by alulab14 on 26/06/2026.
//

#ifndef STL_LABORATORIO09_SISTEMADEATENCION_H
#define STL_LABORATORIO09_SISTEMADEATENCION_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#include <list>
#include <map>
#include "Atencion.h"
#include "Triaje.h"
#include "Medico.h"
#include "Paciente.h"
class SistemaDeAtencion {
public:
    //CARGAS

    void cargarPacientes(const char *nombre);

    void cargarMedicos(const char *nombre);

    void cargarTriajes(const char *nombre);

    void cargarAtenciones(const char *nombre);

    //COMPLETAR

    void llenarAtenciones();

    void llenarAtencionesDePacientes();

    void llenarAtencionesDeMedicos();

    //REPORTES

    void reporteDeAtencionesPorPaciente(const char *nombre);

    void reporteDeAtencionesPorMedico(const char *nombre);

    void linea(ofstream &archOut, int space, char type);

private:
    list<class Atencion> atenciones;
    map<string, class Triaje> triajes;
    vector<class Paciente> pacientes;
    list<class Medico> medicos;
};


#endif //STL_LABORATORIO09_SISTEMADEATENCION_H
