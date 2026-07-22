//
// Created by alulab14 on 10/04/2026.
//

#ifndef FUENTES_BIBLIOTECA_2026_1_SOBRECARGADORES_H
#define FUENTES_BIBLIOTECA_2026_1_SOBRECARGADORES_H
#include <fstream>
using namespace std;
void operator >>(ifstream &archMascota, struct Mascota &arrMascota);

void operator>>(ifstream &archVet, struct Veterinario &arrVet);

void operator>>(ifstream &archAten, struct Atencion &arrAten);

bool operator==(struct Atencion &aten1, struct Atencion &aten2);

bool operator<=(struct Mascota &arrMascotas, int hoy);

void operator<<(ofstream &output, struct Mascota arrMascot);

void operator<<(ofstream &output, struct Atencion arrAten);
#endif //FUENTES_BIBLIOTECA_2026_1_SOBRECARGADORES_H
