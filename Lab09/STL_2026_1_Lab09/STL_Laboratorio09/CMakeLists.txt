cmake_minimum_required(VERSION 4.2)
project(STL_Laboratorio09)

set(CMAKE_CXX_STANDARD 20)

add_executable(STL_Laboratorio09 main.cpp
        Bibliotecas/Triaje.cpp
        Bibliotecas/Triaje.h
        Bibliotecas/Hora.cpp
        Bibliotecas/Hora.h
        Bibliotecas/Atencion.cpp
        Bibliotecas/Atencion.h
        Bibliotecas/Paciente.cpp
        Bibliotecas/Paciente.h
        Bibliotecas/Medico.cpp
        Bibliotecas/Medico.h
        Bibliotecas/SistemaDeAtencion.cpp
        Bibliotecas/SistemaDeAtencion.h)
