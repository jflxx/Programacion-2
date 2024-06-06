/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Escala.cpp
 * Author: Afedo
 * 
 * Created on 26 de mayo de 2024, 19:16
 */

#include "Escala.h"

Escala::Escala() {
    precio = 0;
    codigo = 0;
}
Escala::Escala(int cod,double prec){
    SetCodigo(cod);
    SetPrecio(prec);
}

Escala::Escala(const Escala& orig) {
}

Escala::~Escala() {
}

void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}

