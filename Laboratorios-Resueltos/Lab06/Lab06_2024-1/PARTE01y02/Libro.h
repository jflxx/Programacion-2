/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Afedo
 *
 * Created on 8 de junio de 2024, 23:10
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Libro {
public:
    Libro();
    virtual ~Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(char* nomb);
    void GetNombre(char* nomb) const;
    void SetCodigo(char* cod);
    void GetCodigo(char* cod) const;
private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    bool colocado;
};

void operator >>(ifstream &arch,class Libro &libro);
void operator <<(ofstream &arch,class Libro &libro);

#endif /* LIBRO_H */

