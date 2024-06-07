/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Virtual.cpp
 * Author: Afedo
 * 
 * Created on 5 de junio de 2024, 12:12
 */

#include "Virtual.h"
#include "Alumno.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 0;
}

Virtual::~Virtual() {
    if(licencia != nullptr) delete []licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(char* lice) {
    if(licencia != nullptr) delete []licencia;
    licencia = new char [strlen(lice)+1];
    strcpy(licencia,lice);
}

void Virtual::GetLicencia(char* lice) const {
    if(licencia != nullptr) strcpy(lice,licencia);
    else lice[0]=0;
}

void Virtual::lee(ifstream &arch){
    char lic[10];
    Alumno::lee(arch);
    arch >> lic;
    arch.get();
    SetLicencia(lic);
}

void Virtual::imprime(ofstream &arch){
    Alumno::imprime(arch);
    char lice[10];
    GetLicencia(lice);
    
    arch << setw(15) << lice
            << right << setw(7) << total << endl;
}


void Virtual::actualizatotal(double valorC){
    Alumno::actualizatotal(valorC);
    double totDes = Alumno::GetTotal()+100;
    SetTotal(totDes);
    Alumno::SetTotal(totDes);
}