//
// Created by alulab14 on 19/06/2026.
//

#ifndef ATENCIONESPORPRIORIDADPROG2_PAR_H
#define ATENCIONESPORPRIORIDADPROG2_PAR_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Atencion.h"

class Par {
public:
    int get_llave() const;

    void set_llave(int llave);

    class Atencion *get_valor() const;

    void set_valor(class Atencion *valor);

    Par();

    Par(const class Par &pa);
    void operator=(const class Par &pa);

    ~Par();

private:
    int llave;
    class Atencion *valor;
};


#endif //ATENCIONESPORPRIORIDADPROG2_PAR_H
