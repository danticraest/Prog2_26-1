//
// Created by alulab14 on 12/06/2026.
//

#ifndef EMERGENCIASPROG2_ATENCION_H
#define EMERGENCIASPROG2_ATENCION_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Atencion {
public:
    int get_codigo() const;

    void set_codigo(int codigo);

    void get_paciente(char *pac) const;

    void set_paciente(const char *pac);

    void get_descripcion(char *desc) const;

    void set_descripcion(const char *desc);

    int get_hora() const;

    void set_hora(int hora);

    Atencion();

    Atencion(const class Atencion &ate);

    ~Atencion();

    void leer();

    void imprimir();

    virtual void obtener_prioridad();

private:
    int codigo;
    char *paciente;
    char *descripcion;
    int hora;
};


#endif //EMERGENCIASPROG2_ATENCION_H
