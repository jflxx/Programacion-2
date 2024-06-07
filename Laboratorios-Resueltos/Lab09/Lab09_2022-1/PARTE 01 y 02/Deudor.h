/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Deudor.h
 * Author: Afedo
 *
 * Created on 6 de junio de 2024, 12:43
 */

#ifndef DEUDOR_H
#define DEUDOR_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include  "Cliente.h"
#include "ClienteA.h"
#include "ClienteB.h"
#include "ClienteC.h"
class Deudor {
public:
    Deudor();
    virtual ~Deudor();
    void asignarCate(char cat);
    void leerC(ifstream &arch);
    bool hayDato();
    void imprime(ofstream &arch);
    int devolverDni();
    void actualiza(double tot);
private:
    class Cliente *Cdeudor;
};

#endif /* DEUDOR_H */

