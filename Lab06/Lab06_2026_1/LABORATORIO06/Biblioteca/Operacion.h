//
// Created by alulab14 on 5/06/2026.
//

#ifndef LABORATORIO06_OPERACION_H
#define LABORATORIO06_OPERACION_H
#include "Cita.h"


class Operacion : public Cita {
public:
    bool is_anestesiageneral() const;

    void set_anestesiageneral(bool anestesiageneral);

    int get_nummedicos() const;

    void set_nummedicos(int nummedicos);

    double get_total() const;

    void set_total(double total);
    //creacion constructor, destructor,constructor copia
    Operacion();

    Operacion(const class Operacion &ope);

    ~Operacion();

private:
    bool anestesiageneral;
    int nummedicos;
    double total;
};


#endif //LABORATORIO06_OPERACION_H
