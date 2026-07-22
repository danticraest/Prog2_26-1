//
// Created by alulab14 on 15/05/2026.
//

#ifndef CLASES_OBJETOS_Y_SOBRECARGAS_VETERINARIA_H
#define CLASES_OBJETOS_Y_SOBRECARGAS_VETERINARIA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Mascota.h"

class Veterinaria {
public:
    Veterinaria();

    ~Veterinaria();

    void operator<=(const char *nombreMascotas);

    // int operator+=(int mascota, class VacunaAplicada &vac);

    void operator<<=(const char *nombreVacunas);

    void operator<<(const char* reporteFinal);

    int buscarNombreMascota(char *nombreMascota, class Mascota &masc);

private:
    class Mascota *listaDeMascotas;
    int numMascotas;
};


#endif //CLASES_OBJETOS_Y_SOBRECARGAS_VETERINARIA_H
