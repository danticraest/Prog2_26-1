//
// Created by alulab14 on 5/06/2026.
//

#ifndef LABORATORIO06_MASCOTA_H
#define LABORATORIO06_MASCOTA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Mascota {
public:
    int get_codigo() const;

    void set_codigo(int codigo);

    void get_nombre(char *nom) const;

    void set_nombre(const char *nom);

    char get_tipo() const;

    void set_tipo(char tipo);

    void get_raza(char *raz) const;

    void set_raza(const char *raz);

    //creacion constructor, destructor,constructor copia
    Mascota();

    Mascota(const class Mascota &mas);

    ~Mascota();

    void leerMascota(ifstream &arch);

private:
    int codigo;
    char *nombre;
    char tipo;
    char *raza;
};


#endif //LABORATORIO06_MASCOTA_H
