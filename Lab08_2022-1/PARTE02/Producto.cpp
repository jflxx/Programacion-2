/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: Afedo
 * 
 * Created on 30 de mayo de 2024, 18:00
 */

#include "Producto.h"
#include "FuncionesApertura.h"

Producto::Producto() {
     nombre = nullptr;
}
Producto::Producto(int codigoP,char *nombreP,double precioP,int stockP){
    SetCodprod(codigoP);
    SetNombre(nombreP);
    SetPrecio(precioP);
    SetStock(stockP);
}
Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
    if(nombre!=nullptr) delete []nombre;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetNombre(char* nomb) {
    if(nombre!=nullptr) delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

char Producto::GetNombre(char* nomb) const {
    strcpy(nomb,nombre);
}

void Producto::SetCodprod(int codprod) {
    this->codprod = codprod;
}

int Producto::GetCodprod() const {
    return codprod;
}
// codigo,Nombre del producto, precio, stock
void Producto::leer(const char *nombArch,int cod){
    ifstream arch;
    aperturaDeArchivoParaLeer(arch,nombArch);
    int codigoP,stockP;
    double precioP;
    char nombreP[60],c;
    while(true){
        arch >> codigoP;
        if(arch.eof()) break;
        if(codigoP==cod){
            arch >> c;
            arch.getline(nombreP,60,',');
            arch >> precioP >> c >> stockP;
            SetCodprod(codigoP);
            SetNombre(nombreP);
            SetPrecio(precioP);
            SetStock(stockP);
            break;
        }else
            while(arch.get()!='\n');
    }
    
}

void Producto::imprimir(ofstream &arch){
    char nomb[60];
    GetNombre(nomb);
    arch << left << setw(10) << GetCodprod()
            << setw(60)<<nomb
            <<setw(6)<<GetPrecio()
            << setw(5)<<GetStock();
}
