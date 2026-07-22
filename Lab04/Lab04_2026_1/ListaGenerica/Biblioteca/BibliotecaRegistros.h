//
// Created by alulab14 on 8/05/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAREGISTROS_H
#define LISTAGENERICA_BIBLIOTECAREGISTROS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
void *leeregistro(ifstream &arch);
void asignarCadena(char *&destino, char *origen);
int comparareg(const void *a, const void *b);
void verificareg(void *elemento);
void imprimeregistro(void *nodoElementos, ofstream &out);
#endif //LISTAGENERICA_BIBLIOTECAREGISTROS_H
