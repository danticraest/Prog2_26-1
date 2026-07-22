//
// Created by alulab14 on 12/06/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Urgencia.h"

void Urgencia::get_zona_lesion(char *zona) const {
    if (zona_lesion == nullptr)zona[0]=0;
    else strcpy(zona,zona_lesion);
}

void Urgencia::set_zona_lesion(const char *zona) {
    if (zona_lesion)delete zona_lesion;
    zona_lesion = new char[strlen(zona) + 1];
    strcpy(zona_lesion, zona);
}

bool Urgencia::is_necesita_rx() const {
    return necesita_rx;
}

void Urgencia::set_necesita_rx(bool necesita_rx) {
    this->necesita_rx = necesita_rx;
}

Urgencia::Urgencia() {
    zona_lesion = nullptr;
    necesita_rx = false;
}

Urgencia::Urgencia(const class Urgencia &urg) {
    zona_lesion = nullptr;
    necesita_rx = false;
    *this = urg;
}

Urgencia::~Urgencia() {
    delete zona_lesion;
}
