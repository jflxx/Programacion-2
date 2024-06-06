/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MetodoExacto.h
 * Author: Afedo
 *
 * Created on 9 de abril de 2024, 16:22
 */

#ifndef METODOEXACTO_H
#define METODOEXACTO_H

void CargaDeClientes (int *&cli_DNI,char **&cli_Nombre,char *&cli_Categoria);
char *leerNombre(ifstream &arch,char &categoria);
void ReporteDeClientes (int *cli_DNI,char **cli_Nombre,char *cli_Categoria);
void CargaDePedidosYProductos(int *&cli_DNI,int *&pro_Codigo,char **&pro_Descripcion,
                double *&pro_Descuento,double *&pro_Precio,int **&cli_CodigoProFechaPedido,double **&cli_CantidadPedido);
void leerDatos(int cod,ifstream &arch,char *descripcion,double &porcentajeDesc,double &cantidad,
        double &precio,int &telefono,int &fecha);
int buscarCod_Pro_Agregar(int *buffPro_Codigo,int cod,char *descripcion,
        double porcentajeDesc,double precio,char **buffPro_Descripcion,
        double *buffPro_Descuento,double *buffPro_Precio,int &numDatos);
void agregarPedido(double cantidad,int fecha,int cod,int *&cli_DNI,int **buffCli_CodigoProFechaPedido,
        double **buffCli_CantidadPedido,int dni);
void agregar(double *buffCli_CantidadPedido,int *buffCli_CodigoProFechaPedido,
                    int fecha,double cod, int j,double cantidad);
//int buscarCod_Pro_Agregar(int *buffPro_Codigo,int cod,char *descripcion,
//        double porcentajeDesc,double precio,
//        double *buffPro_Descuento,double *buffPro_Precio,int &numDatos);
#endif /* METODOEXACTO_H */

