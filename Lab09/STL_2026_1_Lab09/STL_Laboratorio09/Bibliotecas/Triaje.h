//
// Created by alulab14 on 26/06/2026.
//

#ifndef STL_LABORATORIO09_TRIAJE_H
#define STL_LABORATORIO09_TRIAJE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Triaje {
public:
    string get_codigo_triaje() const;

    void set_codigo_triaje(const string &codigo_triaje);

    string get_codigo_paciente() const;

    void set_codigo_paciente(const string &codigo_paciente);

    int get_frecuencia_cardiaca() const;

    void set_frecuencia_cardiaca(int frecuencia_cardiaca);

    int get_presion_sistolica() const;

    void set_presion_sistolica(int presion_sistolica);

    int get_presion_diastolica() const;

    void set_presion_diastolica(int presion_diastolica);

    double get_temperatura() const;

    void set_temperatura(double temperatura);

    int get_saturacion_de_oxigeno() const;

    void set_saturacion_de_oxigeno(int saturacion_de_oxigeno);

    Triaje();

    ~Triaje();

    //metodos de lectura e impresion

    void leer(ifstream &arch);

    void imprimir(ofstream &arch) const;

private:
    string codigoTriaje;
    string codigoPaciente;
    int frecuenciaCardiaca;
    int presionSistolica;
    int presionDiastolica;
    double temperatura;
    int saturacionDeOxigeno;
};

//operadores de lectura e impresion de Triaje.h
void operator>>(ifstream &arch, class Triaje &tri);

void operator<<(ofstream &arch, const class Triaje &tri);


#endif //STL_LABORATORIO09_TRIAJE_H
