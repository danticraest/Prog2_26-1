cmake_minimum_required(VERSION 4.2)
project(EmergenciasPROG2)

set(CMAKE_CXX_STANDARD 20)

add_executable(EmergenciasPROG2 main.cpp
        Clases/Atencion.cpp
        Clases/Atencion.h
        Clases/GestorAtenciones.cpp
        Clases/GestorAtenciones.h
        Clases/Emergencia.cpp
        Clases/Emergencia.h
        Clases/Urgencia.cpp
        Clases/Urgencia.h
        Clases/NoUrgencia.cpp
        Clases/NoUrgencia.h
        Utils/utils.cpp
        Utils/utils.h)
