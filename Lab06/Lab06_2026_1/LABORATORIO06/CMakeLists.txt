cmake_minimum_required(VERSION 4.2)
project(LABORATORIO06)

set(CMAKE_CXX_STANDARD 20)

add_executable(LABORATORIO06 main.cpp
        Biblioteca/Mascota.cpp
        Biblioteca/Mascota.h
        Biblioteca/Cita.cpp
        Biblioteca/Cita.h
        Biblioteca/Control.cpp
        Biblioteca/Control.h
        Biblioteca/Operacion.cpp
        Biblioteca/Operacion.h
        Biblioteca/Vacuna.cpp
        Biblioteca/Vacuna.h
        Biblioteca/Veterinaria.cpp
        Biblioteca/Veterinaria.h)
