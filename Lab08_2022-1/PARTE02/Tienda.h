/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tienda.h
 * Author: Afedo
 *
 * Created on 30 de mayo de 2024, 18:23
 */

#ifndef TIENDA_H
#define TIENDA_H
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Pedido.h"
#include "Cliente.h"
#include "FuncionesApertura.h"

class Tienda {
public:
    Tienda();
    Tienda(const Tienda& orig);
    virtual ~Tienda();
    void carga();
    void muestra();
    void actualiza(int );
    char encontrarTipoCliente(int ID);
private:
    class Pedido lpedidos[200];
    class Cliente lclientes[30];
};

#endif /* TIENDA_H */

