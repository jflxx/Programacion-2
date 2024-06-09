/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Marca.h
 * Author: Afedo
 *
 * Created on 9 de junio de 2024, 10:41
 */

#ifndef MARCA_H
#define MARCA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Medicamento.h"


class Marca:public Medicamento{
public:
    Marca();
    virtual ~Marca();
    void lee(ifstream &arch);
    void setLaboratorio(char* lab);
    void getLaboratorio(char* lab) const;
    void imprime(ofstream &arch);
    void actualiza();
private:
    int lote;
    char *laboratorio;
};

#endif /* MARCA_H */

