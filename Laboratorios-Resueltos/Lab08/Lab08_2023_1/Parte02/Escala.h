/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Escala.h
 * Author: Afedo
 *
 * Created on 26 de mayo de 2024, 19:16
 */

#ifndef ESCALA_H
#define ESCALA_H
#include <iostream>
#include <cstring>
using namespace std;
class Escala {
public:
    Escala();
    Escala(int cod,double prec);
    Escala(const Escala& orig);
    virtual ~Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    double precio;
};

#endif /* ESCALA_H */

