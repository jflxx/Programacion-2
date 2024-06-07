/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tesoreria.h
 * Author: Afedo
 *
 * Created on 5 de junio de 2024, 12:19
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Boleta.h"
#include "Escala.h"

class Tesoreria {
public: 
    void cargaescalas();
    void actualizaboleta();
    void cargaalumnos();
    void imprimeboleta();
private:
    class Boleta lboleta[100];
    class Escala lescala[5];
};

#endif /* TESORERIA_H */

