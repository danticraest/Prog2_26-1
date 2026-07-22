//
// Created by alulab14 on 8/05/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAENTEROS_H
#define LISTAGENERICA_BIBLIOTECAENTEROS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
void *leenum(ifstream &arch);
int comparanum(const void *a, const void *b);
void verificanum(void *elemento);
void imprimenum(void *nodoElementos, ofstream &out);
#endif //LISTAGENERICA_BIBLIOTECAENTEROS_H
