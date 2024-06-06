/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */
/* 
 * File:   main.cpp
 * Author: Afedo JF
 *
 * Created on 18 de abril de 2024, 17:17
 */

#include "Clientes.h"
#include "MetodoPorIncrementos.h"

int main(int argc, char** argv) {
    char ***cli_NombreCategoria, ***pro_CodigoDescripcion, ***ped_Codigo;
    int **cli_DniTelefono, ***ped_FechaCantidad;
    double **pro_PrecioDescuento;
    
    CargaDeClientes (cli_DniTelefono, cli_NombreCategoria, "Clientes.csv");
    ReporteDeClientes (cli_DniTelefono, cli_NombreCategoria, "PreubaClientes.txt");
    
    CargaDePedidosYProductos(cli_DniTelefono, pro_CodigoDescripcion,
            pro_PrecioDescuento, ped_Codigo, ped_FechaCantidad, "Pedidos.csv");
    
//    ReporteDePedidosYProductos(cli_DniTelefono, pro_CodigoDescripcion,
//            pro_PrecioDescuento, ped_Codigo, ped_FechaCantidad,
//                "PruebaProductosPedidos.txt");
//    ReporteRlacionDePedidos (cli_DniTelefono, cli_NombreCategoria, pro_CodigoDescripcion,
//                pro_PrecioDescuento, ped_Codigo, ped_FechaCantidad,
//                    "ReporteDeRelacionDePedidos.txt");
    return 0;
}