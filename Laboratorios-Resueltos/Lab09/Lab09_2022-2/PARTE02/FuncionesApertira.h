/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesApertira.h
 * Author: Afedo
 *
 * Created on 5 de junio de 2024, 15:40
 */

#ifndef FUNCIONESAPERTIRA_H
#define FUNCIONESAPERTIRA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

void aperturaDeArchivosParaEscribir(ofstream &arch,const char *nombArch);
void aperturaDeArchivosParaLeer(ifstream &arch,const char *nombArch);

#endif /* FUNCIONESAPERTIRA_H */

