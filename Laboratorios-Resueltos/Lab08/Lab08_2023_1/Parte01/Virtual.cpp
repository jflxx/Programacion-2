/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Virtual.cpp
 * Author: Afedo
 * 
 * Created on 26 de mayo de 2024, 19:41
 */

#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 0;
}

Virtual::Virtual(const Virtual& orig) {
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

char Virtual::GetLicencia(char* lic) const {
    strcpy(lic,licencia);
}

void Virtual::leerDatos(ifstream &arch){
    char lic[9];
    Alumno::leerDatos(arch);
    arch.get(lic,9,'\n');
    SetLicencia(lic);
}

void Virtual::actualiza(double prec){
    total = prec+100;
    Alumno::SetTotal(total);
}
void Virtual::imprime(ofstream &arch){
    char lic[9];
    Alumno::imprimir(arch);
    GetLicencia(lic);
    arch << right << setw(10) << lic
            << setw(15) << GetTotal() <<endl;
//    arch << right << setw(25) << GetTotal()<<endl;
}