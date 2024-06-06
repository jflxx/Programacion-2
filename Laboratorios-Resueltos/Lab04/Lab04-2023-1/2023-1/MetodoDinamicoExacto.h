/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MetodoDinamicoExacto.h
 * Author: Afedo
 *
 * Created on 10 de abril de 2024, 15:20
 */

#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

void lecturaAlumnos (const char *nombArch,int *&alumno_Codigo,char **&alumno_Nombre,char *&alumno_Modalidad,
                int *&alumno_Porcentaje,int *&alumno_Escala);
void pruebaLecturaAlumnos(const char *nombArch,int *&alumno_Codigo,char **&alumno_Nombre,char *&alumno_Modalidad,
                  int *&alumno_Porcentaje,int *&alumno_Escala);
void lecturaCursos (const char *nombArch,int *&alumno_Codigo,int *&alumno_Escala,char **&curso_Nombre,
                double *&curso_Credito,int **&curso_Alumnos);
void agregarCurso(char *nombCurso,double creditos,char **buffNombreCur,
        double *buffCreditos,int **buffCur_Alumno,int &mumDatos);
void agregarAlumno(char **buffNombreCur,char *nombCurso,int codAlumn,
        const int *alumno_Codigo,const int *alumno_Escala,int **buffCur_Alumno);
void iniciarArreglosCursos(char **&curso_Nombre, double *&curso_Credito,int **&curso_Alumnos,int numDatos);
void pruebaDeLecturaCursos (const char *nombArch,char **&curso_Nombre,double *&curso_Credito,int **&curso_Alumnos);
int *colocarArregloAlumno_Curso(int *buffCur_Alumno);
void colocarAlumnosBuffer(int *buffCur_Alumno,int alumno_Codigo,int alumno_Escala);
void abrirArchivoLectura(ifstream &arch,const char *nombArch);
void abrirArchivoEscritura(ofstream &arch, const char *nombArch);

void reporteDeRecaudacionPorModalidad (const char *nombArch,int *alumno_Codigo,char *alumno_Modalidad,
                    int *alumno_Porcentaje,char **alumno_Nombre,char **curso_Nombre,double *curso_Credito,int **curso_Alumnos);
void imprimirDatosCurso(ofstream &arch,double curso_Credito,char *curso_Nombre,
        int i);
void imprimirAlumnosMatriculados(ofstream &arch,int *curso_Alumnos,char **alumno_Nombre,
                char *alumno_Modalidad,int *alumno_Porcentaje,int *alumno_Codigo,
                double curso_Credito,double &recPres,double &recSemi,double &recVirt);
void imprimirEncabezado(ofstream &arch);
void imprimirEncabezadoAlumno(ofstream &arch);
void agregarEscalas(double *escalas);
int buscarAlumno(int codigo,int *alumno_Codigo);
void imprimirRecuadado(ofstream &arch,char alumno_Modalidad,double recaudadoAlumno);
char *leeCadena(ifstream &arch,int lim,char car);
void imprimirLinea(ofstream &arch,char c,int num);
#endif /* METODODINAMICOEXACTO_H */

