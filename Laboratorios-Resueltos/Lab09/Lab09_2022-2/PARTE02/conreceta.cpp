/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   conreceta.cpp
 * Author: Afedo
 * 
 * Created on 5 de junio de 2024, 15:18
 */

#include "conreceta.h"
#include "FuncionesApertira.h"

conreceta::conreceta() {
    especialidad = nullptr;
}
conreceta::~conreceta() {
    if(especialidad!=nullptr) delete []especialidad;
}

void conreceta::SetEspecialidad(char* espe) {
    if(especialidad != nullptr) delete []especialidad;
    especialidad = new char [strlen(espe)+1];
    strcpy(especialidad,espe);
}

void conreceta::GetEspecialidad(char* espe) const {
    if(especialidad != nullptr) strcpy(espe,especialidad);
}

void conreceta::SetCodmed(int codmed) {
    this->codmed = codmed;
}

int conreceta::GetCodmed() const {
    return codmed;
}

void conreceta::leemedicamento(ifstream &arch){
    ifstream archMedicos;
    aperturaDeArchivosParaLeer(archMedicos, "medicos.csv");
    
    medicamento::leemedicamento(arch);
    arch >> codmed;
    
    while(arch.get()!='\n');
    
    int codigoMed;
    char nombreMed[50],especiMed[50];
    while(true){
        archMedicos >> codigoMed;
        if(codigoMed == GetCodmed()) break;
        else 
            while(archMedicos.get()!='\n');
    }
    archMedicos.get();
    archMedicos.getline(nombreMed,50,',');
    archMedicos >> especiMed;
    SetEspecialidad(especiMed);
    
}

void conreceta::imprimemedicamento(ofstream &arch){
    char esp[50];
    medicamento::imprimemedicamento(arch);
    GetEspecialidad(esp);
    arch << right << setw(10) << GetCodigo()
            << setw(25) << esp << endl;
}

void conreceta::aplicadescuento(){
    medicamento::aplicadescuento();
    double tot=GetTotal();
    SetTotal(tot*(1.05));
}