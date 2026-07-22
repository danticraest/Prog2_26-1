cmake_minimum_required(VERSION 4.0)
project(Prueba_Biblioteca_2026_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Prueba_Biblioteca_2026_1 main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")
target_link_libraries(Prueba_Biblioteca_2026_1 PRIVATE BiblioEst)