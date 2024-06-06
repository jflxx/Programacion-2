/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: Afedo
 * 
 * Created on 30 de mayo de 2024, 17:52
 */

#include "Cliente.h"

Cliente::Cliente() {
    nombre = nullptr;
    
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
    if(nombre!=nullptr) delete []nombre;
}

void Cliente::SetNombre(char* nomb) {
    if(nombre!=nullptr) delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

char Cliente::GetNombre(char* nomb) const {
    strcpy(nomb,nombre);
}

void Cliente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char Cliente::GetCategoria() const {
    return categoria;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::leer(ifstream &arch){
    int ID;
    char nomb[60],cat,c;
    arch >> ID;
    if(arch.eof()) return;
    arch >> c;
    arch.getline(nomb,60,',');
    arch >> cat;
    
    SetCategoria(cat);
    SetDni(ID);
    SetNombre(nomb);
}