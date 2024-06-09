/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Almacen.h
 * Author: Afedo
 *
 * Created on 9 de junio de 2024, 10:47
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Arbol.h"
#include "Medicamento.h"

class Almacen {
public:
    void carga();
    void actualiza();
    void imprime();
private:
    class Arbol arbolalma;
    Medicamento* leerMedicamento(ifstream &arch);
};

#endif /* ALMACEN_H */

