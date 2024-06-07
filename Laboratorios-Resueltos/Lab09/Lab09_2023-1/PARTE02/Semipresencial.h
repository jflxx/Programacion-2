/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Semipresencial.h
 * Author: Afedo
 *
 * Created on 5 de junio de 2024, 12:10
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Alumno.h"


class Semipresencial:public Alumno{
public:
    Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualizatotal(double valorC);
private:
    double descuento;
    double total;
};

#endif /* SEMIPRESENCIAL_H */

