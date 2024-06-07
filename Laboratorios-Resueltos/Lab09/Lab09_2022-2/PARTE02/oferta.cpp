/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   oferta.cpp
 * Author: Afedo
 * 
 * Created on 5 de junio de 2024, 15:35
 */

#include "oferta.h"

oferta::oferta() {
    poferta = nullptr;
}
oferta::~oferta() {
    if(poferta!=nullptr) delete poferta;
}


void oferta::iniciarMedicamento(int cod_medi){
    if ((cod_medi/10000)%2==0){
        poferta = new class conreceta;
    }else
        poferta = new class sinreceta;
}

void oferta::Leer(int codMedicamento,ifstream &arch){
    poferta->SetCodigo(codMedicamento);
    poferta->leemedicamento(arch);
}

bool oferta::hayDato(){
    return poferta!=nullptr? true:false;
}

void oferta::imprime(ofstream &arch){
    poferta->imprimemedicamento(arch);
}

void oferta::actualiza(){
    poferta->aplicadescuento();
}