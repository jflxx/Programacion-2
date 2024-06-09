/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Afedo
 *
 * Created on 8 de junio de 2024, 23:17
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Estante.h"
#include "Libro.h"

class Biblioteca {
public:
    Biblioteca();
    void cargar_libros();
    void cargar_estantes();
    void posicionar_libros();
    void mostrar_datos();
private:
    void imprimirLibros(ofstream &arch);
    class Estante estantes[10];
    int cantidad_estantes;
    class Libro libros[20];
    int cantidad_libros;
};

#endif /* BIBLIOTECA_H */

