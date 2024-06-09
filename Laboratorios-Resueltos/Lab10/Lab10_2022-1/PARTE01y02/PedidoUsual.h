/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PedidoUsual.h
 * Author: Afedo
 *
 * Created on 6 de junio de 2024, 22:55
 */

#ifndef PEDIDOUSUAL_H
#define PEDIDOUSUAL_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Pedido.h"

class PedidoUsual: public Pedido {
public:
    void lee(ifstream &arch);
    void imprime(ofstream &arch)const;
    void actualiza();
private:
    double descuento;
    double flete;
};

#endif /* PEDIDOUSUAL_H */

