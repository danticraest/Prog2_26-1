#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Bibliotecas/funcionesAuxiliares.h"
int main() {
    void *pacientes;
    cargarPacientes("ArchivosDeDatos/pacientes.csv", pacientes);
    reportePacientes("ArchivosDeReporte/repPacientes.txt", pacientes);
    cargarVisitas("ArchivosDeDatos/visitas.csv", pacientes);
    generarReporte("ArchivosDeReporte/reporte.txt", pacientes);
    return 0;
}
