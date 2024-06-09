/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Afedo
 *
 * Created on 8 de junio de 2024, 11:40
 */

#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Boleta.h"
#include "Arbol.h"

class Nodo {
public:
    Nodo();
    friend class Arbol;
private:
    class Boleta dboleta;
    class Nodo *izq;
    class Nodo *der;
};

#endif /* NODO_H */

