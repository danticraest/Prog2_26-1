//
// Created by alulab14 on 17/04/2026.
//

#ifndef METODOSDEASIGNACIONDEMEMORIA_2026_1_FUNCIONESAUXILIARES_H
#define METODOSDEASIGNACIONDEMEMORIA_2026_1_FUNCIONESAUXILIARES_H

void verifyLec(const char *nombre, ifstream &arch);
void verifyEsc(const char *nombre, ofstream &arch) ;
void cargarInformacion(const char *nombreInfo,
                       int *&fechas, char ***&datosDeTexto, int**&datosEnteros, double**&datosDePuntoFlotante);
void incrementarCapacidad(int &capacidad, int &numDatos,
                          int *&fechas, char ***&datosDeTexto,
                          int **&datosEnteros, double **&datosDePuntoFlotante);
void deletearYreemplazar(int *&fechas, char ***&datosDeTexto,
                         int **&datosEnteros, double **&datosDePuntoFlotante,
                         int *auxFecha, char ***auxDatTex, int **auxDatEnt, double **auxDatPunto);
void leerInformacion(ifstream &archInfo, int &fechas, char **&datosDeTexto,
                     int *&datosEnteros, double *&datosDePuntoFlotante);
char *leerCadenaExacta(ifstream &arch, char lim);
void asignarCadena(char *&destino, char *fuente);


void completarInformacion(int *&fechas, char ***&datosDeTexto, int**&datosEnteros, double**&datosDePuntoFlotante);
void reporteDeAtenciones(const char *nombreRep, int *fechas, char ***datosDeTexto,
    int**datosEnteros, double**datosDePuntoFlotante);

void titulares(ofstream &output);
void linea(int space, char type, ofstream &output);
void subtitulos(ofstream &output);
#endif //METODOSDEASIGNACIONDEMEMORIA_2026_1_FUNCIONESAUXILIARES_H
