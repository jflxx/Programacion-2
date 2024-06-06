/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Semipresencial.cpp
 * Author: Afedo
 * 
 * Created on 26 de mayo de 2024, 19:40
 */

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    total = 0;
}

Semipresencial::Semipresencial(const Semipresencial& orig) {
}

Semipresencial::~Semipresencial() {
}

void Semipresencial::leerDatos(ifstream &arch){
    double descuento;
    Alumno::leerDatos(arch);
    arch >> descuento;
    setDescuento(descuento);
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

void Semipresencial::actualiza(double prec){
    total = prec-prec*getDescuento()/100;
    Alumno::SetTotal(total);
}

void Semipresencial::imprime(ofstream &arch){
    Alumno::imprimir(arch);
    arch << right << setw(25) << GetTotal()<<endl;
}