//
// Created by alulab14 on 26/06/2026.
//

#ifndef STL_LABORATORIO09_MEDICO_H
#define STL_LABORATORIO09_MEDICO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#include <vector>
#include "Atencion.h"

class Medico {
public:
    int get_codigo() const;

    void set_codigo(int codigo);

    string get_nombre() const;

    void set_nombre(const string &nombre);

    double get_tarifa() const;

    void set_tarifa(double tarifa);

    string get_especialidad_nombre() const;

    void set_especialidad_nombre(const string &especialidad_nombre);

    vector<class Atencion> get_atenciones() const;

    void set_atenciones(const vector<class Atencion> &atenciones);

    double get_pagos_por_atencion() const;

    void set_pagos_por_atencion(double pagos_por_atencion);

    Medico();

    ~Medico();

    //metodos de lectura e impresion

    void leer(ifstream &arch);

    void imprimir(ofstream &arch) const;

    bool operator<(const class Medico &med) const;

    void agregarAtencion(const class Atencion &med);

private:
    int codigo;
    string nombre;
    double tarifa;
    string especialidadNombre;
    vector<class Atencion> atenciones;
    double pagosPorAtencion;
};

//operadores de lectura e impresion en Medico.h
void operator>>(ifstream &arch, class Medico &med);

void operator<<(ofstream &arch, const class Medico &med);


#endif //STL_LABORATORIO09_MEDICO_H
