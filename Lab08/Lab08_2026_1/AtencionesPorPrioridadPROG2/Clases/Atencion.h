//
// Created by alulab14 on 19/06/2026.
//

#ifndef ATENCIONESPORPRIORIDADPROG2_ATENCION_H
#define ATENCIONESPORPRIORIDADPROG2_ATENCION_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

class Atencion {
private:
    int codigo;
    string paciente;
    string descripcion;
    int hora_ingreso;

public:
    string get_paciente() const;

    void set_paciente(const string &paciente);

    string get_descripcion() const;

    void set_descripcion(const string &descripcion);

    Atencion();

    Atencion(const class Atencion &ate);

    virtual void operator=(const class Atencion &ate);

    virtual ~Atencion() = default;

    virtual void leer(ifstream &, int);

    virtual void imprimir(ofstream &) const;

    virtual int obtenerPrioridad() const =0;

    int get_codigo() const;

    void set_codigo(int codigo);

    int get_hora_ingreso() const;

    void set_hora_ingreso(int hora_ingreso);

    //metodos virtuales nuevos

    virtual int conseguir_llave(int codigo);

    virtual void clonar();
};


#endif //ATENCIONESPORPRIORIDADPROG2_ATENCION_H
