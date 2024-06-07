/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: Afedo
 *
 * Created on 6 de junio de 2024, 12:33
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Cliente {
public:
    Cliente();
    virtual ~Cliente();
    void SetTotalped(double totalped);
    double GetTotalped() const;
    void SetCantped(int cantped);
    int GetCantped() const;
    void SetNombre(char* nomb);
    void GetNombre(char* nomb) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    void imprimeDatos(ofstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void lee(ifstream &arch);
    virtual void calcula(double tot);
private:
    int dni;
    char categoria;
    char *nombre;
    int cantped;
    double totalped;
};

#endif /* CLIENTE_H */

