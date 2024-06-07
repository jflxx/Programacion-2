/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Semipresencial.cpp
 * Author: Afedo
 * 
 * Created on 5 de junio de 2024, 12:10
 */

#include "Semipresencial.h"

Semipresencial::Semipresencial(){
    total = 0;
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
} 

void Semipresencial::lee(ifstream &arch){
    Alumno::lee(arch);
    arch >> descuento;
    arch.get();
}

void Semipresencial::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch << setw(15) << ""
            << right << setw(7) << total << endl;
}

void Semipresencial::actualizatotal(double valorC){
    Alumno::actualizatotal(valorC);
    double totDes = Alumno::GetTotal()*(1-descuento/100);
    SetTotal(totDes);
    Alumno::SetTotal(totDes);
}
