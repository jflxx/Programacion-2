/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Semipresencial.h
 * Author: Afedo
 *
 * Created on 26 de mayo de 2024, 19:40
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#include "Alumno.h"

class Semipresencial:public Alumno {
public:
    Semipresencial();
    Semipresencial(const Semipresencial& orig);
    virtual ~Semipresencial();
    void leerDatos(ifstream &arch);
    void setTotal(double total);
    double getTotal() const;
    void setDescuento(double descuento);
    double getDescuento() const;
    void actualiza(double prec);
    void imprime(ofstream &arch);
private:
    double descuento;
    double total;
};

#endif /* SEMIPRESENCIAL_H */

