/* 
 * File:   BibGenerica.h
 * Author: Afedo
 *
 * Created on 28 de abril de 2024, 18:06
 */

#ifndef BIBGENERICA_H
#define BIBGENERICA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;
void crearcola(void *&cola,const char*nombArch,
            void *(*leer)(ifstream &arch),int (*prioridad)(void*));
void *leenumero(ifstream &arch);
void encolar(void *&cola,void *dato,int (*obtieneprioridad)(void*));
int colaVacia(void *cola);

int prioridadNumero(void *dato);

void imprimirnum(void *cola, const char *nomarch);
void *desencola(void *cola);
#endif /* BIBGENERICA_H */

