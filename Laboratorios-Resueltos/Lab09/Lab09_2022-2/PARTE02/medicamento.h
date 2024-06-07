/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   medicamento.h
 * Author: Afedo
 *
 * Created on 5 de junio de 2024, 15:14
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;


class medicamento {
public:
    medicamento();
    virtual ~medicamento();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(char* nomb);
    void GetNombre(char* nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leerArchivoMedi();
    virtual void imprimemedicamento(ofstream &arch);
    virtual void leemedicamento(ifstream &arch);
    virtual void aplicadescuento();
private:
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int fecha;
    double total;
};

#endif /* MEDICAMENTO_H */

