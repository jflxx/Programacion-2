/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: Afedo
 * 
 * Created on 8 de junio de 2024, 11:41
 */

#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}
Arbol::~Arbol() {
//    if(raiz!=nullptr) delete raiz;
}

void Arbol::insertar(const class Boleta &bol){
    insertarRecursivo(raiz,bol);
}

void Arbol::insertarRecursivo(class Nodo *&nuevo,const class Boleta &bol){
    if(nuevo==nullptr){
        nuevo = new class Nodo;
        nuevo->dboleta = bol;
        return;
    }
    if(nuevo->dboleta < bol) insertarRecursivo(nuevo->der,bol);
    else insertarRecursivo(nuevo->izq,bol);
}

void Arbol::imprime(ofstream &arch){
    imprimeR(raiz,arch);
}

void Arbol::imprimeR(class Nodo *p,ofstream &arch){
    if(p==nullptr) return;
    imprimeR(p->izq,arch);
    p->dboleta.imprimeAlumno(arch);
    imprimeR(p->der,arch);
}

void Arbol::leeEscalas(ifstream &arch){
    int n;
    double prec;
    while(true){
        arch >> n;
        if(arch.eof()) break;
        arch.get();
        arch >> prec;
        lescala[n-1].SetPrecio(prec);
        lescala[n-1].SetCodigo(n);
    }
}

void Arbol::actualiza(){
    actualizaR(raiz);
}

void Arbol::actualizaR(class Nodo *p){
    if(p==nullptr) return;
    actualizaR(p->izq);
    actualizaR(p->der);
    int esc = p->dboleta.devolverEscala();
    p->dboleta.actualiza(lescala[esc-1].GetPrecio());
}