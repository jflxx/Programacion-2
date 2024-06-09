/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */
/* 
 * File:   main.cpp
 * Author: Afedo JF
 *
 * Created on 6 de junio de 2024, 22:49
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Promociones.h"

int main(int argc, char** argv) {
    Promociones pro;
    
    pro.leepedidos();
    pro.actualizapedidos();
    pro.imprimepedidos();
    
    return 0;
}

