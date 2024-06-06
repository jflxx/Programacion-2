/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tesoreria.h
 * Author: Afedo
 *
 * Created on 26 de mayo de 2024, 19:51
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include <iostream>
#include <cstring>
using namespace std;
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"
#include "FuncionesAuxiliares.h"
class Tesoreria {
public:
    Tesoreria();
    Tesoreria(const Tesoreria& orig);
    virtual ~Tesoreria();
    void cargaescalas();
    void cargaalumnos();
    void actualiza(int cant);
    void imprime();
private:
    class Presencial lpresencial[100];
    class Semipresencial lsemipresencial[100];
    class Virtual lvirtual[100];
    class Escala lescala[10];
};

#endif /* TESORERIA_H */

