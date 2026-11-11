cmake_minimum_required(VERSION 4.4)
project(ABB_Despachador)

set(CMAKE_CXX_STANDARD 20)

add_executable(ABB_Despachador main.cpp
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp)
