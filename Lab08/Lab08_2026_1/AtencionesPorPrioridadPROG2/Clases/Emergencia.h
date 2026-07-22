//
// Created by alulab14 on 19/06/2026.
//

#ifndef ATENCIONESPORPRIORIDADPROG2_EMERGENCIA_H
#define ATENCIONESPORPRIORIDADPROG2_EMERGENCIA_H
#include "Atencion.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

class Emergencia : public Atencion {
public:
    bool get_requiere_rcp() const;

    void set_requiere_rcp(bool requiere_rcp);

    int get_minutos_sin_pulso() const;

    void set_minutos_sin_pulso(int minutos_sin_pulso);

private:
    bool requiere_rcp;
    int minutos_sin_pulso;

public:
    //SE AÑADIO :

    Emergencia();

    Emergencia(const class Emergencia &eme);

    void operator=(const class Emergencia &eme);

    ~Emergencia();

    //

    void leer(ifstream &, int);

    void imprimir(ofstream &) const;

    int obtenerPrioridad() const;
};


#endif //ATENCIONESPORPRIORIDADPROG2_EMERGENCIA_H
