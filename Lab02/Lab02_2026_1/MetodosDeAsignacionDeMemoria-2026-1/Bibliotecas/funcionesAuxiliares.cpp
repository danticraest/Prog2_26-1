//
// Created by alulab14 on 17/04/2026.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define INC 5
#define MAXL 200
using namespace std;

#include "funcionesAuxiliares.h"

void verifyLec(const char *nombre, ifstream &arch) {
    arch.open(nombre, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombre << endl;
        exit(1);
    }
}

void verifyEsc(const char *nombre, ofstream &arch) {
    arch.open(nombre, ios::out);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombre << endl;
        exit(1);
    }
}

void cargarInformacion(const char *nombreInfo,
                       int *&fechas, char ***&datosDeTexto,
                       int **&datosEnteros, double **&datosDePuntoFlotante) {
    ifstream archInfo;
    verifyLec(nombreInfo, archInfo);
    int capacidad = 0, numDatos = 0;
    fechas = nullptr;
    datosDeTexto = nullptr;
    datosEnteros = nullptr;
    datosDePuntoFlotante = nullptr;
    while (true) {
        if (capacidad == numDatos) {
            incrementarCapacidad(capacidad, numDatos,
                                 fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante);
        }
        leerInformacion(archInfo, fechas[numDatos - 1], datosDeTexto[numDatos - 1],
                        datosEnteros[numDatos - 1], datosDePuntoFlotante[numDatos - 1]);
        if (archInfo.eof()) break;
        numDatos++;
    }
}

void incrementarCapacidad(int &capacidad, int &numDatos,
                          int *&fechas, char ***&datosDeTexto,
                          int **&datosEnteros, double **&datosDePuntoFlotante) {
    capacidad += INC;
    if (fechas == nullptr) {
        fechas = new int[capacidad]{};
        datosDeTexto = new char **[capacidad]{};
        datosEnteros = new int *[capacidad]{};
        datosDePuntoFlotante = new double *[capacidad]{};
        numDatos++;
    } else {
        int *auxFecha = new int[capacidad]{};
        char ***auxDatTex = new char **[capacidad]{};
        int **auxDatEnt = new int *[capacidad]{};
        double **auxDatPunto = new double *[capacidad]{};
        for (int i = 0; i < numDatos; i++) {
            auxFecha[i] = fechas[i];
            auxDatTex[i] = datosDeTexto[i];
            auxDatEnt[i] = datosEnteros[i];
            auxDatPunto[i] = datosDePuntoFlotante[i];
        }
        deletearYreemplazar(fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante,
                            auxFecha, auxDatTex, auxDatEnt, auxDatPunto);
    }
}

void deletearYreemplazar(int *&fechas, char ***&datosDeTexto,
                         int **&datosEnteros, double **&datosDePuntoFlotante,
                         int *auxFecha, char ***auxDatTex, int **auxDatEnt, double **auxDatPunto) {
    delete fechas;
    delete datosDeTexto;
    delete datosEnteros;
    delete datosDePuntoFlotante;
    fechas = auxFecha;
    datosDeTexto = auxDatTex;
    datosEnteros = auxDatEnt;
    datosDePuntoFlotante = auxDatPunto;
}

void leerInformacion(ifstream &archInfo, int &fechas, char **&datosDeTexto,
                     int *&datosEnteros, double *&datosDePuntoFlotante) {
    char *aux, c;
    int dd, mm, aa, hhI, mmI, ssI, hhF, mmF, ssF;
    datosDeTexto = new char *[4]{};
    datosEnteros = new int [5]{};
    datosDePuntoFlotante = new double [2]{};
    archInfo >> dd;
    if (archInfo.eof()) return;
    archInfo >> c >> mm >> c >> aa >> c;
    fechas = aa * 10000 + mm * 100 + dd;
    aux = leerCadenaExacta(archInfo, ',');
    datosDeTexto[0] = aux;
    datosDeTexto[1] = leerCadenaExacta(archInfo, ',');
    archInfo >> hhI >> c >> mmI >> c >> ssI >> c;
    datosEnteros[0] = hhI * 3600 + mmI * 60 + ssI;
    archInfo >> datosDePuntoFlotante[0] >> c >> datosEnteros[2] >> c >> datosEnteros[3] >> c >>
            hhF >> c >> mmF >> c >> ssF >> c;
    datosEnteros[1] = hhF * 3600 + mmF * 60 + ssF;
    datosEnteros[4] = 0; //de acuerdo al enunciado
    datosDeTexto[2] = leerCadenaExacta(archInfo, '\n');
    datosDePuntoFlotante[1] = 0; //de acuerdo al enunciado
    datosDeTexto[3] = nullptr;
}

char *leerCadenaExacta(ifstream &arch, char lim) {
    char *aux, buffer[200]{};
    arch.getline(buffer, 200, lim);
    if (arch.eof()) return nullptr;
    asignarCadena(aux, buffer);
    return aux;
}

void asignarCadena(char *&destino, char *fuente) {
    destino = new char[strlen(fuente) + 1];
    strcpy(destino, fuente);
}

void completarInformacion(int *&fechas, char ***&datosDeTexto, int **&datosEnteros, double **&datosDePuntoFlotante) {
    double costo;
    cout << "Ingresar costo por hora:" << endl;
    cin >> costo;
    // cout<<datosDePuntoFlotante[0]<<endl;
    // double **aux = datosDePuntoFlotante;
    // datosDeTexto = new char **[4]{};
    // datosDeTexto[4]=datosEnteros[1]-datosEnteros[0];
}

void reporteDeAtenciones(const char *nombreRep, int *fechas, char ***datosDeTexto,
                         int **datosEnteros, double **datosDePuntoFlotante) {
    ofstream output;
    verifyEsc(nombreRep, output);
    titulares(output);
    for (int i = 0; datosDeTexto[i] != nullptr; i++) {
        linea(MAXL, '=', output);
        output << "FECHA: " << fechas[i] << endl;
        output << "REGISTRO DE ATENCIONES: " << endl;
        linea(MAXL, '-', output);
        subtitulos(output);
        for (int j = 0; datosDeTexto[j] != nullptr; j++) {
            char **datosDTaux = datosDeTexto[j];
            int *datosEaux = datosEnteros[j];
            double *datosPFaux = datosDePuntoFlotante[j];
            output<<left<<setw(15)<<datosDTaux[0]<<setw(15)<<datosDTaux[1]

            <<setw(15)<<datosEaux[0]<<setw(15)<<datosEaux[1]
            <<setw(15)<<"<"<<setw(33)<<"<"<<setw(15)<<datosPFaux[0]
            <<endl;
        }
    }
}

void titulares(ofstream &output) {
    output << setw(100) << "CLINICA DE URGENCIAS PORG2_SALUD" << endl;
    output << setw(97) << "REGISTRO DE LOS ATENCIONES" << endl;
}

void linea(int space, char type, ofstream &output) {
    for (int i = 0; i < space; i++) {
        output << type;
    }
    output << endl;
}

void subtitulos(ofstream &output) {
    output <<right<< setw(63) << "DURACION DE" << setw(20) << "COSTO DE LA" << endl;
    output << left << setw(15) << "ID" << setw(15) << "NOMBRE" <<
            setw(15) << "INGRESO" << setw(10) << "ALTA" <<
            setw(25) << "LA ATENCION" << setw(25) << "ATENCION" <<
            setw(15) << "TEMPERATURA" << setw(25) << "PRESION ARTERIAL" <<
            setw(15) << "ESPECIALIDAD"
            << endl;
}
