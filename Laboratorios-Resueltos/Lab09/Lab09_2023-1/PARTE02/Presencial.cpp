/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Presencial.cpp
 * Author: Afedo
 * 
 * Created on 5 de junio de 2024, 12:06
 */

#include "Presencial.h"

Presencial::Presencial() {
    total = 0;
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


void Presencial::lee(ifstream &arch){
    Alumno::lee(arch);
    arch >> recargo;
    arch.get();
}

void Presencial::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch << setw(15) << ""
            << right << setw(7) << total << endl;
}

void Presencial::actualizatotal(double valorC){
    Alumno::actualizatotal(valorC);
    double totDes = Alumno::GetTotal()*(1+recargo/100);
    SetTotal(totDes);
    Alumno::SetTotal(totDes);
}



