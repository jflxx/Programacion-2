/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: Afedo
 *
 * Created on 30 de mayo de 2024, 18:00
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class Producto {
public:
    Producto();
    Producto(int codigoP,char *nombreP,double precioP,int stockP);
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(char* nomb);
    char GetNombre(char* nomb) const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
    void leer(const char *nombArch,int cod);
    void imprimir(ofstream &arch);
private:
    int codprod;
    char *nombre;
    double precio;
    int stock;
};

#endif /* PRODUCTO_H */

