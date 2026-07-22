//
// Created by alulab14 on 8/05/2026.
//


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "BibliotecaRegistros.h"

void *leeregistro(ifstream &arch) {
    int *fecha = new int;
    int *hora = new int;
    int *codigo = new int;
    char *nombre, *raza, *color;
    char cadena[200], c;
    int dd, mm, aa, hor, min;
    arch >> *codigo >> c >> dd >> c >> mm >> c >> aa >> c;
    arch.getline(cadena, 200, ',');
    arch >> hor >> c >> min >> c;
    arch.getline(cadena, 200, ','); //PROGRAMADA
    arch.getline(cadena, 200, ','); //Luna
    asignarCadena(nombre, cadena);
    arch.getline(cadena, 200, ','); //Labrador
    asignarCadena(raza, cadena);
    arch.getline(cadena, 200, ','); //negro
    asignarCadena(color, cadena);
    arch.getline(cadena, 200, '\n'); //CANINO

    void **elementos = new void *[6];
    *fecha = aa * 10000 + mm * 100 + dd;
    *hora = hor * 100;
    elementos[0] = fecha;
    elementos[1] = hora;
    elementos[2] = codigo;
    elementos[3] = nombre;
    elementos[4] = raza;
    elementos[5] = color;
    void **aux = new void *[2];
    aux[0] = elementos;
    aux[1] = nullptr;
    return aux;
}

void asignarCadena(char *&destino, char *origen) {
    destino = new char[strlen(origen) + 1];
    strcpy(destino, origen);
}

int comparareg(const void *a, const void *b) {
    int datoA, datoB;
    void **aa = (void **) a;
    void **bb = (void **) b;
    // datoA = (void **) aa[0];
    // datoB = (void **) bb[0];
    return datoA - datoB;
}

void verificareg(void *elemento) {
}

void imprimeregistro(void *nodoElementos, ofstream &out) {
    void **nodoDatos = (void **) nodoElementos;
    out << *(int *) nodoDatos << endl;
}
