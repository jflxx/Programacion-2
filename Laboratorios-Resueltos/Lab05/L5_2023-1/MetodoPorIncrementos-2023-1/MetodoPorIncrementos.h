/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MetodoPorIncrementos.h
 * Author: Afedo
 *
 * Created on 14 de abril de 2024, 11:44
 */

#ifndef METODOPORINCREMENTOS_H
#define METODOPORINCREMENTOS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;


void cargarCursos (const char *nombArch,char ***&cursos_datos,int *&cursos_credito,char ****&cursos_alumnos,
            double **&cursos_informacion_economica);
void pruebaCursos (const char *nombArch,char ***cursos_datos,int *cursos_credito,
            char ****cursos_alumnos,double **cursos_informacion_economica);
void aumentarEspacios(char ***&cursos_datos,int *&cursos_creditos,int &cap,
        int &numDatos,char ****&cursos_alumnos, double **&cursos_informacion_economica);
void leerCurso(ifstream &arch,char **&cursos_datos,int *&cursos_credito,
        char *codigoCurso,int cap,int numDatos);
void leerAlumnos(ifstream &arch,char ***&cursos_alumnos,
                double *&cursos_informacion_economica,int curso_credito);
void colocarAlumnos(char **&cursos_alumnos,char *nombreAlumno,char *codigoEscala);
void aumentarEspacios(char ***&cursos_alumnos,int &numAlumnos,int &cap);
double pagoAlumno(char *codigoEscala);
void imprimirCursoDatos(ofstream &arch,char **cursos_datos,int cursos_credito,
                double *cursos_informacion_economica);
void imprimirAlumnosDato(ofstream &arch, char **cursos_alumnos);
void imprimirAlumnos(ofstream &arch, char ***cursos_alumnos);

void reporteDeAlumnosPorCurso (const char *nombArch,char ***cursos_datos,int *cursos_credito,char ****cursos_alumnos,
            double **cursos_informacion_economica);
void imprimirAlumnos(ofstream &arch,char ***cursos_alumnos,int credito);
void imprimirCurso(ofstream &arch,char **cursos_datos);
void imprimirTotal(ofstream &arch,double *cursos_informacion_economica);
void imprimirAlumnoo(ofstream &arch,char **cursos_alumnos,int credito);


#endif /* METODOPORINCREMENTOS_H */

