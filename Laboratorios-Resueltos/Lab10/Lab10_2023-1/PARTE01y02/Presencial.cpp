/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Presencial.cpp
 * Author: Afedo
 * 
 * Created on 8 de junio de 2024, 11:32
 */

#include "Presencial.h"

Presencial::Presencial(){
    total = 0;
}

void Presencial::lee(ifstream &arch){
    Alumno::lee(arch);
    arch >> recargo;
    arch.get();
}

void Presencial::setTotal(double total) {
    this->total = total;
}

double Presencial::getTotal() const {
    return total;
}

void Presencial::setRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::getRecargo() const {
    return recargo;
}

void Presencial::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch << setw(10) << ""
            << right << setw(10) << total<<endl;
}

void Presencial::actualizatotal(double CostCred){
    Alumno::actualizatotal(CostCred);
    double tot = Alumno::GetTotal();
    total = tot*(1+recargo/100);
    Alumno::SetTotal(total);
}