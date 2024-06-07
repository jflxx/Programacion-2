/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClienteC.cpp
 * Author: Afedo
 * 
 * Created on 6 de junio de 2024, 12:40
 */

#include "ClienteC.h"

void ClienteC::lee(ifstream &arch){
    arch >> flete;
    arch.get();
    Cliente::lee(arch);
}

void ClienteC::imprime(ofstream &arch){
     Cliente::imprimeDatos(arch);
     arch << left << setw(10)<< "Flete:"<< flete << "% " << endl;
     Cliente::imprime(arch);
}

void ClienteC::calcula(double tot){
    tot = tot*(1+(flete/100));
    Cliente::calcula(tot);
}