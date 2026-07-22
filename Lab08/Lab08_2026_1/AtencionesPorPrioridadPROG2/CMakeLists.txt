cmake_minimum_required(VERSION 4.2)
project(AtencionesPorPrioridadPROG2)

set(CMAKE_CXX_STANDARD 20)

add_executable(AtencionesPorPrioridadPROG2 main.cpp
        Clases/Par.cpp
        Clases/Par.h
        Clases/Atencion.cpp
        Clases/Atencion.h
        utils/Utils.cpp
        utils/Utils.h
        Clases/NodoListaDoble.cpp
        Clases/NodoListaDoble.h
        Clases/ListaDoble.cpp
        Clases/ListaDoble.h
        Clases/GestorAtenciones.cpp
        Clases/GestorAtenciones.h
        Clases/Emergencia.cpp
        Clases/Emergencia.h
        Clases/Urgencia.cpp
        Clases/Urgencia.h
        Clases/NoUrgencia.cpp
        Clases/NoUrgencia.h)
