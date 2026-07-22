//
// Created by alulab14 on 19/06/2026.
//

#ifndef ATENCIONESPORPRIORIDADPROG2_URGENCIA_H
#define ATENCIONESPORPRIORIDADPROG2_URGENCIA_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "Atencion.h"

using namespace std;

class Urgencia : public Atencion {
private:
    char *zona_lesion;
    bool necesita_rx;

public:
    void get_zona_lesion(char *) const;

    void set_zona_lesion(const char *);

    bool get_necesita_rx() const;

    void set_necesita_rx(const bool necesita_rx);

    void leer(ifstream &, int);

    void imprimir(ofstream &) const;

    int obtenerPrioridad() const;
    //SE AÑADIO :

    Urgencia();

    Urgencia(const class Urgencia &urg);

    void operator=(const class Urgencia &urg);

    ~Urgencia();
};


#endif //ATENCIONESPORPRIORIDADPROG2_URGENCIA_H
