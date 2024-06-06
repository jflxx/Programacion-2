/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Alumno.h
 * Author: Afedo
 *
 * Created on 26 de mayo de 2024, 19:05
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
class Alumno {
public:
    Alumno();
    Alumno(int cod,const char *nomb,int escala,double total);
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* nomb);
    char GetNombre(char* nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leerDatos(ifstream &arch);
    void imprimir(ofstream &arch);
private:
    int codigo;
    char *nombre;
    int escala;
    double total;
};

#endif /* ALUMNO_H */

