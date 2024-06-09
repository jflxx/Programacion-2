/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Boleta.h
 * Author: Afedo
 *
 * Created on 8 de junio de 2024, 11:38
 */

#ifndef BOLETA_H
#define BOLETA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Alumno.h"

class Boleta {
public:
    Boleta();
    void leeAlumno(ifstream &arch);
    bool operator <(const class Boleta &bol); 
    void imprimeAlumno(ofstream &arch);
    void actualiza(double PrecCred);
    int devolverEscala();
private:
    class Alumno *pboleta;
};

#endif /* BOLETA_H */

