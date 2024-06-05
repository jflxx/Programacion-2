/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   sinreceta.cpp
 * Author: Afedo
 * 
 * Created on 28 de mayo de 2024, 18:12
 */

#include "sinreceta.h"

sinreceta::sinreceta() {
}

sinreceta::sinreceta(const sinreceta& orig) {
}

sinreceta::~sinreceta() {
}

void sinreceta::SetNombre(char* nomb) {
     if(nombre!=nullptr)delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

char sinreceta::GetNombre(char* nomb) const {
    strcpy(nomb,nombre);
}

void sinreceta::SetDni(int dni) {
    this->dni = dni;
}

int sinreceta::GetDni() const {
    return dni;
}

void sinreceta::colocar(int DNIs,int cant,int fecha,int medicam,char *nombP){
    SetNombre(nombP);
    SetDni(DNIs);
    leerMedicamento(medicam,cant,fecha);
}

void sinreceta::imprimir(ofstream &arch){
    char nomb[60];
    GetNombre(nomb);
    medicamento::imprimir(arch);
    arch << left << setw(12) << GetDni()
                << setw(40) << nomb;
    arch << endl;
}
