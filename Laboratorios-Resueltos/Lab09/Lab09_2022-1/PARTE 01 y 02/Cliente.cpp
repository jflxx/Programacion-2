/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: Afedo
 * 
 * Created on 6 de junio de 2024, 12:33
 */

#include "Cliente.h"

Cliente::Cliente() {
    nombre = nullptr;
    totalped = 0;
    cantped =0;
}

Cliente::~Cliente() {
    if(nombre != nullptr) delete []nombre;
}

void Cliente::SetTotalped(double totalped) {
    this->totalped = totalped;
}

double Cliente::GetTotalped() const {
    return totalped;
}

void Cliente::SetCantped(int cantped) {
    this->cantped = cantped;
}

int Cliente::GetCantped() const {
    return cantped;
}

void Cliente::SetNombre(char* nomb) {
    if(nombre != nullptr) delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Cliente::GetNombre(char* nomb) const{
    if(nombre != nullptr) strcpy(nomb,nombre);
    nomb[0] = 0;
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

void Cliente::lee(ifstream &arch){
    char nomb[60];
    arch >> dni;
    arch.get();
    arch.getline(nomb,60,'\n');
    SetNombre(nomb);
}

void Cliente::imprime(ofstream &arch){
    arch << setw(10) << "Total:" << totalped << endl;
     arch << setw(20) << "Cantidad de Pedidos: "<< cantped << endl;
}

void Cliente::imprimeDatos(ofstream &arch){
    arch << left << setw(15) << dni
                << nombre << endl;
    for(int i=0; i<50 ;i++)
        arch << '-';
    arch << endl;
}

void Cliente::calcula(double tot){
    totalped+=tot;
    cantped++;
}