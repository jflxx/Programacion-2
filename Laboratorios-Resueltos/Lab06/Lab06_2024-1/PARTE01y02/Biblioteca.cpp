/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Afedo
 * 
 * Created on 8 de junio de 2024, 23:17
 */

#include "Biblioteca.h"
#include "FuncionesAuxiliares.h"

Biblioteca::Biblioteca() {
    cantidad_estantes = 0;
    cantidad_libros = 0;
}

void Biblioteca::cargar_libros(){
    ifstream arch("libros.csv",ios::in);
    int nL=0;
    while(true){
        arch >> libros[nL];
        if(arch.eof()) break;
        nL++;
    }
    cantidad_libros = nL;
}

void Biblioteca::cargar_estantes(){
    ifstream arch("estantes.csv",ios::in);
    int nE=0;
    while(true){
        arch >> estantes[nE];
        if(arch.eof()) break;
        nE++;
    }
    cantidad_estantes = nE;
}

void Biblioteca::posicionar_libros(){
    
    for(int i=0; i<cantidad_libros ;i++){
        for(int j=0; j<cantidad_estantes ;j++){
            if(estantes[j]+=libros[i]){
                break;
            }
        }
    }
}

void Biblioteca::mostrar_datos(){
    ofstream arch;
    AperturaDeArchivoParaEscritura(arch,"Reporte.txt");
    
    imprimirLinea(arch,50,'=');
    arch << right << setw(45) << "Informacion del posicionamiento de Libros"<<endl;
    arch << setw(40) << "en los estantes de la Biblioteca"<<endl;
    imprimirLinea(arch,50,'=');
    arch << left << setw(20) << "Cantidad de Estantes"
            << right << setw(2) << cantidad_estantes<<endl;
    for(int i=0; i<cantidad_estantes ;i++){
        arch << estantes[i];
    }
    
    arch << endl;
    imprimirLibros(arch);
}

void Biblioteca::imprimirLibros(ofstream &arch){
    arch << "Informacion de todos los Libros:" << endl;
    arch << "Cantidad de Libros Total:  "<< cantidad_libros<<endl;
    
    for(int i=0;i<cantidad_libros;i++)
        arch << libros[i];
}

