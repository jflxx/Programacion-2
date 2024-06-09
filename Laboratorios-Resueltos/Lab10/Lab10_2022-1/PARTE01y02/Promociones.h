/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Promociones.h
 * Author: Afedo
 *
 * Created on 6 de junio de 2024, 23:08
 */

#ifndef PROMOCIONES_H
#define PROMOCIONES_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Lista.h"
#include "Pedido.h"
#include "PedidoEspecial.h"
#include "PedidoEventual.h"
#include "PedidoUsual.h"

class Promociones {
public:
    void leepedidos();
    void imprimepedidos();
    void actualizapedidos();
private:
    Pedido *leePedido(ifstream &arch);
    class Lista Lpedidos;
};

#endif /* PROMOCIONES_H */

