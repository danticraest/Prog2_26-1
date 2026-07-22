#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Clases/GestorAtenciones.h"
#include "Utils/utils.h"

int main() {
GestorAtenciones gestor;
    gestor.procesar_dia("2026-06-11");
    gestor.generar_reporte_diario("reporte/20260611.txt");
    return 0;
}
