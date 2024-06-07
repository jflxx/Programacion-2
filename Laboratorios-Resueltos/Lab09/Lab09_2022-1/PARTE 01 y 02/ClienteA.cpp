/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClienteA.cpp
 * Author: Afedo
 * 
 * Created on 6 de junio de 2024, 12:37
 */

#include "ClienteA.h"


void ClienteA::lee(ifstream &arch){
    arch >> descuento;
    arch.get();
    Cliente::lee(arch);
}

void ClienteA::imprime(ofstream &arch){
     Cliente::imprimeDatos(arch);
     arch << left << setw(15) << "Descuento: " << descuento << "%   "
             << endl;
     Cliente::imprime(arch);
}

void ClienteA::calcula(double tot){
    tot = tot*(1-(descuento/100));
    Cliente::calcula(tot);
}