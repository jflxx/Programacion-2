/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: Afedo
 * 
 * Created on 26 de mayo de 2024, 19:05
 */

#include "Alumno.h"

Alumno::Alumno() {
    nombre = nullptr;
    total = 0;
}
Alumno::Alumno(int cod,const char *nomb,int escala,double total){
    nombre = nullptr;
    SetNombre(nomb);
    SetCodigo(cod);
    SetEscala(escala);
    SetTotal(total);
}

Alumno::Alumno(const Alumno& orig) {
//    nombre = nullptr;
//    *this = orig;
}

Alumno::~Alumno() {
    if(nombre!=nullptr) delete []nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char* nomb) {
    if(nombre!=nullptr) delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

char Alumno::GetNombre(char* nomb) const {
    strcpy(nomb,nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::leerDatos(ifstream &arch){
    int codigo,escala;
    double descuento;
    char nombre[60],c;
    
    arch >> codigo >> c;
    arch.getline(nombre,60,',');
    arch >> escala;
    arch.get();
    
    SetCodigo(codigo);
    SetEscala(escala);
    SetNombre(nombre);
}

void Alumno::imprimir(ofstream &arch){
    char nombre[60];
    GetNombre(nombre);
    arch << left
            << setw(20) << GetCodigo()
            << setw(60) << nombre
            << setw(10) << GetEscala();
}

