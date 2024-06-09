/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PilaConEnteros.h
 * Author: Afedo
 *
 * Created on 1 de mayo de 2024, 16:43
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
int cmpnumero(const void *a,const void *b);
void *leenumero(ifstream &arch);
void imprimenumero(ofstream &arch,void *a);

#endif /* PILACONENTEROS_H */

