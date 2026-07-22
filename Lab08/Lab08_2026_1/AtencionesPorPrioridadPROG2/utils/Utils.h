//
// Created by alulab14 on 19/06/2026.
//

#ifndef ATENCIONESPORPRIORIDADPROG2_UTILS_H
#define ATENCIONESPORPRIORIDADPROG2_UTILS_H



#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;

class Utils {
public:
    static void apertura_archivo_lectura(ifstream &, string);

    static void apertura_archivo_escritura(ofstream &, string);

    static char *fecha_a_path(const char *);

    static char *int_a_char(int);

    static void construir_nombre_archivo(char *, const char *, int);

    static void construir_path_dia(char *, const char *);

};




#endif //ATENCIONESPORPRIORIDADPROG2_UTILS_H
