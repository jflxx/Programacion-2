/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Virtual.cpp
 * Author: Afedo
 * 
 * Created on 8 de junio de 2024, 11:35
 */

#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 0;
}
Virtual::~Virtual() {
    if(licencia!=nullptr) delete []licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(char* lic) {
    if(licencia!=nullptr) delete []licencia;
    licencia = new char [strlen(lic)+1];
    strcpy(licencia,lic);
}

void Virtual::GetLicencia(char* lic) const {
    if(licencia!=nullptr) strcpy(lic,licencia);
    else lic[0] = 0;
}

void Virtual::lee(ifstream &arch){
    char lice[10];
    Alumno::lee(arch);
    arch.getline(lice,10,'\n');
    SetLicencia(lice);
}


void Virtual::imprime(ofstream &arch){
    char lic[10];
    GetLicencia(lic);
    Alumno::imprime(arch);
    arch << setw(10) << lic
            << right << setw(10) << total <<endl;
}

void Virtual::actualizatotal(double CostCred){
    Alumno::actualizatotal(CostCred);
    double tot = Alumno::GetTotal();
    total = 100+tot;
    Alumno::SetTotal(total);
}
