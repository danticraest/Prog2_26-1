//
// Created by alulab14 on 19/06/2026.
//

#ifndef ATENCIONESPORPRIORIDADPROG2_NODOLISTADOBLE_H
#define ATENCIONESPORPRIORIDADPROG2_NODOLISTADOBLE_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Par.h"
#include "ListaDoble.h"

class NodoListaDoble {
public:
    class Par get_dato() const;

    void set_dato(const class Par &dato);

    class NodoListaDoble *get_anterior() const;

    void set_anterior(class NodoListaDoble *anterior);

    class NodoListaDoble *get_siguiente() const;

    void set_siguiente(class NodoListaDoble *siguiente);

    NodoListaDoble();

    NodoListaDoble(const class NodoListaDoble &nod);

    void operator=(const class NodoListaDoble &nod);

    ~NodoListaDoble();

private:
    class Par dato;
    class NodoListaDoble *anterior;
    class NodoListaDoble *siguiente;

    friend class ListaDoble;
};


#endif //ATENCIONESPORPRIORIDADPROG2_NODOLISTADOBLE_H
