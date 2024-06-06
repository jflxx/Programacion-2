/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Afedo
 * 
 * Created on 30 de mayo de 2024, 18:05
 */

#include "Pedido.h"

Pedido::Pedido() {
    obs = nullptr;
    total = 0;
}
Pedido::Pedido(int cod,int c,int d,int f){
    SetCodigo(cod);
    SetCantidad(c);
    SetDni(d);
    SetFecha(f);
}
Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
    if(obs!=nullptr) delete []obs;
}

void Pedido::SetObs(const char *ob) {
    if(obs!=nullptr) delete []obs;
    obs = new char [strlen(ob)+1];
    strcpy(obs,ob);
}

void Pedido::GetObs(char* ob) const {
    if(obs!=nullptr){
        strcpy(ob,obs);
        return;
    }
    ob[0] = 0;
    
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

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}
//pedido: codigo,cantidad solicitada, dni del cliente, Fecha del pedido
void Pedido::leer(ifstream &arch){
    int codPed,cant,dni,d,m,a;
    char c;
    double tot;
    arch >> codPed;
    if(arch.eof()) return;
    arch.get();
    arch >> cant >> c >> dni >> c >> d >> c >> m >> c >> a;
//    Pedido(codPed,cant,dni,a*10000 + m*100 + d);
    SetCodigo(codPed);
    SetCantidad(cant);
    SetDni(dni);
    SetFecha(a*10000 + m*100 + d);
//    cout << GetCodigo()<<endl;
    Producto::leer("productos3.csv",codigo);
    tot = Pedido::GetPrecio()*Pedido::GetCantidad()+GetTotal();
    SetTotal(tot);
}

void Pedido::imprimir(ofstream &arch){
//    arch << left << setw(10) << GetCodigo()
//            << setw(5) << GetCantidad() 
//            << setw(15) << GetDni()
//            << setw(10) << GetFecha() 
//            << setw (10) << GetTotal() << endl;
    char desc[60],obser[30];
    GetNombre(desc);
    GetObs(obser);
    arch << left 
            << setw(10) << GetFecha()  
            << setw(10) << GetCodigo()
            << setw(60) << desc
            << setw(10) << GetCantidad()
            << setw(10) << GetPrecio()
            << setw (10) << GetTotal()
            << setw (30) << obser << endl;
//    Producto::imprimir(arch);
    arch << endl;
}

void Pedido::actualiza(char tipo){
    switch (tipo){
        case 'A':
            descuento(50,"Descuento Especial de 50%");
            break;
        case 'B':
            descuento(30,"Descuento Especial de 30%");
            break;
        case 'C':
            descuento(10,"Descuento Especial de 10%");
            break;
    }
}

void Pedido::descuento(int desc,const char *nomb){
    double tot;
    
    tot = GetTotal();
    SetTotal(tot-(tot*((double)desc)/100));
    SetObs(nomb);
}