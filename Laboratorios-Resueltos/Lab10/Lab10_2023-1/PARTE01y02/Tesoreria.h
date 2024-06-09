/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tesoreria.h
 * Author: Afedo
 *
 * Created on 8 de junio de 2024, 11:47
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Arbol.h"
#include "Boleta.h"

class Tesoreria {
public:
    void cargaalumnos();
    void actualizaboleta();
    void imprimeboleta();
private:
    class Alumno *leeAlumno(ifstream &arch);
    class Arbol aboleta;
};


#endif /* TESORERIA_H */

