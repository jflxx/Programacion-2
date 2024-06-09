/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */
/* 
 * File:   main.cpp
 * Author: Afedo JF
 *
 * Created on 28 de abril de 2024, 17:40
 */

#include <iostream>

using namespace std;
#include "BibGenerica.h"
#include "FunConEnteros.h"
#include "FunConRegistro.h"
int main(int argc, char** argv) {
    void *cola;
//    
//    crearcola(cola,"numeros.txt",leenumero,prioridadNumero);
//    imprimirnum(cola,"reporte.txt");
    
    crearcola(cola,"Pedidos.csv",leeRegistro,prioridadpedido);
    imprimirped(cola,"ReporteFinal.txt");
    
    return 0;
}

