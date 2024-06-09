/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoEventual.cpp
 * Author: Afedo
 * 
 * Created on 6 de junio de 2024, 22:56
 */

#include "PedidoEventual.h"


void PedidoEventual::lee(ifstream &arch){
    arch >> flete;
    arch.get();
    Pedido::lee(arch);
}

void PedidoEventual::imprime(ofstream &arch)const{
    Pedido::imprime(arch);
    arch << left << setw(15) << "Flete: " << right << setw(10) << flete << "%" << endl;
}

void PedidoEventual::actualiza(){
    double tot  = GetTotal()*(1+flete/100);
    SetTotal(tot);
}