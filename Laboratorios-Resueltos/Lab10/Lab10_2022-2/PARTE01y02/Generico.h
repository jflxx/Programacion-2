/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Generico.h
 * Author: Afedo
 *
 * Created on 9 de junio de 2024, 10:40
 */

#ifndef GENERICO_H
#define GENERICO_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Medicamento.h"

class Generico: public Medicamento{
public:
    Generico();
    virtual ~Generico();
    void lee(ifstream &arch);
    void setPais(char* p);
    void getPais(char* p) const;
    void imprime(ofstream &arch);
    void actualiza();
private:
    char *pais;
};

#endif /* GENERICO_H */

