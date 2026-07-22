//
// Created by alulab14 on 19/06/2026.
//

#ifndef ATENCIONESPORPRIORIDADPROG2_GESTORATENCIONES_H
#define ATENCIONESPORPRIORIDADPROG2_GESTORATENCIONES_H
#include "Atencion.h"
#include "ListaDoble.h"
#include "../utils/Utils.h"


class GestorAtenciones : public Utils {
private:
    Atencion **atenciones;

    int cantidad_atenciones;

    int capacidad;

public:
    GestorAtenciones();

    ~GestorAtenciones();

    void cargar_atenciones(const char *nombreArchivo, int);

    void agregar_atencion(Atencion *);

    void procesar_dia(const char *fecha);

    void generar_reporte_diario(const char *nombre_reporte);

    Atencion *reservar_memoria_atencion(char);

    void reservar_memoria();

    void atenciones_prioridad(class ListaDoble);

    void linea(ofstream &out, int space, char type);

    //metodos nuevos
    void cargar_atenciones_prioridad(const char *nombreArchivo);

    void imprimir_atenciones_prioridad(const char *nombre_reporte);
};


#endif //ATENCIONESPORPRIORIDADPROG2_GESTORATENCIONES_H
