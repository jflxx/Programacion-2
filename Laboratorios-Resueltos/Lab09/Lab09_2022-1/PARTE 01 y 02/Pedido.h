/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Afedo
 *
 * Created on 6 de junio de 2024, 12:41
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
    void leerPed(ifstream &arch,int cod);
    void colocarDatos(int cod,int cant,int DocIden,int fech,double tot);
    void setTotal(double total);
    double getTotal() const;
    void setFecha(int fecha);
    int getFecha() const;
    void setDni(int dni);
    int getDni() const;
    void setCantidad(int cantidad);
    int getCantidad() const;
    void setCodigo(int codigo);
    int getCodigo() const;
    bool hayDato();
private:
    int codigo;
    int cantidad;
    int dni;
    int fecha;
    double total;
};

#endif /* PEDIDO_H */

