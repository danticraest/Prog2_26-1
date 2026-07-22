//
// Created by alulab14 on 5/06/2026.
//

#ifndef LABORATORIO06_VACUNA_H
#define LABORATORIO06_VACUNA_H


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Cita.h"
using namespace std;

class Vacuna : public Cita {
public:
    int get_dosis() const;

    void set_dosis(int dosis);

    int get_meses() const;

    void set_meses(int meses);

    //creacion constructor, destructor,constructor copia
    Vacuna();

    Vacuna(const Vacuna &vac);

    void operator=(const Vacuna &vac);

    ~Vacuna();

private:
    int dosis;
    int meses;
};


#endif //LABORATORIO06_VACUNA_H
