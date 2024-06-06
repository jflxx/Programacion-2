/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Virtual.h
 * Author: Afedo
 *
 * Created on 26 de mayo de 2024, 19:41
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#include "Alumno.h"

class Virtual: public Alumno{
public:
    Virtual();
    Virtual(const Virtual& orig);
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(char* lic);
    char GetLicencia(char* lic) const;
    void leerDatos(ifstream &arch);
    void actualiza(double prec);
    void imprime(ofstream &arch);
private:
    char *licencia;
    double total;
};

#endif /* VIRTUAL_H */

