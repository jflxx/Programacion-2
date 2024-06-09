/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Semipresencial.h
 * Author: Afedo
 *
 * Created on 8 de junio de 2024, 11:34
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Alumno.h"


class Semipresencial:public Alumno {
public:
    Semipresencial();
    void lee(ifstream &arch);
    void setTotal(double total);
    double getTotal() const;
    void setDescuento(double descuento);
    double getDescuento() const;
    void imprime(ofstream &arch);
    void actualizatotal(double CostCred);
private:
    double descuento;
    double total;
};

#endif /* SEMIPRESENCIAL_H */

