/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Marca.cpp
 * Author: Afedo
 * 
 * Created on 9 de junio de 2024, 10:41
 */

#include "Marca.h"

Marca::Marca() {
    laboratorio = nullptr;
}
Marca::~Marca() {
    if(laboratorio != nullptr) delete []laboratorio;
}

void Marca::setLaboratorio(char* lab) {
    if(laboratorio != nullptr) delete []laboratorio;
    laboratorio = new char [strlen(lab)+1];
    strcpy(laboratorio,lab);
}

void Marca::getLaboratorio(char* lab) const {
    if(laboratorio != nullptr) strcpy(lab,laboratorio);
    else lab[0]=0;
}

void Marca::lee(ifstream &arch){
    char lab[50];
    Medicamento::lee(arch);
    arch.getline(lab,50,',');
    setLaboratorio(lab);
    arch >> lote;
}

void Marca::imprime(ofstream &arch){
    char lab[30];
    getLaboratorio(lab);
    Medicamento::imprime(arch);
    arch << left 
            << setw(30) << lab << lote << endl;
}


void Marca::actualiza(){
    double tot;
    tot = Medicamento::getPrecio();
    tot = tot*(1.20);
    Medicamento::setPrecio(tot);
}