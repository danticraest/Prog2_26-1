//
// Created by alulab14 on 15/05/2026.
//

#ifndef CLASES_OBJETOS_Y_SOBRECARGAS_VACUNAAPLICADA_H
#define CLASES_OBJETOS_Y_SOBRECARGAS_VACUNAAPLICADA_H


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class VacunaAplicada {
public:
    void get_nombre(char *nom) const;

    void set_nombre(const char *nom);

    int get_fecha() const;

    void set_fecha(int fecha);

    double get_dosis() const;

    void set_dosis(double dosis);

    void get_colegiatura(char *cole) const;

    void set_colegiatura(const char *cole);

    VacunaAplicada();

    VacunaAplicada(const class VacunaAplicada &vac);

    void operator=(const class VacunaAplicada &vac);

    ~VacunaAplicada();

private:
    char *nombre;
    int fecha;
    double dosis;
    char *colegiatura;
};

void operator>>(ifstream &arch,class VacunaAplicada &vac);
void operator<<(ofstream &rep,class VacunaAplicada &vac);


#endif //CLASES_OBJETOS_Y_SOBRECARGAS_VACUNAAPLICADA_H
