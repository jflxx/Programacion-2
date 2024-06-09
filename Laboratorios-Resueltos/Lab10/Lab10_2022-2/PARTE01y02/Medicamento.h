/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Medicamento.h
 * Author: Afedo
 *
 * Created on 9 de junio de 2024, 10:39
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Medicamento {
public:
    Medicamento();
    virtual ~Medicamento();
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    void setNombre(char* nomb);
    void getNombre(char* nomb) const;
    void setCodigo(int codigo);
    int getCodigo() const;
    virtual void actualiza()=0;
    void setPrecio(double precio);
    double getPrecio() const;
private:
    int codigo;
    char* nombre;
    int stock;
    double precio;
};

#endif /* MEDICAMENTO_H */

