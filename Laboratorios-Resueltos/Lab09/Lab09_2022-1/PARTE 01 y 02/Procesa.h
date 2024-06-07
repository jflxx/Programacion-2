/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Procesa.h
 * Author: Afedo
 *
 * Created on 6 de junio de 2024, 12:45
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Pedido.h"
#include "Deudor.h"
class Procesa {
public:
    void carga();
    void actualiza();
    void muestra();
    int buscarIndiceCli(int cod);
    void imprimirLinea(ofstream &arch,int lim, char c);
private:
    class Pedido lpedidos[200];
    class Deudor ldeudor[30];
};

#endif /* PROCESA_H */

