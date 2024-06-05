/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Afedo
 *
 * Created on 30 de mayo de 2024, 18:05
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Producto.h"


class Pedido:public Producto{
public:
    Pedido();
    Pedido(int cod,int c,int d,int f);
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetObs(char* ob);
    char GetObs(char* ob) const;
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
private:
    int codigo;
    int cantidad;
    int dni;
    int fecha;
    double total;
    char *obs;
};

#endif /* PEDIDO_H */

