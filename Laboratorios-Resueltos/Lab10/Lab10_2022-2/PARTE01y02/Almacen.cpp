
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Almacen.cpp
 * Author: Afedo
 * 
 * Created on 9 de junio de 2024, 10:47
 */

#include "Almacen.h"
#include "FuncionesApertura.h"
#include "Generico.h"
#include "Marca.h"

void Almacen::carga(){
    ifstream arch;
    aperturaDeArchivosParaLectura(arch,"medicamentos.csv");
    
    class Medicamento *med;
    while(true){
        med = leerMedicamento(arch);
        if(arch.eof()) break;
        arbolalma.insertar(med);
    }
}

void Almacen::actualiza(){
    ifstream arch;
    aperturaDeArchivosParaLectura(arch,"recarga.csv");
    int cod;
    
    while(true){
        arch >> cod;
        if(arch.eof()) break;
        arbolalma.actualiza(cod);
    }
}



void Almacen::imprime(){
    ofstream arch;
    aperturaDeArchivosParaEscritura(arch,"ReporteDeMedicamentos.txt");
    arch.precision(2);
    arch << fixed;
    arbolalma.imprime(arch);
}

Medicamento* Almacen::leerMedicamento(ifstream &arch){
    Medicamento *med;
    int tipo;
    
    arch >> tipo;
    arch.get();
    if(arch.eof()) return nullptr;
    if(tipo==0)
        med = new class Generico;
    else
        med = new class Marca;
    
    med->lee(arch);
    return med;
}


