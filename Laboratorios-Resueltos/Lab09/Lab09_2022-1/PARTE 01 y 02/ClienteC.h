/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClienteC.h
 * Author: Afedo
 *
 * Created on 6 de junio de 2024, 12:40
 */

#ifndef CLIENTEC_H
#define CLIENTEC_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Cliente.h"

class ClienteC:public Cliente{
public:
   void lee(ifstream &arch);
   void imprime(ofstream &arch);
   void calcula(double tot);
private:
    double flete;
};

#endif /* CLIENTEC_H */

