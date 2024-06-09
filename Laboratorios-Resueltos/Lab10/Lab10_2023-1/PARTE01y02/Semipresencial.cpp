/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Semipresencial.cpp
 * Author: Afedo
 * 
 * Created on 8 de junio de 2024, 11:34
 */

#include "Semipresencial.h"
Semipresencial::Semipresencial(){
    total = 0;
}

void Semipresencial::lee(ifstream &arch){
    Alumno::lee(arch);
    arch >> descuento;
    arch.get();
}

void Semipresencial::setTotal(double total) {
    this->total = total;
}

double Semipresencial::getTotal() const {
    return total;
}

void Semipresencial::setDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::getDescuento() const {
    return descuento;
}

void Semipresencial::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch << setw(10) << ""
            << right << setw(10) << total <<endl;
}

void Semipresencial::actualizatotal(double CostCred){
    Alumno::actualizatotal(CostCred);
    double tot = Alumno::GetTotal();
    total = tot*(1-descuento/100);
    Alumno::SetTotal(total);
}