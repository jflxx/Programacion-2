/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoUsual.cpp
 * Author: Afedo
 * 
 * Created on 6 de junio de 2024, 22:55
 */

#include "PedidoUsual.h"

void PedidoUsual::lee(ifstream &arch){
    arch >> descuento;
    arch.get();
    arch >> flete;
    arch.get();
    Pedido::lee(arch);
}

void PedidoUsual::imprime(ofstream &arch)const{
    Pedido::imprime(arch);
    arch << left << setw(15) << "Descuento: " << right << setw(10) << descuento <<  "%" << endl;
    arch << left << setw(15) << "Flete: " << right << setw(10) << flete << "%" << endl;
}

void PedidoUsual::actualiza(){
    double tot  = GetTotal() + GetTotal()*(flete/100) - GetTotal()*(descuento/100);
    SetTotal(tot);
}