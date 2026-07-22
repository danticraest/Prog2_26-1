//
// Created by alulab14 on 26/06/2026.
//

#ifndef STL_LABORATORIO09_PACIENTE_H
#define STL_LABORATORIO09_PACIENTE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#include <list>
#include "Atencion.h"

class Paciente {
public:
    string get_codigo() const;

    void set_codigo(const string &codigo);

    string get_nombre() const;

    void set_nombre(const string &nombre);

    char get_sexo() const;

    void set_sexo(char sexo);

    int get_edad() const;

    void set_edad(int edad);

    double get_gastos_por_atencion() const;

    void set_gastos_por_atencion(double gastos_por_atencion);

    Paciente();

    ~Paciente();

    //metodos de lectura e impresion

    void leer(ifstream &arch);

    void imprimir(ofstream &arch) const;

    void agregarAtencionP(const class Atencion &med);

private:
    string codigo;
    string nombre;
    char sexo;
    int edad;
    list<class Atencion> atenciones;
    double gastosPorAtencion;
};

//operadores de lectura e impresion de Paciente.h
void operator>>(ifstream &arch, class Paciente &pac);

void operator<<(ofstream &arch, const class Paciente &pac);
#endif //STL_LABORATORIO09_PACIENTE_H
