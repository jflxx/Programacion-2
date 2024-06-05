/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: Afedo
 *
 * Created on 30 de mayo de 2024, 17:52
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetNombre(char* nomb);
    char GetNombre(char* nomb) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    void leer(ifstream &arch);
private:
    int dni;
    char categoria;
    char *nombre;
};

#endif /* CLIENTE_H */

