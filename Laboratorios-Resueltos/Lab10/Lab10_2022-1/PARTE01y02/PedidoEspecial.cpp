/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoEspecial.cpp
 * Author: Afedo
 * 
 * Created on 6 de junio de 2024, 22:54
 */

#include "PedidoEspecial.h"


void PedidoEspecial::lee(ifstream &arch){
    arch >> descuento;
    arch.get();
    Pedido::lee(arch);
}

void PedidoEspecial::imprime(ofstream &arch)const{
    Pedido::imprime(arch);
    arch << left << setw(15) << "Descuento" << right << setw(10) <<descuento << "%" << endl;
}

void PedidoEspecial::actualiza(){
    double tot  = GetTotal()*(1-descuento/100);
    SetTotal(tot);
}