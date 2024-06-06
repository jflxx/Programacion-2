/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Presencial.h
 * Author: Afedo
 *
 * Created on 26 de mayo de 2024, 19:19
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#include "Alumno.h"


class Presencial : public Alumno {
public:
    Presencial();
    Presencial(const Presencial& orig);
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void leerDatos(ifstream &arch);
    void actualiza(double prec);
    void imprime(ofstream &arch);
private:
    double recargo;
    double total;
};

#endif /* PRESENCIAL_H */

