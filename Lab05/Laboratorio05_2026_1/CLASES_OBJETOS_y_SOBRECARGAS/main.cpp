#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Clases/Veterinaria.h"
int main() {
    class Veterinaria vet;
    vet <= "ArchivosDeDatos/mascotas.csv";
     vet <<= "ArchivosDeDatos/vacunasAplicadas.csv";
    vet<<"ArchivosDeReporte/ReporteVeterinaria.txt";
    return 0;
}
