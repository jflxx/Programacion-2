/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesPila.h
 * Author: Afedo
 *
 * Created on 1 de mayo de 2024, 16:42
 */

#ifndef FUNCIONESPILA_H
#define FUNCIONESPILA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

void imprimirArreglo(void *arr);

void cargaarreglo(void *&arreglo,int (*cmp)(const void*,const void*),
        void *(*lee)(ifstream &arch),const char *nombArch);
bool pilavacia(void *pila);
void push(void *&pila,void *dato);
void cargapila(void *&pila,void *&arreglo);
void imprimepila(void *pilaIni,void (*imprimenumero)(ofstream &arch,void*),const char*nombArch);
void *pop(void *&pila);
void muevepila(void *&pilaini,void *&pilafin);

#endif /* FUNCIONESPILA_H */

