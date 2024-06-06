/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MetodoPorIncrementos.h
 * Author: Afedo
 *
 * Created on 15 de abril de 2024, 22:19
 */

#ifndef METODOPORINCREMENTOS_H
#define METODOPORINCREMENTOS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

void cargarCitas (const char *nombArch,char ***&medicoDatos,double *&medicoTarifaHora,
        char ****&citaPaciente,int **&citaCantidad,double ***&citaTiempoYPago);
void inicializarArreglos(char ***&medicoDatos,double *&medicoTarifaHora,
        char ****&citaPaciente,int **&citaCantidad,double ***&citaTiempoYPago,
        int numDatos);
void leerDatosPaciente(ifstream &arch,char *&codigo,char *&nombre);
void leeDatosMedico(ifstream &arch,char *&codMedico,char *&nombMedico,
        double &tarifaMed);
void iniciarEspaciosDatosMedico(char ***&medicoDatos,int numDatos,int cap,
        char ****&citaPaciente);
void agregarPaciente(ifstream &arch,char ***&citaPaciente,int *&citaCantidad,
                double **&citaTiempoYPago,char *codigoPac,char *nombrePac,
        double tarifaMed);
void leeHora(ifstream &arch,double &hora);
char *paciente(char **citaPaciente);
void agregarPac(char **&citaPaciente,int &citaCantidad,
                double *&citaTiempoYPago,char *codigoPac,char *nombrePac);
void calcularTiempoYPago(ifstream &arch,double *&citaTiempoYPago,double tarifaMed);
void agregarEspacios(char ***&citaPaciente,int *&citaCantidad,double **&citaTiempoYPago,
                    int cap,int cantPacientes);
void verificarEspacioSuficiente(char ***&citaPaciente,int *&citaCantidad,
                double **&citaTiempoYPago);
void agregarMedico(char **&medicoDatos,char *codMedico,char *nombMedico);
int buscarMed(char ***&medicoDatos,double *&medicoTarifaHora,
        char ****&citaPaciente,int **&citaCantidad,double ***&citaTiempoYPago,
        char *codMedico,char *nombMedico,double tarifaMed,
        int &numDatos,int &cap);
bool codIguales(char **medicoDatos,char *codMedico);
void agregarEspacios(char ***&medicoDatos,double *&medicoTarifaHora,
        char ****&citaPaciente,int **&citaCantidad,
                double ***&citaTiempoYPago,int &numDatos,int &cap);

void pruebaDeCargaDeCitas (const char *nombArch,char ***medicoDatos,double *medicoTarifaHora,
                char ****citaPaciente,int **citaCantidad,double ***citaTiempoYPago);
void imprimirDatosMed(ofstream &arch,char **medicoDatos,double medicoTarifaHora);
void imprimirPacientes(ofstream &arch,char ***citaPaciente,int *citaCantidad,
        double **citaTiempoYPago);
void imprimirDatosPac(ofstream &arch,char **citaPaciente);


#endif /* METODOPORINCREMENTOS_H */

