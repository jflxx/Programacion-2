/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: Afedo
 * 
 * Created on 9 de junio de 2024, 10:43
 */

#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}
Arbol::~Arbol() {
//    elimina();
}

void Arbol::insertar(class Medicamento *med){
    insertarRecursivo(raiz,med);
}

void Arbol::imprime(ofstream &arch){
    arch << right << setw(80) << "REPORTE DE MEDICAMENTOS"<<endl;
    for(int i=0; i<130;i++)
        arch << '=';
    arch<<endl;
     arch << left 
            << setw(10) << "Codigo"
            << setw(60) << "Nombre del Medicamento"
            << setw(10) << "Stock"
            << setw(6) << "Precio"
            << "   "
            << setw(30) << "Pais/Laboratorio"
            << "Lote" << endl;
    for(int i=0; i<130;i++)
        arch << '=';
    arch<<endl;
    imprimeRecursivo(arch,raiz);
}

void Arbol::imprimeRecursivo(ofstream &arch,class Nodo *r){
    if(r==nullptr)return;
    imprimeRecursivo(arch,r->izq);
    r->med->imprime(arch);
    imprimeRecursivo(arch,r->der);
}

void Arbol::insertarRecursivo(class Nodo *&r,class Medicamento *med){
    if(r==nullptr){
        r = new Nodo;
        r->der = nullptr;
        r->der = nullptr;
        r->med = med;
    }else
        if(r->med->getCodigo()<med->getCodigo())
            insertarRecursivo(r->der,med);
        else
            insertarRecursivo(r->izq,med);
}

void Arbol::actualiza(int cod){
    actualizaRecursivo(raiz,cod);
}

void Arbol::actualizaRecursivo(class Nodo *&r,int cod){
    if(r==nullptr) return;
    if(r->med->getCodigo()==cod)
        r->med->actualiza();
    else
        if(r->med->getCodigo()<cod)
            actualizaRecursivo(r->der,cod);
        else
            actualizaRecursivo(r->izq,cod);
    
}


