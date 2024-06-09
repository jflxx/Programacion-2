/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Afedo
 *
 * Created on 6 de junio de 2024, 22:57
 */

#ifndef NODO_H
#define NODO_H
#include "Pedido.h"
#include "Lista.h"

class Nodo {
public:
    Nodo();
    friend class Lista;
private:
    class Pedido *ped;
    class Nodo *sig;
    class Nodo *ant;
};


#endif /* NODO_H */

