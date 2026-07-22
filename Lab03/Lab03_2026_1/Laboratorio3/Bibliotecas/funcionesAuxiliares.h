//
// Created by alulab14 on 24/04/2026.
//

#ifndef LABORATORIO3_FUNCIONESAUXILIARES_H
#define LABORATORIO3_FUNCIONESAUXILIARES_H

void verifyLec(const char* nombre, ifstream &arch) ;
void verifyEsc(const char* nombre, ofstream &arch);
void asignarCadena(char *&destino, char *origen);
void incrementarCapacidad(void **&padre, int &capacidad, int &numDatos);
void linea(char type, int space, ofstream &output);
void titulares(ofstream &output);

void cargarPacientes(const char*nombrePacientes,void*& pacientes);
void *leerPacientes(ifstream &archPacientes);
void reportePacientes(const char *repPacientes, void *pacientes);

void cargarVisitas(const char*nombreVisitas,void*& pacientes);
void *leerVisitas(int ano, int mes, int dia, int hh, double costoAtencion);

void generarReporte(const char*nombreRep, void*&pacientes);

#endif //LABORATORIO3_FUNCIONESAUXILIARES_H
