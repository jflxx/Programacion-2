/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Virtual.h
 * Author: Afedo
 *
 * Created on 8 de junio de 2024, 11:35
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Alumno.h"
class Virtual:public Alumno {
public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(char* lice);
    void GetLicencia(char* lice) const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualizatotal(double CostCred);
private:
    char *licencia;
    double total;
};

#endif /* VIRTUAL_H */

