#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Bibliotecas/EstructuraHuellitas.h"
#include "Bibliotecas/sobreCargadores.h"

int main() {
    struct Mascota arrMascotas[200]{};
    struct Veterinario arrVet[200]{};
    struct Atencion arrAten[200]{};
    ifstream archMascota("ArchivosDeDatos/Mascotas.csv", ios::in);
    if (!archMascota.is_open()) {
        cout << "No se pudo abrir archivo Mascotas.csv" << endl;
        exit(1);
    }

    ifstream archVet("ArchivosDeDatos/Veterinarios.csv", ios::in);
    if (!archVet.is_open()) {
        cout << "No se pudo abrir archivo Veterinarios.csv" << endl;
        exit(1);
    }
    ifstream archAten("ArchivosDeDatos/Atenciones.csv", ios::in);
    if (!archAten.is_open()) {
        cout << "No se pudo abrir archivo Atenciones.csv" << endl;
        exit(1);
    }
    ofstream outputMascot("ArchivosDeReporte/ReporteMascot.txt", ios::out);
    if (!outputMascot.is_open()) {
        cout << "No se pudo abrir archivo ReporteMascot.txt" << endl;
        exit(1);
    }
    ofstream outputAten("ArchivosDeReporte/ReporteAten.txt", ios::out);
    if (!outputAten.is_open()) {
        cout << "No se pudo abrir archivo ReporteAten.txt.txt" << endl;
        exit(1);
    }

    //LECTURA
    int i = 0;
    while (true) {
        archMascota >> arrMascotas[i];
        if (archMascota.eof()) {
            break;
        }
        i++;
    }

    int j = 0;
    while (true) {
        archVet >> arrVet[j];
        if (archVet.eof()) {
            break;
        }
        j++;
    }

    int k = 0;
    while (true) {
        archAten >> arrAten[k];
        if (archAten.eof()) {
            break;
        }
        k++;
    }
    //OPERACIONES
    //son iguales si es a la misma hora y misma fecha (regla #2)
    if (arrAten[0] == arrAten[1])cout << "true";
    else cout << "false";
    cout << endl;

    int fechaEjemplo = 20241010; //estoy usando la fecha de la primera mascota de Mascotas.csv
    //y lo compararé con la fecha de la primera mascota (REGLA #1)
    if (arrMascotas[0] <= fechaEjemplo)cout << "true";
    else cout << "false";
    cout << endl;

    //IMPRESION
    outputMascot << arrMascotas[0];
    outputAten << arrAten[0];
    return 0;
}
