/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */
/* 
 * File:   main.cpp
 * Author: Afedo JF
 *
 * Created on 5 de junio de 2024, 15:12
 */

#include "farmacia.h"



int main(int argc, char** argv) {
    farmacia Pedidos;
    
    Pedidos.leerecetas();
    Pedidos.descuenta();
    Pedidos.imprimirrecetas();
    return 0;
}

