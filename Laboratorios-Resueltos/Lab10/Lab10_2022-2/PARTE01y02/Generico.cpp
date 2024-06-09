/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Generico.cpp
 * Author: Afedo
 * 
 * Created on 9 de junio de 2024, 10:40
 */

#include "Generico.h"

Generico::Generico() {
    pais =nullptr;
}
Generico::~Generico() {
    if(pais!=nullptr) delete []pais;
}


void Generico::setPais(char* p) {
    if(pais!=nullptr) delete []pais;
    pais  = new char [strlen(p)+1];
    strcpy(pais,p);
}

void Generico::getPais(char* p) const {
    strcpy(p,pais);
}

void Generico::lee(ifstream &arch){
    char P[20];
    Medicamento::lee(arch);
    arch.getline(P,20,'\n');
    setPais(P);
}

void Generico::imprime(ofstream &arch){
    char p[30];
    getPais(p);
    Medicamento::imprime(arch);
    arch << left 
            << setw(30) << p << endl;
}

void Generico::actualiza(){
    //no hace nada
}