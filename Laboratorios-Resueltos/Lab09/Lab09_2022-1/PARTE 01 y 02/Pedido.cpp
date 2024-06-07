/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Afedo
 * 
 * Created on 6 de junio de 2024, 12:41
 */

#include "Pedido.h"

Pedido::Pedido() {
    total = 0;
    codigo=0;
}


void Pedido::setTotal(double total) {
    this->total = total;
}

double Pedido::getTotal() const {
    return total;
}

void Pedido::setFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::getFecha() const {
    return fecha;
}

void Pedido::setDni(int dni) {
    this->dni = dni;
}

int Pedido::getDni() const {
    return dni;
}

void Pedido::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::getCantidad() const {
    return cantidad;
}

void Pedido::setCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::getCodigo() const {
    return codigo;
}


void Pedido::leerPed(ifstream &arch,int cod){
    int cant, DocIden,d,m,a;
    char c;
    double tot;
    
    arch.get();
    arch >> cant >> c >> tot >> c >> DocIden >> c
            >> d >> c >> m >> c >> a;
    colocarDatos(cod,cant,DocIden,a*10000+m*100+d,tot);
}

void Pedido::colocarDatos(int cod,int cant,int DocIden,int fech,double tot){
    setCodigo(cod);
    setCantidad(cant);
    setDni(DocIden);
    setTotal(tot);
    setFecha(fech);
}
bool Pedido::hayDato(){
    return codigo!=0? true:false;
}
