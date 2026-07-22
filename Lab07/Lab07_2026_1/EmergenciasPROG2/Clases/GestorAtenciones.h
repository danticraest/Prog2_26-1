//
// Created by alulab14 on 12/06/2026.
//

#ifndef EMERGENCIASPROG2_GESTORATENCIONES_H
#define EMERGENCIASPROG2_GESTORATENCIONES_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Atencion.h"

class GestorAtenciones {
public:
    class Atencion *get_atenciones() const;

    void set_atenciones(class Atencion *atenciones);

    int get_cantidad_atenciones() const;

    void set_cantidad_atenciones(int cantidad_atenciones);

    int get_capacidad() const;

    void set_capacidad(int capacidad);

    GestorAtenciones();

    GestorAtenciones(const class GestorAtenciones &ges);

    ~GestorAtenciones();

    void reservar_memoria();

    void reservar_memoria_atencion(char tipo);

    void agregar_atencion(Atencion *);

    void cargar_atenciones(const char *nombre_archivo, int hora);

    void procesar_dia(const char *fecha);

    void generar_reporte_diario(const char *nombre_reporte);

    void linea(ofstream &arch, int space, char type);

private:
    class Atencion *atenciones; //(se puede cambiar a estatico)
    int cantidad_atenciones;
    int capacidad;
    //se hace INC
};


#endif //EMERGENCIASPROG2_GESTORATENCIONES_H
