/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: Afedo
 *
 * Created on 9 de junio de 2024, 10:43
 */

#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"
#include "Medicamento.h"
class Arbol {
public:
    Arbol();
    virtual ~Arbol();
    void insertar(class Medicamento *med);
    void imprime(ofstream &arch);
    void actualiza(int cod);
private:
    void insertarRecursivo(class Nodo *&r,class Medicamento *med);
    void imprimeRecursivo(ofstream &arch,class Nodo *r);
    void actualizaRecursivo(class Nodo *&r,int cod);
    class Nodo *raiz;
};

#endif /* ARBOL_H */

