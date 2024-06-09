/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Espacio.h
 * Author: Afedo
 *
 * Created on 8 de junio de 2024, 23:12
 */

#ifndef ESPACIO_H
#define ESPACIO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Espacio {
public:
    Espacio();
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetContenido(char contenido);
    char GetContenido() const;
private:
    char contenido;
    int posx;
    int posy;
};

void operator <<(ofstream &arch,class Espacio &espacio);

#endif /* ESPACIO_H */

