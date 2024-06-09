/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Boleta.cpp
 * Author: Afedo
 * 
 * Created on 8 de junio de 2024, 11:38
 */

#include "Boleta.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
Boleta::Boleta() {
    pboleta = nullptr;
}
void Boleta::leeAlumno(ifstream &arch){
    char tipo;
    arch >> tipo;
    arch.get();
    if(arch.eof()) return; 
    switch (tipo){
        case 'P':
            pboleta = new class Presencial;
            break;
        case 'S':
            pboleta = new class Semipresencial;
            break;
        case 'V':
            pboleta = new class Virtual;
            break;
    }
    pboleta->lee(arch);
}

bool Boleta::operator <(const class Boleta &bol){
    return pboleta->GetCodigo()<bol.pboleta->GetCodigo();
}

void Boleta::imprimeAlumno(ofstream &arch){
    pboleta->imprime(arch);
}

void Boleta::actualiza(double PrecCred){
    pboleta->actualizatotal(PrecCred);
}

int Boleta::devolverEscala(){
    return pboleta->GetEscala();
}