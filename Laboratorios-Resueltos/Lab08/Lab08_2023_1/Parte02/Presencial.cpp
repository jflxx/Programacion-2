/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Presencial.cpp
 * Author: Afedo
 * 
 * Created on 26 de mayo de 2024, 19:19
 */

#include "Presencial.h"

Presencial::Presencial() {
    total = 0;
    recargo = 0;
}

Presencial::Presencial(const Presencial& orig) {
}

Presencial::~Presencial() {
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

void Presencial::leerDatos(ifstream &arch){
    double recargo;
    Alumno::leerDatos(arch);
    arch >> recargo;
    SetRecargo(recargo);
}

void Presencial::actualiza(double prec){
    total = prec*GetRecargo()/100+prec;
    Alumno::SetTotal(total);
}

void Presencial::imprime(ofstream &arch){
    Alumno::imprimir(arch);
    arch << right << setw(25) << GetTotal()<<endl;
}


