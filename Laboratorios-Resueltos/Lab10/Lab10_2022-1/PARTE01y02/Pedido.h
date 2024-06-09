/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Afedo
 *
 * Created on 6 de junio de 2024, 22:50
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Pedido {
public:
    Pedido();
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(char* nomb);
    void GetNombre(char* nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch) const;
    virtual void actualiza() = 0;
private:
    int codigo;
    char *nombre;
    int cantidad;
    int dni;
    int fecha;
    double total;
};

void operator <<(ofstream &arch,const class Pedido *ped);

#endif /* PEDIDO_H */

