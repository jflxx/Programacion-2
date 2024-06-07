/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   farmacia.h
 * Author: Afedo
 *
 * Created on 5 de junio de 2024, 15:37
 */

#ifndef FARMACIA_H
#define FARMACIA_H
#include "oferta.h"
class farmacia {
public:
    void leerecetas();
    void imprimirrecetas();
    void descuenta();
private:
    class oferta loferta[300];
};

#endif /* FARMACIA_H */

