/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Alumno.h
 * Author: Afedo
 *
 * Created on 8 de junio de 2024, 11:28
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
class Alumno {
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(char* nomb);
    void GetNombre(char* nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void actualizatotal(double CostCred);
private:
    int codigo;
    char *nombre;
    int escala;
    double creditos;
    double total;
};

#endif /* ALUMNO_H */

