/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Presencial.h
 * Author: Afedo
 *
 * Created on 5 de junio de 2024, 12:06
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Alumno.h"

class Presencial:public Alumno{
public:
    Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualizatotal(double valorC);
private:
    double recargo; //porcentaje de recargo sobre su boleta
    double total;
};

#endif /* PRESENCIAL_H */

