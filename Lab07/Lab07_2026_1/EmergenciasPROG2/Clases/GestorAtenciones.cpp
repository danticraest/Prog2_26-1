//
// Created by alulab14 on 12/06/2026.
//

#include "GestorAtenciones.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#include "../Utils/utils.h"
#define MAXL 200
using namespace std;
#include "Atencion.h"


class Atencion *GestorAtenciones::get_atenciones() const {
    return atenciones;
}

void GestorAtenciones::set_atenciones(class Atencion *atenciones) {
    this->atenciones = atenciones;
}

int GestorAtenciones::get_cantidad_atenciones() const {
    return cantidad_atenciones;
}

void GestorAtenciones::set_cantidad_atenciones(int cantidad_atenciones) {
    this->cantidad_atenciones = cantidad_atenciones;
}

int GestorAtenciones::get_capacidad() const {
    return capacidad;
}

void GestorAtenciones::set_capacidad(int capacidad) {
    this->capacidad = capacidad;
}

GestorAtenciones::GestorAtenciones() {
    atenciones = nullptr;
    cantidad_atenciones = 0;
    capacidad = 0;
}

GestorAtenciones::GestorAtenciones(const class GestorAtenciones &ges) {
    atenciones = nullptr;
    cantidad_atenciones = 0;
    capacidad = 0;
    *this = ges;
}


GestorAtenciones::~GestorAtenciones() {
    delete atenciones;
}

void GestorAtenciones::reservar_memoria() {

    capacidad += 5;
    if (cantidad_atenciones ==0) {
        Atencion *aux=new Atencion[capacidad];

    }
}

void GestorAtenciones::reservar_memoria_atencion(char tipo) {
}

void GestorAtenciones::agregar_atencion(Atencion *) {
}

void GestorAtenciones::cargar_atenciones(const char *nombre_archivo, int hora) {
}

void GestorAtenciones::procesar_dia(const char *fecha) {
    int hor = 0;
    construir_nombre_archivo("fechaActual", fecha, hor);


}

void GestorAtenciones::linea(ofstream &arch, int space, char type) {
    for (int i = 0; i < space; i++) {
        arch << type;
    }
    arch << endl;
}

void GestorAtenciones::generar_reporte_diario(const char *nombre_reporte) {
    ofstream outRep(nombre_reporte, ios::out);
    if (!outRep.is_open()) {
        cout << "Error al abrir el archivo " << nombre_reporte << endl;
        exit(1);
    }
    if ()
    linea(outRep, MAXL, '=');
    outRep << "HORA:" << endl;
    linea(outRep, MAXL, '=');
    linea(outRep, MAXL, '=');
    outRep << "EMERGENCIAS:" << endl;
    linea(outRep, MAXL, '=');
    outRep << left << setw(15) << "CODIGO" << setw(15) << "NOMBRES" << setw(15) << "DESCRIPCION" <<
            setw(15) << "RCP?" << setw(15) << "NO_PULSO" << setw(15) << "OBSERVACION" << endl;
    linea(outRep, MAXL, '=');

    outRep << "URGENCIAS:" << endl;
    linea(outRep, MAXL, '=');
    outRep << left << setw(15) << "CODIGO" << setw(15) << "NOMBRES" << setw(15) << "DESCRIPCION" <<
            setw(15) << "ZONA_LESION" << setw(15) << "RX?" << setw(15) << "OBSERVACION" << endl;
    linea(outRep, MAXL, '=');

    outRep << "EMERGENCIAS:" << endl;
    linea(outRep, MAXL, '=');
    outRep << left << setw(15) << "CODIGO" << setw(15) << "NOMBRES" << setw(15) << "DESCRIPCION" <<
            setw(15) << "ESPECIALIDAD" << setw(15) << "CONSULTA_PROGRAMADA" << endl;
    linea(outRep, MAXL, '=');
}
