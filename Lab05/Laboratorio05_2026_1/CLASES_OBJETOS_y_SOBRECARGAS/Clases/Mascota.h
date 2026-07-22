//
// Created by alulab14 on 15/05/2026.
//

#ifndef CLASES_OBJETOS_Y_SOBRECARGAS_MASCOTA_H
#define CLASES_OBJETOS_Y_SOBRECARGAS_MASCOTA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "VacunaAplicada.h"

class Mascota {
public:
    int get_dni() const;

    void set_dni(int dni);

    void get_nombre(char *nom) const;

    void set_nombre(const char *nom);

    void get_especie(char *espe) const;

    void set_especie(const char *espe);

    int get_edad() const;

    void set_edad(int edad);

    double get_peso() const;

    void set_peso(double peso);

    void get_colegiatura(char *cole) const;

    void set_colegiatura(const char *cole);

    int get_num_vacunas() const;

    void set_num_vacunas(int num_vacunas);

    Mascota();

    Mascota(const class Mascota &masc);

    void operator=(const class Mascota &masc);

    ~Mascota();

private:
    int dni;
    char *nombre;
    char *especie;
    int edad;
    double peso;
    char *colegiatura;
    class VacunaAplicada listaVacunas[20];
    int numVacunas;
};

void operator>>(ifstream &arch, class Mascota &masc);
void operator<<(ofstream &rep, class Mascota &masc);


#endif //CLASES_OBJETOS_Y_SOBRECARGAS_MASCOTA_H
