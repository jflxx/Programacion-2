/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClienteB.cpp
 * Author: Afedo
 * 
 * Created on 6 de junio de 2024, 12:39
 */

#include "ClienteB.h"

void ClienteB::lee(ifstream &arch){
    arch >> descuento;
    arch.get();
    arch >> flete;
    arch.get();
    Cliente::lee(arch);
}
void ClienteB::imprime(ofstream &arch){
     Cliente::imprimeDatos(arch);
     arch << left << setw(15) << "Descuento: " <<  descuento << "%   "
             << setw(10)<< "Flete:"<< flete << "% " << endl;
     Cliente::imprime(arch);
}

void ClienteB::calcula(double tot){
    tot = tot*(1-(descuento/100))+ tot*(flete/100);
    Cliente::calcula(tot);
}