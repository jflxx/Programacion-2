/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   sinreceta.cpp
 * Author: Afedo
 * 
 * Created on 5 de junio de 2024, 15:19
 */

#include "sinreceta.h"

sinreceta::sinreceta() {
    nombre = nullptr;
}
sinreceta::~sinreceta() {
    if(nombre != nullptr) delete []nombre;
}

void sinreceta::SetNombre(char* nomb) {
    if(nombre != nullptr) delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void sinreceta::GetNombre(char* nomb) const {
    if(nombre != nullptr) strcpy(nomb,nombre);;
}

void sinreceta::SetDni(int dni) {
    this->dni = dni;
}

int sinreceta::GetDni() const {
    return dni;
}


void sinreceta::leemedicamento(ifstream &arch){
    medicamento::leemedicamento(arch);
    char nomb[50];
    int codDoc;
    arch>> codDoc;
    arch.get();
    arch >> dni;
    arch.get();
    arch >> nomb;
    SetNombre(nomb);
}

void sinreceta::imprimemedicamento(ofstream &arch){
    char nomb[50];
    GetNombre(nomb);
    medicamento::imprimemedicamento(arch);
    arch << right << setw(10) << GetDni()
            << setw(25) << nomb << endl;
}

void sinreceta::aplicadescuento(){
    medicamento::aplicadescuento();
    double tot=GetTotal();
    SetTotal(tot*(0.9));
}