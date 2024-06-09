/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Afedo
 *
 * Created on 9 de junio de 2024, 10:43
 */

#ifndef NODO_H
#define NODO_H

#include "Medicamento.h"
#include "Arbol.h"
class Nodo {
public:
    Nodo();
    friend class Arbol;
private:
    class Medicamento *med;
    class Nodo *izq;
    class Nodo *der;
};

#endif /* NODO_H */

