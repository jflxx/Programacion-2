/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   conreceta.cpp
 * Author: Afedo
 * 
 * Created on 28 de mayo de 2024, 18:09
 */

#include "conreceta.h"

conreceta::conreceta() {
    especialidad = nullptr;
}

conreceta::conreceta(const conreceta& orig) {
}

conreceta::~conreceta() {
}

void conreceta::SetEspecialidad(char* especi) {
    if(especialidad!=nullptr)delete []especialidad;
    especialidad = new char [strlen(especi)+1];
    strcpy(especialidad,especi);
}

char conreceta::GetEspecialidad(char* especi) const {
    strcpy(especi,especialidad);
}

void conreceta::SetCodmed(int codmed) {
    this->codmed = codmed;
}

int conreceta::GetCodmed() const {
    return codmed;
}

void conreceta::colocar(int codMedico,int cant,int fecha,
        int medicam,char *esp){
    SetCodmed(codMedico);
    SetEspecialidad(esp);
    leerMedicamento(medicam,cant,fecha);
}

void conreceta::imprimir(ofstream &arch){
    char esp[60];
    GetEspecialidad(esp);
    arch << left << setw(12) << GetCodigo()
                << setw(40) << esp;
    medicamento::imprimir(arch);
    arch << endl;
}

