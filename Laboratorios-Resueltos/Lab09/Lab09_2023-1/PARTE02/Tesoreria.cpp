/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tesoreria.cpp
 * Author: Afedo
 * 
 * Created on 5 de junio de 2024, 12:19
 */

#include "Tesoreria.h"
#include "FuncionesApertura.h"

void Tesoreria::cargaescalas(){
    ifstream arch;
    aperturaDeArchivoParaLeer(arch,"escalas.csv");
    int escala;
    double precio;
    while(true){
        arch >> escala;
        if(arch.eof()) break;
        arch.get();
        arch >> precio;
        lescala[escala-1].SetCodigo(escala);
        lescala[escala-1].SetPrecio(precio);
    }
}
//Tipo de alumno, código, nombre, escala, créditos, descuento/recarga/licencia
void Tesoreria::cargaalumnos(){
    ifstream arch;
    aperturaDeArchivoParaLeer(arch,"alumnos.csv");
    
    char tipo;  
    int nB=0;
    while(true){
        arch >> tipo;
        if(arch.eof()) break;
        arch.get();
        lboleta[nB].asignaMemoria(tipo);
        lboleta[nB].leeDatos(arch);
        nB++;
    }
}

void Tesoreria::imprimeboleta(){
    ofstream arch;
    aperturaDeArchivoParaEscribir(arch,"prueba.txt");
    arch.precision(2);
    arch << fixed;
    int nB=0;
    while(lboleta[nB].hayDato()){
        lboleta[nB].imprimeDatos(arch);
        nB++;
    }
}

void Tesoreria::actualizaboleta(){
    
    int nB=0,esca;
    while(lboleta[nB].hayDato()){
        esca = lboleta[nB].devolverEscala();
        lboleta[nB].actualizar(lescala[esca-1].GetPrecio());
        nB++;
    }
}