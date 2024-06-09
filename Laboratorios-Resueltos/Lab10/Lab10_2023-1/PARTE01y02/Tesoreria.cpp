/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tesoreria.cpp
 * Author: Afedo
 * 
 * Created on 8 de junio de 2024, 11:47
 */

#include "Tesoreria.h"
#include "FuncionesApertura.h"
void Tesoreria::cargaalumnos(){
    ifstream arch;
    aperturaDeArchivoParaLectura(arch,"alumnos.csv");
    class Boleta boleta;
    while(true){
        boleta.leeAlumno(arch);
        if(arch.eof()) break;
        aboleta.insertar(boleta);
    }
}

void Tesoreria::imprimeboleta(){
    ofstream arch;
    aperturaDeArchivoParaEscritura(arch,"prueba.txt");
    arch.precision(2);
    arch << fixed;
    aboleta.imprime(arch);
}

void Tesoreria::actualizaboleta(){
    ifstream archEsc;
    aperturaDeArchivoParaLectura(archEsc,"escalas.csv");
    aboleta.leeEscalas(archEsc);
    aboleta.actualiza();
}
