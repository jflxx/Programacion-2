/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Lista.h
 * Author: Afedo
 *
 * Created on 6 de junio de 2024, 22:59
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "Pedido.h"

class Lista {
public:
    Lista();
    virtual ~Lista();
    void elimina();
    void insertar(class Pedido *ped);
    void imprimeLista(ofstream &arch);
    void actualiza(ifstream &arch);
private:
    class Nodo *lini;
    class Nodo *lfin;
};

void operator>>(ifstream &arch,class Pedido *&ped);

#endif /* LISTA_H */

