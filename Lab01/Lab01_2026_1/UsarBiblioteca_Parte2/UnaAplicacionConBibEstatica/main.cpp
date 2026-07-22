#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Bibliotecas/EstructuraHuellitas.h"
#include "Bibliotecas/sobreCargadores.h"

void cargarDatos(struct Mascota *arrMascota, struct Veterinario *arrVet, ifstream &archMascota,
     ifstream &archVet);

void registrarAtenciones(struct Atencion *arrAten, ifstream &archAten);
void     listaMascotasAEsterilizar(struct Mascota *arrMascotas,ofstream& output1);
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
    ofstream output1("ArchivosDeReporte/ListaMascotasAEsterilizar.txt", ios::out);
    if (!output1.is_open()) {
        cout << "No se pudo abrir archivo ListaMascotasAEsterilizar.txt" << endl;
        exit(1);
    }
    //pregunta a)
    cargarDatos(arrMascotas, arrVet, archMascota, archVet);
    //pregunta b)
    registrarAtenciones(arrAten, archAten);
    //pregunta c)
    listaMascotasAEsterilizar(arrMascotas, output1);

    // int fechaEjemplo = 20260408;
    // if (arrMascotas[0] <= fechaEjemplo)cout << "true";
    // else cout << "false";
    // cout << endl;
    return 0;
}


void cargarDatos(struct Mascota *arrMascota, struct Veterinario *arrVet, ifstream &archMascota,
     ifstream &archVet) {

    int i = 0;
    while (true) {
        archMascota >> arrMascota[i];
        if (archMascota.eof()) break;
        i++;
    }
    int j = 0;
    while (true) {
        archVet >> arrVet[j];
        if (archVet.eof()) break;
        j++;
    }
}

void registrarAtenciones(struct Atencion *arrAten,  ifstream &archAten) {
    int k = 0;
    while (true) {
        archAten >> arrAten[k];
        if (archAten.eof()) {
            arrAten[k].fecha = 0; //bandera
            break;
        }
        k++;
    }
    int m = 0;
    for (int j = 0; arrAten[j].fecha != 0; j++) {
        for (int i = 1; arrAten[i].fecha != 0; i++) {
            if (arrAten[i] == arrAten[j]) {
                m++;
                cout << "Horario ocupado del veterinario ID: " << arrAten[i].idVeterinario <<
                        " el " << arrAten[i].fecha << " a las " << arrAten[i].hora << ":" << arrAten[i].min << "." <<                        endl;
            }
        }
    }
    cout << endl;
    cout << m << " ATENCION(S) SIN PROGRAMAR" << endl;
}

void     listaMascotasAEsterilizar(struct Mascota *arrMascotas,ofstream& output1) {


}
