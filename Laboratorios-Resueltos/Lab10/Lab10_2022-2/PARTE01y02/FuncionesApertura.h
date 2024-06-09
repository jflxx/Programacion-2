/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesApertura.h
 * Author: Afedo
 *
 * Created on 9 de junio de 2024, 10:49
 */

#ifndef FUNCIONESAPERTURA_H
#define FUNCIONESAPERTURA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

void aperturaDeArchivosParaLectura(ifstream &arch,const char *nombArch){
    arch.open(nombArch,ios::in);
    if(!arch.is_open()){
        cout << "No se pudo abrir el archivo: " << nombArch << endl;
        exit(1);
    }
}
void aperturaDeArchivosParaEscritura(ofstream &arch,const char *nombArch){
    arch.open(nombArch,ios::out);
    if(!arch.is_open()){
        cout << "No se pudo abrir el archivo: " << nombArch << endl;
        exit(1);
    }
}

#endif /* FUNCIONESAPERTURA_H */

