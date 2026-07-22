//
// Created by alulab14 on 10/04/2026.
//

#ifndef FUENTES_BIBLIOTECA_2026_1_ESTRUCTURAHUELLITAS_H
#define FUENTES_BIBLIOTECA_2026_1_ESTRUCTURAHUELLITAS_H

struct Mascota {
    int idMascota;
    char nombre[20];
    char raza[20];
    char color[20];
    char tipo[20];
    int fechaNaci; //aaaammdd
};

struct Veterinario {
    int idVeterinario;
    char nombre[40];
    char especialidad[30];
};

struct Atencion {
    int idAtencion;
    int idMascota;
    int idVeterinario;
    int fecha;
    char tipoAtencion[30];
    int hora;
    int min;
    char estado[20];
};

struct SistemaHuellitas {
    struct Mascota mascot[200];
    struct Veterinario vet[200];
    struct Atencion aten[200];
    int numMascotas;
    int numVeterinarios;
    int numAtenciones;
};

#endif //FUENTES_BIBLIOTECA_2026_1_ESTRUCTURAHUELLITAS_H
