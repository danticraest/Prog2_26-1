//
// Created by alulab14 on 19/06/2026.
//

#ifndef ATENCIONESPORPRIORIDADPROG2_NOURGENCIA_H
#define ATENCIONESPORPRIORIDADPROG2_NOURGENCIA_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "Atencion.h"

using namespace std;

class NoUrgencia : public Atencion {
private:
    char *especialidad;
    bool es_consulta_programada;

public:
    void get_especialidad(char *) const;

    void set_especialidad(const char *);

    bool get_es_consulta_programada() const;

    void set_es_consulta_programada(bool es_consulta_programada);

    void leer(ifstream &, int);

    void imprimir(ofstream &) const;

    int obtenerPrioridad() const;

    //SE AÑADIO :
    NoUrgencia();

    NoUrgencia(const class NoUrgencia &nour);

    void operator=(const class NoUrgencia &nour);

    ~NoUrgencia();
};


#endif //ATENCIONESPORPRIORIDADPROG2_NOURGENCIA_H
