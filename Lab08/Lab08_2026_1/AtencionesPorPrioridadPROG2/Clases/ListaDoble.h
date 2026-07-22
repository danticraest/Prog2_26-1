//
// Created by alulab14 on 19/06/2026.
//

#ifndef ATENCIONESPORPRIORIDADPROG2_LISTADOBLE_H
#define ATENCIONESPORPRIORIDADPROG2_LISTADOBLE_H
#include "GestorAtenciones.h"
#include "NodoListaDoble.h"


class ListaDoble {
public:
    class NodoListaDoble *get_cabeza() const;

    void set_cabeza(class NodoListaDoble *cabeza);

    //constructor, destructor,constructor copia
    ListaDoble();

    ListaDoble(const class ListaDoble &lis);

    ~ListaDoble();

    //metodos de lista
    void insertar(class GestorAtenciones *p,int  llave);

    void imprimir(class GestorAtenciones *p);

    void destruir();

private:
    class NodoListaDoble *cabeza;
};


#endif //ATENCIONESPORPRIORIDADPROG2_LISTADOBLE_H
