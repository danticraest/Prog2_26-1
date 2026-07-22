//
// Created by alulab14 on 5/06/2026.
//

#ifndef LABORATORIO06_CITA_H
#define LABORATORIO06_CITA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Mascota.h"

class Cita {
public:
    int get_fecha() const;

    void set_fecha(int fecha);

    int get_hora() const;

    void set_hora(int hora);

    class Mascota get_amascota() const;

    void set_amascota(const class Mascota &amascota);

    //creacion constructor, destructor
    Cita();

    ~Cita();

    void leerCita(ifstream &arch);

    void imprimirCita(ofstream &arch);

private:
    int fecha;
    int hora;
    class Mascota Amascota;
};


#endif //LABORATORIO06_CITA_H
