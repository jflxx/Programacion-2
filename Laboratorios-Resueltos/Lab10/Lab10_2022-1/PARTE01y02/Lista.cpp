/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Lista.cpp
 * Author: Afedo
 * 
 * Created on 6 de junio de 2024, 22:59
 */

#include <ratio>

#include "Lista.h"
#include "FuncionesApertura.h"
#include "Pedido.h"

Lista::Lista() {
    lini = nullptr;
    lfin = nullptr;
}
Lista::~Lista() {
//    elimina();
}

void Lista::insertar(Pedido *ped){
    class Nodo *nuevoNodo,*p = lini,*ant = nullptr;

    nuevoNodo = new class Nodo;
    nuevoNodo->sig = nullptr;
    nuevoNodo->ant = nullptr;
    nuevoNodo->ped = ped;
    
    while(p){
        if(ped->GetCodigo() < p->ped->GetCodigo()) break;
        if(ped->GetCodigo() == p->ped->GetCodigo() && 
                ped->GetFecha() < p->ped->GetFecha()) break;
        ant = p;
        p = p->sig;
    }
    // si el nodo entrante va primero
    if(ant==nullptr){
        lini = nuevoNodo;
        lfin = nuevoNodo;
        nuevoNodo->sig = p;
    }else{ //ya hay nodo
        if(p==nullptr){
            ant->sig = nuevoNodo;
            lfin = nuevoNodo;
        }else{
            nuevoNodo->sig = p;
            nuevoNodo->ant = ant;
            ant->sig = nuevoNodo;
        }
    } 
}

void Lista::imprimeLista(ofstream &arch){
    Nodo *p = lini;
    while(p){
        arch << p->ped;
        arch << endl;
        p = p->sig;
    }
}

void Lista::actualiza(ifstream &arch){
    
    Nodo *p;
    int dni,d,m,a;
    char c;
    while(true){
        p = lfin;
        arch >> dni >> c >> d >> c >> m >> c >> a;
        if(arch.eof()) break;
        while(p){
            if(p->ped->GetDni() == dni && p->ped->GetFecha()>=a*10000+m*100+d){
                p->ped->actualiza();
            }
            p = p->ant;
        }
    }
    
}