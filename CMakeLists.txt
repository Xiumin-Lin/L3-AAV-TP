cmake_minimum_required(VERSION 3.20)
project(TP_AlgoAv C)

set(CMAKE_C_STANDARD 99)

add_executable(
        TP_AlgoAv
#        src/list/maListe.c src/list/liste.c src/list/liste.h
        src/tree/monArbre.c src/tree/arbre.c src/tree/arbre.h
        )
