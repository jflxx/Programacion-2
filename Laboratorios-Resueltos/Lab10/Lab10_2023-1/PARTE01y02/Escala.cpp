/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Escala.cpp
 * Author: Afedo
 * 
 * Created on 8 de junio de 2024, 11:43
 */

#include "Escala.h"

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