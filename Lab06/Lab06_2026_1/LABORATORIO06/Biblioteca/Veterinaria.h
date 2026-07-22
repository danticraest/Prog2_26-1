//
// Created by alulab14 on 5/06/2026.
//

#ifndef LABORATORIO06_VETERINARIA_H
#define LABORATORIO06_VETERINARIA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Control.h"
#include "Operacion.h"
#include "Vacuna.h"
using namespace std;

class Veterinaria {
public:
    Vacuna get_arr_vacuna() const;

    void set_arr_vacuna(const Vacuna &arr_vacuna);

    Operacion get_arr_operacion() const;

    void set_arr_operacion(const Operacion &arr_operacion);

    Control *get_arr_control() const;

    void set_arr_control(Control *arr_control);



    int get_numdat_control() const;

    void set_numdat_control(int numdat_control);

    int get_capa_control() const;

    void set_capa_control(int capa_control);

    //constructor, destructor, constructor copia, operador de asignacion
    Veterinaria();

    Veterinaria(const class Veterinaria &vet);

    void operator=(const class Veterinaria &vet);

    ~Veterinaria();

    void cargacitas();

    void incremetarCapacidadC(int &numdatControl, int &capaControl);

    void muestracitas();

    void citasControl(ofstream &arch,int i);

    void citasVacuna(ofstream &arch);

    void citasOperacion(ofstream &arch);

private:
    Control *arrControl;
    Vacuna arrVacuna;
    Operacion arrOperacion;
    int numdatControl;
    int capaControl;
};


#endif //LABORATORIO06_VETERINARIA_H
