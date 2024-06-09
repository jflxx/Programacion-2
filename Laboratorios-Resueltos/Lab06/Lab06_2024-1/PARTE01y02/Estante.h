/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Estante.h
 * Author: Afedo
 *
 * Created on 8 de junio de 2024, 23:13
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Espacio.h"
#include "Libro.h"

class Estante {
public:
    Estante();
    virtual ~Estante();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(char* cod);
    void GetCodigo(char* cod) const;
    bool operator +=(class Libro &libro);
    bool hayEspacio(class Libro &libro);
    void actualizarEspacios(class Libro &libro);
    void imprimeLinea(ofstream &arch,int lim,char c);
    void imprimirEstante(ofstream &arch);
    void imprimirLibros(ofstream &arch);
private:
    char *codigo;
    int anchura;
    int altura;
    class Libro libros[10];
    class Espacio espacios[100];
    int cantidad_libros;
};
void operator >>(ifstream &arch,class Estante &estante);
void operator <<(ofstream &arch,class Estante &estante);

#endif /* ESTANTE_H */

