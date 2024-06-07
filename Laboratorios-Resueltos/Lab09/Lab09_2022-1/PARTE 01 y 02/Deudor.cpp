/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Deudor.cpp
 * Author: Afedo
 * 
 * Created on 6 de junio de 2024, 12:43
 */

#include "Deudor.h"

Deudor::Deudor() {
    Cdeudor = nullptr;
}

Deudor::~Deudor() {
    if(Cdeudor != nullptr) delete Cdeudor;
}

void Deudor::leerC(ifstream &arch){
    arch.get();
    Cdeudor->lee(arch);
}

void Deudor::asignarCate(char cat){
    switch (cat){
        case 'A':
            Cdeudor = new class ClienteA;
            break;
        case 'B':
            Cdeudor = new class ClienteB;
            break;
        case 'C':
            Cdeudor = new class ClienteC;
            break;
    }
    Cdeudor->SetCategoria(cat);
}

bool Deudor::hayDato(){
    return Cdeudor!=nullptr? true:false;
}

void Deudor::imprime(ofstream &arch){
    Cdeudor->imprime(arch);
}


int Deudor::devolverDni(){
    return Cdeudor->GetDni();
}

void Deudor::actualiza(double tot){
    Cdeudor->calcula(tot);
}