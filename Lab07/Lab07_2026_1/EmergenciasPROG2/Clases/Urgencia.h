//
// Created by alulab14 on 12/06/2026.
//

#ifndef EMERGENCIASPROG2_URGENCIA_H
#define EMERGENCIASPROG2_URGENCIA_H


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Urgencia {
public:
    void get_zona_lesion(char *zona) const;

    void set_zona_lesion(const char *zona);

    bool is_necesita_rx() const;

    void set_necesita_rx(bool necesita_rx);

    Urgencia();
    Urgencia(const class Urgencia& urg);

    ~Urgencia();

private:
    char *zona_lesion;
    bool necesita_rx;
};


#endif //EMERGENCIASPROG2_URGENCIA_H
