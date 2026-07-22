//
// Created by alulab14 on 5/06/2026.
//

#ifndef LABORATORIO06_CONTROL_H
#define LABORATORIO06_CONTROL_H
#include "Cita.h"


class Control : public Cita {
public:
    double get_costo() const;

    void set_costo(double costo);

    int get_codmed() const;

    void set_codmed(int codmed);
    //creacion constructor, destructor
    Control();

    ~Control();

    void leerControl(ifstream &arch);

private:
    double costo;
    int codmed;
};


#endif //LABORATORIO06_CONTROL_H
