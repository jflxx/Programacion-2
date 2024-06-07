/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: Afedo
 * 
 * Created on 5 de junio de 2024, 12:01
 */

#include "Alumno.h"

Alumno::Alumno() {
    total = 0;
    nombre = nullptr;
}

Alumno::~Alumno() {
    if(nombre != nullptr) delete []nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(char* nomb) {
    if(nombre != nullptr) delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Alumno::GetNombre(char* nomb) const {
    if(nombre != nullptr) strcpy(nomb,nombre);
    else nomb[0] = 0;
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::lee(ifstream &arch){
    char nombreA[60],c;
    arch >> codigo >> c;
    arch.getline(nombreA,60,',');
    arch >> escala;
    arch.get();
    arch >> creditos;
    arch.get();
    SetNombre(nombreA);
}

void Alumno::imprime(ofstream &arch){
    char nomb[60];
    GetNombre(nomb);
    arch << left << setw(20) << codigo
            << setw(60) << nomb
            << setw(10) << escala
            << setw(10) << creditos;
}

void Alumno::actualizatotal(double valorC){
    SetTotal(valorC*creditos);
}