#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#include "Bibliotecas/SistemaDeAtencion.h"

int main() {
    class SistemaDeAtencion sistema;
    //CARGAR ARCHIVOS
    sistema.cargarPacientes("ArchivosDeDatos/Pacientes.csv");
    sistema.cargarMedicos("ArchivosDeDatos/Especialidades_Medicos.csv");
    sistema.cargarTriajes("ArchivosDeDatos/RegistrosDeTriajes.csv");
    // sistema.cargarAtenciones("ArchivosDeDatos/Atenciones.csv"); //sale con bucle, pero deberia llenar las atenciones correspondientes
    //LLENAR DATOS
    sistema.llenarAtenciones();
    sistema.llenarAtencionesDePacientes();
    sistema.llenarAtencionesDeMedicos();
    //GENERAR REPORTES
    sistema.reporteDeAtencionesPorPaciente("ArchivosDeReporte/reportePaciente.txt");
    sistema.reporteDeAtencionesPorMedico("ArchivosDeReporte/reporteMedicos.txt");
    return 0;
}
