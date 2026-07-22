cmake_minimum_required(VERSION 4.2)
project(CLASES_OBJETOS_y_SOBRECARGAS)

set(CMAKE_CXX_STANDARD 20)

add_executable(CLASES_OBJETOS_y_SOBRECARGAS main.cpp
        Clases/Mascota.cpp
        Clases/Mascota.h
        Clases/VacunaAplicada.cpp
        Clases/VacunaAplicada.h
        Clases/Veterinaria.cpp
        Clases/Veterinaria.h)
