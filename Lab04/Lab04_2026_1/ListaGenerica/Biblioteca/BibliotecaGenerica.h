//
// Created by alulab14 on 8/05/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAGENERICA_H
#define LISTAGENERICA_BIBLIOTECAGENERICA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
void verifyLec(ifstream &arch, const char *nombre);

void verifyEsc(ofstream &arch, const char *nombre);

void procesaArreglo(void **arreglo1, void *(*leenum)(ifstream &), const char *nombreNum);

void creaLista(void **arreglo1, void *&lista1, int (*comparanum)(const void *, const void *));

void generaLista(void *&lista);

void insertaLista(void**arreglo1,void *&lista1);

void fusionaListas(void *lista1, void *lista2, void (*verificanum)(void *));

void imprimeLista(void *lista1, void (*imprimenum)(void *, ofstream &),
                  const char *nombreRep);
#endif //LISTAGENERICA_BIBLIOTECAGENERICA_H
