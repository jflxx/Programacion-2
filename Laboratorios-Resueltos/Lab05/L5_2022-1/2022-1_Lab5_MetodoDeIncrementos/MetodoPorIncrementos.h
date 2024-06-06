/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MetodoPorIncrementos.h
 * Author: Afedo
 *
 * Created on 18 de abril de 2024, 17:30
 */

#ifndef METODOPORINCREMENTOS_H
#define METODOPORINCREMENTOS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

void CargaDePedidosYProductos(int **&cli_DniTelefono,char ***&pro_CodigoDescripcion,
            double **&pro_PrecioDescuento,char ***&ped_Codigo,int ***&ped_FechaCantidad,const char *nombArch);
void aumentarEspacios(char ***&pro_CodigoDescripcion,double **&pro_PrecioDescuento,int &numDatosProd,int &capProd);
bool compararCodigos(char **pro_CodigoDescripcion,char *codigoProd);
bool productoEncontrado(char ***pro_CodigoDescripcion,char *codigoProd,int numDatosProd);
void agregarProducto(char **&pro_CodigoDescripcion,double *&pro_PrecioDescuento,
        char *codigoProd,char *nombreProd,double precioProd,int &numDatosProd,double descuentoProd);
void leerDatosProducto(ifstream &arch,char *&codigoProd,char *&nombreProd,double &precioProd,int &cantPedido,double &descuentoProd);
void leerDatosPedido(ifstream &arch,int &dniCliente,int &fecha);

#endif /* METODOPORINCREMENTOS_H */

