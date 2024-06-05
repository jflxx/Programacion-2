/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   farmacia.h
 * Author: Afedo
 *
 * Created on 28 de mayo de 2024, 18:14
 */

#ifndef FARMACIA_H
#define FARMACIA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "conreceta.h"
#include "sinreceta.h"
#include "medico.h"

class farmacia {
public:
    farmacia();
    farmacia(const farmacia& orig);
    virtual ~farmacia();
    void carmamedico(const char *nombArch);
    void leerecetas(const char *nombArch);
    void imprimirrecetas(const char *nombArch);
    void buscarMedico(int codMed,char *espec);
    void imprimirLinea(ofstream &arch,int lim,char c);
private:
    class medico lmedico[50];
    class sinreceta lsinreceta[1000];
    class conreceta lconreceta[1000];
};

#endif /* FARMACIA_H */

