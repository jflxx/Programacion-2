/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */
/* 
 * File:   main.cpp
 * Author: Afedo JF
 *
 * Created on 8 de junio de 2024, 11:28
 */

#include "Tesoreria.h"
using namespace std;

int main(int argc, char** argv) {
    Tesoreria ABoleta;
    
    ABoleta.cargaalumnos();
    ABoleta.actualizaboleta();
    ABoleta.imprimeboleta();
    
    return 0;
}

