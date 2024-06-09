/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Medicamento.cpp
 * Author: Afedo
 * 
 * Created on 9 de junio de 2024, 10:39
 */

#include "Medicamento.h"

Medicamento::Medicamento() {
    nombre = nullptr;
}

void Medicamento::setPrecio(double precio) {
    this->precio = precio;
}

double Medicamento::getPrecio() const {
    return precio;
}
Medicamento::~Medicamento() {
    if(nombre!=nullptr) delete []nombre;
}

void Medicamento::lee(ifstream &arch){
    char nomb[60],c;
    arch >> codigo >> c;
    arch.getline(nomb,60,',');
    arch >> stock >> c >> precio >> c;
    setNombre(nomb);
}

void Medicamento::setNombre(char* nomb) {
    if(nombre!=nullptr) delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Medicamento::getNombre(char* nomb) const {
    if(nombre!=nullptr) strcpy(nomb,nombre);
    else nomb[0]=0;
}

void Medicamento::setCodigo(int codigo) {
    this->codigo = codigo;
}

int Medicamento::getCodigo() const {
    return codigo;
}

void Medicamento::imprime(ofstream &arch){
    char nomb[60];
    getNombre(nomb);
    arch << left 
            << setw(10) << codigo
            << setw(60) << nomb
            << setw(10) << stock
            << right << setw(6) << precio
            << left << "   ";
}