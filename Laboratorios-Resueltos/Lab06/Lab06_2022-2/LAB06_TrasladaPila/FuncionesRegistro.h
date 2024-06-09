/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesRegistro.h
 * Author: Afedo
 *
 * Created on 1 de mayo de 2024, 20:15
 */

#ifndef FUNCIONESREGISTRO_H
#define FUNCIONESREGISTRO_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
using namespace std;

void cargaarreglo(void *&arr,int (*cmp)(const void*,const void*),
        void *(*lee)(ifstream &arch),const char *nombArch);

void *leeregistro(ifstream &arch);
int cmpregistro(const void*a,const void*b);
void *leeregistro(ifstream &arch);
void imprimepila2(void *pilafin,void (*imprimeregistro)(ofstream &arch,void*),const char *nombArch);
void imprimeregistro(ofstream &arch,void *reg);

#endif /* FUNCIONESREGISTRO_H */

