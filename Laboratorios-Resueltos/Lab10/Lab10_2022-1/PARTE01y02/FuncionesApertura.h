/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesApertura.h
 * Author: Afedo
 *
 * Created on 6 de junio de 2024, 23:10
 */

#ifndef FUNCIONESAPERTURA_H
#define FUNCIONESAPERTURA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

void aperturaDeArchivosParaLeer(ifstream &arch,const char *nombArch);
void aperturaDeArchivosParaEscribir(ofstream &arch,const char *nombArch);

#endif /* FUNCIONESAPERTURA_H */

