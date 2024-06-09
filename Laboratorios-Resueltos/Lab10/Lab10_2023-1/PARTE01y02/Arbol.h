/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: Afedo
 *
 * Created on 8 de junio de 2024, 11:41
 */

#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Nodo.h"
#include "Escala.h"
#include "Boleta.h"

class Arbol {
public:
    Arbol();
    virtual ~Arbol();
    void insertar(const class Boleta &bol);
    void imprime(ofstream &arch);
    void leeEscalas(ifstream &arch);
    void actualiza();
private:
    class Nodo *raiz;
    class Escala lescala[10];
    void insertarRecursivo(class Nodo *&nuevo,const class Boleta &bol);
    void imprimeR(class Nodo *p,ofstream &arch);
    void actualizaR(class Nodo *p);
};

#endif /* ARBOL_H */

