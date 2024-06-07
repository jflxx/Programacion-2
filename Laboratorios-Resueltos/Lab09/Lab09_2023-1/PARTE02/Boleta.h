/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Boleta.h
 * Author: Afedo
 *
 * Created on 5 de junio de 2024, 12:15
 */

#ifndef BOLETA_H
#define BOLETA_H
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Alumno.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"

class Boleta {
public:
    Boleta();
    virtual ~Boleta();
    void asignaMemoria(char tipo);
    void leeDatos(ifstream &arch);
    bool hayDato();
    void imprimeDatos(ofstream &arch);
    void actualizar(double valorC);
    int devolverEscala();
private:
    class Alumno *pboleta; 
};

#endif /* BOLETA_H */

