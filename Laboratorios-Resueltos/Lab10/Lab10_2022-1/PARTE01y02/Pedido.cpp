/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Afedo
 * 
 * Created on 6 de junio de 2024, 22:50
 */

#include "Pedido.h"

Pedido::Pedido() {
    nombre = nullptr;
}
Pedido::~Pedido() {
    if(nombre!=nullptr) delete []nombre;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetNombre(char* nomb) {
    if(nombre!=nullptr) delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Pedido::GetNombre(char* nomb) const{
    if(nombre!=nullptr) strcpy(nomb,nombre);
    else nomb[0] = 0;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::lee(ifstream &arch){
    char nomb[60],c;
    int d,m,a;
    arch.getline(nomb,60,',');
    SetNombre(nomb);
    arch >> cantidad >> c >> total >> c >> dni >> c
            >> d >> c >> m >> c >> a;
    SetFecha(a*10000 + m*100 + d);
}

void Pedido::imprime(ofstream &arch) const{
    char nomb[60];
    GetNombre(nomb);
    arch << right << setfill('0')<< setw(2) <<fecha%100<< "/"
            << setw(2) << (fecha%10000)/100 << '/' << setfill(' ') 
            << fecha/10000 << endl;
    arch << left << setw(10) << codigo
            << nomb << endl;
    arch << left << setw(15) << "DNI:" << right << setw(10) <<dni << endl;
    arch << left << setw(15) << "Monto Total:" << right << setw(10) << total << endl;
}

void operator <<(ofstream &arch,const class Pedido *ped){
    ped->imprime(arch);
}
