/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   sinreceta.h
 * Author: Afedo
 *
 * Created on 28 de mayo de 2024, 18:12
 */

#ifndef SINRECETA_H
#define SINRECETA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;
#include "medicamento.h"


class sinreceta:public medicamento{
public:
    sinreceta();
    sinreceta(const sinreceta& orig);
    virtual ~sinreceta();
    void SetNombre(char* nomb);
    char GetNombre(char* nomb) const;
    void SetDni(int dni);
    int GetDni() const;
    void colocar(int DNI,int cant,int fecha,int medicam,char *nombP);
    void imprimir(ofstream &arch);
private:
    int dni;
    char *nombre;
};

#endif /* SINRECETA_H */

