/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClienteA.h
 * Author: Afedo
 *
 * Created on 6 de junio de 2024, 12:37
 */

#ifndef CLIENTEA_H
#define CLIENTEA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Cliente.h"

class ClienteA:public Cliente{
public:
    void lee(ifstream &arch);
     void imprime(ofstream &arch);
     void calcula(double tot);
private:
    double descuento;
};

#endif /* CLIENTEA_H */

