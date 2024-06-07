/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Virtual.h
 * Author: Afedo
 *
 * Created on 5 de junio de 2024, 12:12
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Alumno.h"

class Virtual:public Alumno{
public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(char* lice);
    void GetLicencia(char* lice) const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualizatotal(double valorC);
private:
    char *licencia;
    double total;
};

#endif /* VIRTUAL_H */

