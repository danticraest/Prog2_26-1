//
// Created by alulab14 on 26/06/2026.
//

#ifndef STL_LABORATORIO09_ATENCION_H
#define STL_LABORATORIO09_ATENCION_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#include "Hora.h"
#include "Triaje.h"

class Atencion {
public:
    int get_fecha() const;

    void set_fecha(int fecha);

    string get_codigo_paciente() const;

    void set_codigo_paciente(const string &codigo_paciente);

    class Hora get_hora_ingreso() const;

    void set_hora_ingreso(const class Hora &hora_ingreso);

    class Hora get_hora_alta() const;

    void set_hora_alta(const class Hora &hora_alta);

    int get_codigo_medico() const;

    void set_codigo_medico(int codigo_medico);

    string get_codigo_triaje() const;

    void set_codigo_triaje(const string &codigo_triaje);

    class Hora get_duracion() const;

    void set_duracion(const class Hora &duracion);

    class Triaje get_triaje() const;

    void set_triaje(const class Triaje &triaje);

    Atencion();

    ~Atencion();

    //metodos de lectura e impresion

    void leer(ifstream &arch);

    void imprimir(ofstream &arch) const;

    bool operator<(const class Atencion &ate) const;

private:
    int fecha;
    string codigoPaciente;
    class Hora horaIngreso;
    class Hora horaAlta;
    int codigoMedico;
    string CodigoTriaje;
    class Hora duracion;
    class Triaje triaje;
};

//operadores de lectura e impresion de Atencion.h
void operator>>(ifstream &arch, class Atencion &ate);

void operator<<(ofstream &arch, const class Atencion &ate);

#endif //STL_LABORATORIO09_ATENCION_H
