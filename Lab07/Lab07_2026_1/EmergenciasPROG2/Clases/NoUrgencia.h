//
// Created by alulab14 on 12/06/2026.
//

#ifndef EMERGENCIASPROG2_NOURGENCIA_H
#define EMERGENCIASPROG2_NOURGENCIA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class NoUrgencia {
public:
    void get_especialidad(char*espe) const;

    void set_especialidad(const char *espe);

    bool is_es_consulta_programada() const;

    void set_es_consulta_programada(bool es_consulta_programada);

    NoUrgencia();
    NoUrgencia(const class NoUrgencia& nour);

    ~NoUrgencia();

private:
    char *especialidad;
    bool es_consulta_programada;
};


#endif //EMERGENCIASPROG2_NOURGENCIA_H
