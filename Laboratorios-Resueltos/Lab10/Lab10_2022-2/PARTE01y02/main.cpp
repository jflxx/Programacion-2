/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */
/* 
 * File:   main.cpp
 * Author: Afedo JF
 *
 * Created on 9 de junio de 2024, 10:38
 */

#include "Almacen.h"
using namespace std;

int main(int argc, char** argv) {
    Almacen alma;
    alma.carga();
    alma.actualiza();
    alma.imprime();
    return 0;
}

