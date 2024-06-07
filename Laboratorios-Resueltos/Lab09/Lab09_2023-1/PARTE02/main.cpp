/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */
/* 
 * File:   main.cpp
 * Author: Afedo JF
 *
 * Created on 5 de junio de 2024, 09:38
 */

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Tesoreria.h"

int main(int argc, char** argv) {
    Tesoreria OTeso;
    
    OTeso.cargaescalas();
    OTeso.cargaalumnos();
    OTeso.actualizaboleta();
    OTeso.imprimeboleta();
    return 0;
}

