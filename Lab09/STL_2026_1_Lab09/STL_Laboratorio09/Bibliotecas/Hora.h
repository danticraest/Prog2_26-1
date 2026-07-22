//
// Created by alulab14 on 26/06/2026.
//

#ifndef STL_LABORATORIO09_HORA_H
#define STL_LABORATORIO09_HORA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Hora {
public:
    Hora();

    ~Hora();
    //metodos de lectura e impresion

    void leer(ifstream &arch);

    void imprimir(ofstream &arch) const;

private:
    int hh;
    int mm;
    int ss;
    int segundos;
};

//operadores de lectura e impresion de Hora.h
void operator>>(ifstream &arch, class Hora &hor);

void operator<<(ofstream &arch, const class Hora &hor);

#endif //STL_LABORATORIO09_HORA_H
