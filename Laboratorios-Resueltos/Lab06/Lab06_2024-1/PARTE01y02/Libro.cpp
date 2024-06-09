/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Afedo
 * 
 * Created on 8 de junio de 2024, 23:10
 */

#include "Libro.h"

Libro::Libro() {
    nombre = nullptr;
    codigo = nullptr;
}

Libro::~Libro() {
    if(nombre!=nullptr) delete []nombre;
    if(codigo!=nullptr) delete []codigo;
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(char* nomb) {
    if(nombre!=nullptr) delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Libro::GetNombre(char* nomb) const {
    if(nombre!=nullptr) strcpy(nomb,nombre);;
}

void Libro::SetCodigo(char* cod) {
    if(codigo!=nullptr) delete []codigo;
    codigo = new char [strlen(cod)+1];
    strcpy(codigo,cod);
}

void Libro::GetCodigo(char* cod) const {
    if(codigo!=nullptr) strcpy(cod,codigo);;
}

void operator >>(ifstream &arch,class Libro &libro){
    char codigo[7],nomb[60];
    int ancho,alto;
    
    arch.getline(codigo,7,',');
    if(arch.eof()) return;
    arch.getline(nomb,60,',');
    arch >> ancho;
    arch.get();
    arch >> alto;
    arch.get();
    
    libro.SetAlto(alto);
    libro.SetAncho(ancho);
    libro.SetCodigo(codigo);
    libro.SetColocado(false);
    libro.SetNombre(nomb);
}

void operator <<(ofstream &arch,class Libro &libro){
    char cod[7],nomb[60];
    libro.GetCodigo(cod);
    libro.GetNombre(nomb);
    if(libro.IsColocado()){
        arch << left << setw(10) << cod
                << setw(25) << nomb 
                << right
                << setw(6) << libro.GetAncho()
                << setw(8) << libro.GetAlto() << endl;
    }else{
        arch << left << setw(10) << cod
                << setw(25) << " NO SE PUDO COLOCAR"
                << right
                << setw(6) << libro.GetAncho()
                << setw(8) << libro.GetAlto() << endl;
    }
}