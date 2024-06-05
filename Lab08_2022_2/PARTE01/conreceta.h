/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   conreceta.h
 * Author: Afedo
 *
 * Created on 28 de mayo de 2024, 18:09
 */

#ifndef CONRECETA_H
#define CONRECETA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;
#include "medicamento.h"

class conreceta:public medicamento {
public:
    conreceta();
    conreceta(const conreceta& orig);
    virtual ~conreceta();
    void SetEspecialidad(char* especi);
    char GetEspecialidad(char* especi) const;
    void SetCodmed(int codmed);
    int GetCodmed() const;
    void colocar(int codMedico,int cant,int fecha,int medicam,char *esp);
    void imprimir(ofstream &arch);
private:
    int codmed;
    char *especialidad;
};

#endif /* CONRECETA_H */

