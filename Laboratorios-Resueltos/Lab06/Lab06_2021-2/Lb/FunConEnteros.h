

/* 
 * File:   FunConEnteros.h
 * Author: Afedo
 *
 * Created on 28 de abril de 2024, 19:10
 */

#ifndef FUNCONENTEROS_H
#define FUNCONENTEROS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

void *leenumero(ifstream &arch);
int prioridadNumero(void *dato);
void imprimirnum(void *cola, const char *nomarch);


#endif /* FUNCONENTEROS_H */

