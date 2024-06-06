/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */
/* 
 * File:   main.cpp
 * Author: Afedo JF
 *
 * Created on 15 de abril de 2024, 22:14
 */

#include "MetodoPorIncrementos.h"


int main(int argc, char** argv) {
    char ***medicoDatos, ****citaPaciente;
    int **citaCantidad;
    double *medicoTarifaHora, ***citaTiempoYPago;
    
    cargarCitas ("Citas.csv", medicoDatos, medicoTarifaHora, citaPaciente, citaCantidad,
                citaTiempoYPago);
    
    pruebaDeCargaDeCitas ("PruebaDeCargaDeCitas.txt", medicoDatos, medicoTarifaHora,
                citaPaciente, citaCantidad, citaTiempoYPago);
    
//    ReporteDeCitasPorMedico ("ReporteDeCitasPorMedico.txt", medicoDatos, medicoTarifaHora,
//                citaPaciente, citaCantidad, citaTiempoYPago);
    return 0;
}
