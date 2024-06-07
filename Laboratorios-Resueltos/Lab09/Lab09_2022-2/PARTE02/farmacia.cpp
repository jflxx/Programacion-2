/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   farmacia.cpp
 * Author: Afedo
 * 
 * Created on 5 de junio de 2024, 15:37
 */

#include "farmacia.h"
#include "FuncionesApertira.h"
// cod.Med , cant, fecha, cod.Doc, Dni, nombre Pa
void farmacia::leerecetas(){
    ifstream arch;
    aperturaDeArchivosParaLeer(arch,"recetas2.csv");
    int codMedicamento;
    int nR = 0;
    while(true){
        arch >> codMedicamento;
        if(arch.eof()) break;
        arch.get();
        loferta[nR].iniciarMedicamento(codMedicamento);
        loferta[nR].Leer(codMedicamento,arch);
        nR++;
    }
}

void farmacia::imprimirrecetas(){
    ofstream arch;
    aperturaDeArchivosParaEscribir(arch,"Prueba.txt");
    int nO=0;
    while(loferta[nO].hayDato()){
        loferta[nO].imprime(arch);
        nO++;
    }
    
}

void farmacia::descuenta(){
    int nO=0;
    while(loferta[nO].hayDato()){
        loferta[nO].actualiza();
        nO++;
    }
}