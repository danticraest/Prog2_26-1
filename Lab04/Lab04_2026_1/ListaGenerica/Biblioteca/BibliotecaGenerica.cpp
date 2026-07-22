//
// Created by alulab14 on 8/05/2026.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "BibliotecaGenerica.h"

void verifyLec(ifstream &arch, const char *nombre) {
    arch.open(nombre, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombre << endl;
        exit(1);
    }
}

void verifyEsc(ofstream &arch, const char *nombre) {
    arch.open(nombre, ios::out);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombre << endl;
        exit(1);
    }
}

void procesaArreglo(void **arreglo1, void *(*leenum)(ifstream &), const char *nombreNum) {
    ifstream archNum;
    verifyLec(archNum, nombreNum);
    int i = 0;
    while (true) {
        void *elementos = leenum(archNum);
        if (archNum.eof()) break;
        arreglo1[i] = elementos;
        i++;
    }
    arreglo1[i] = nullptr;
}


void creaLista(void **arreglo1, void *&lista1, int (*comparanum)(const void *, const void *)) {
    void **Lista = (void **) lista1;
    int i = 0;
    while (true) {
        if (arreglo1[i] == nullptr) break;
        i++;
    }
    qsort(arreglo1, i, sizeof(void *), comparanum);
    generaLista(lista1);
    insertaLista(arreglo1, lista1);
}

void generaLista(void *&lista) {
    void **Lista = new void *[2];
    int *longitud = new int;
    *longitud = 0;
    Lista[0] = nullptr;
    Lista[1] = longitud;
    lista = Lista;
}

void insertaLista(void **arreglo1, void *&lista1) {
    void **Lista = (void **) lista1;
    int *i = new int;
    *i = 0;
    while (true) {
        void**datoLista=(void**) Lista[*i];
        if (arreglo1[*i] == nullptr) break;
        datoLista[0] = arreglo1;
        i++;
    }
    Lista[1] = i;
}

void fusionaListas(void *lista1, void *lista2, void (*verificanum)(void *)) {

}

void imprimeLista(void *lista1, void (*imprimenum)(void *, ofstream &),
                  const char *nombreRep) {
    ofstream outRep;
    verifyEsc(outRep, nombreRep);
    void **Lista = (void **) lista1;
    void *actual = Lista[0];

    while (actual != nullptr) {
        void **datos = (void **) actual;
        imprimenum(Lista[0], outRep);
        actual = datos[1];
    }
}
