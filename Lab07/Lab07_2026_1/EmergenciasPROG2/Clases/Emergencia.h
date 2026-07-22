//
// Created by alulab14 on 12/06/2026.
//

#ifndef EMERGENCIASPROG2_EMERGENCIA_H
#define EMERGENCIASPROG2_EMERGENCIA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#include "Atencion.h"
using namespace std;

class Emergencia : public Atencion {
public:
    bool is_requiere_rcp() const;

    void set_requiere_rcp(bool requiere_rcp);

    int get_minutos_sin_pulso() const;

    void set_minutos_sin_pulso(int minutos_sin_pulso);

    Emergencia();

    Emergencia(const class Emergencia &em);

    ~Emergencia();

private:
    bool requiere_rcp;
    int minutos_sin_pulso;
};


#endif //EMERGENCIASPROG2_EMERGENCIA_H
