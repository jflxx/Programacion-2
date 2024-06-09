/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Afedo
 *
 * Created on 9 de junio de 2024, 12:17
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

void AperturaDeArchivoParaEscritura(ofstream &arch,const char *nombArch){
    arch.open(nombArch,ios::out);
    if(!arch.is_open()){
        cout << "No se pudo abrir el archivo: " << nombArch;
        exit(1);
    }
}

void imprimirLinea(ofstream &arch,int lim,char c){
    for(int i=0; i<lim ;i++)
        arch << c;
    arch << endl;
}

#endif /* FUNCIONESAUXILIARES_H */

