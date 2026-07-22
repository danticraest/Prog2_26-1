#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Bibliotecas/funcionesAuxiliares.h"
int main() {
    int *fechas;
    char ***datosDeTexto;
    int **datosEnteros;
    double **datosDePuntoFlotante;
    //LA INFORMACION SE ESTA CARGANDO POR EL METODO DE INCREMENTOS (INC=5):
    cargarInformacion("ArchivosDeDatos/ER_Final_Dataset_For_Students_Programacion_2.csv",
                      fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante);
    completarInformacion(fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante);
    reporteDeAtenciones("ArchivosDeReporte/reporte.txt", fechas, datosDeTexto,
                        datosEnteros, datosDePuntoFlotante);
    return 0;
}
