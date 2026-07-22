#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Biblioteca/BibliotecaGenerica.h"
#include "Biblioteca/BibliotecaRegistros.h"
#include "Biblioteca/BibliotecaEnteros.h"
#define MAX 300

using namespace std;
int main() {
    void *arreglo1[MAX]{}, *arreglo2[MAX]{};
    void *lista1, *lista2;
    procesaArreglo(arreglo1, leenum, "ArchivosIngreso/numeros1.txt");
    creaLista(arreglo1, lista1, comparanum);

    procesaArreglo(arreglo2, leenum, "ArchivosIngreso/numeros2.txt");
    creaLista(arreglo2, lista2, comparanum);

    fusionaListas(lista1, lista2, verificanum);
    imprimeLista(lista1, imprimenum, "ArchivosSalida/Repnum.txt");

    procesaArreglo(arreglo1, leeregistro, "ArchivosIngreso/Atenciones1.txt");
    creaLista(arreglo1, lista1, comparareg);

    procesaArreglo(arreglo2, leeregistro, "ArchivosIngreso/Atenciones2.txt");
    creaLista(arreglo2, lista2, comparareg);

    fusionaListas(lista1, lista2, verificareg);
    imprimeLista(lista1, imprimeregistro, "ArchivosSalida/Repreg.txt");
    return 0;
}
