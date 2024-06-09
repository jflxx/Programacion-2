/* 
 * File:   FunConRegistro.h
 * Author: Afedo
 *
 * Created on 28 de abril de 2024, 20:05
 */

#ifndef FUNCONREGISTRO_H
#define FUNCONREGISTRO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

int prioridadpedido(void *dato);
void *leeRegistro(ifstream &arch);
void imprimirped(void *cola, const char *nomarch);

#endif /* FUNCONREGISTRO_H */

