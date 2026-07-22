cmake_minimum_required(VERSION 4.0)
project(Fuentes_Biblioteca_2026_1)

set(CMAKE_CXX_STANDARD 20)
add_library(BiblioEst STATIC Bibliotecas/sobreCargadores.cpp)
add_executable(Fuentes_Biblioteca_2026_1 main.cpp)
target_link_libraries(Fuentes_Biblioteca_2026_1 BiblioEst)
