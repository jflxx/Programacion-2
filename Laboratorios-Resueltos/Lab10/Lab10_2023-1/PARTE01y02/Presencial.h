/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Presencial.h
 * Author: Afedo
 *
 * Created on 8 de junio de 2024, 11:32
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Alumno.h"
class Presencial: public Alumno{
public:
    Presencial();
    void lee(ifstream &arch);
    void setTotal(double total);
    double getTotal() const;
    void setRecargo(double recargo);
    double getRecargo() const;
    void imprime(ofstream &arch);
    void actualizatotal(double CostCred);
private:
    double recargo;
    double total; // monto recago total
};

#endif /* PRESENCIAL_H */

