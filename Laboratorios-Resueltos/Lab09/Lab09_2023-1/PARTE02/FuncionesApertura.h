/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesApertura.h
 * Author: Afedo
 *
 * Created on 5 de junio de 2024, 13:13
 */

#ifndef FUNCIONESAPERTURA_H
#define FUNCIONESAPERTURA_H

#include <fstream>
#include <iostream>
using namespace std;

void aperturaDeArchivoParaLeer(ifstream &arch,const char *nombArch);
void aperturaDeArchivoParaEscribir(ofstream &arch,const char *nombArch);

#endif /* FUNCIONESAPERTURA_H */

