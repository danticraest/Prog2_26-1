//
// Created by alulab14 on 8/05/2026.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "BibliotecaEnteros.h"

void *leenum(ifstream &arch) {
    int *num = new int;
    arch >> *num;
    if (arch.eof()) return nullptr;
    void *aux = new void *[1];
    return aux;
}

int comparanum(const void *a, const void *b) {
    int datoA, datoB;
    void **aa = (void **) a;
    void **bb = (void **) b;
    // datoA = (void **) aa[0];
    // datoB = (void **) bb[0];
    return datoA - datoB;
}

void verificanum(void *elemento) {

}

void imprimenum(void *nodoElementos, ofstream &out) {
    void **nodoDatos = (void **) nodoElementos;
    out << *(int *) nodoDatos << endl;
}
