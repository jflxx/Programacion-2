/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClienteB.h
 * Author: Afedo
 *
 * Created on 6 de junio de 2024, 12:39
 */

#ifndef CLIENTEB_H
#define CLIENTEB_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Cliente.h"

class ClienteB:public Cliente{
public:
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void calcula(double tot);
private:
    double descuento;
    double flete;
};

#endif /* CLIENTEB_H */

