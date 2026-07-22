#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Clases/GestorAtenciones.h"

int main() {
    GestorAtenciones gestor;
    cout<<"Comienza la Carga de Atenciones por Prioridad"<<endl;
    //reporte de una fecha en especifica:
    gestor.cargar_atenciones_prioridad("1992/01/23");
    cout<<"Termina la Carga de Atenciones por Prioridad"<<endl;
    gestor.imprimir_atenciones_prioridad("ArchivosDeReporte/reporte.txt");
    cout<<"Termina la Impresion de Atenciones por Prioridad"<<endl;
    return 0;
}
