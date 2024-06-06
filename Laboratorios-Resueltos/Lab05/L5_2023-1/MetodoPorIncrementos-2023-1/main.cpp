/* 
 * File:   main.cpp
 * Author: Afedo JF
 *
 * Created on 14 de abril de 2024, 11:34
 */

#include "MetodoPorIncrementos.h"

int main(int argc, char** argv) {
    char ***cursos_datos, ****cursos_alumnos;
    int *cursos_credito;
    double **cursos_informacion_economica;
    
    
    cargarCursos ("matricula_ciclo_2023_1.csv", cursos_datos, cursos_credito, cursos_alumnos,
            cursos_informacion_economica);
    
    pruebaCursos ("PruebaCursos.txt", cursos_datos, cursos_credito, cursos_alumnos, cursos_informacion_economica);
    
    reporteDeAlumnosPorCurso ("ReporteDeAlumnosPorCurso.txt", cursos_datos, cursos_credito, cursos_alumnos,
            cursos_informacion_economica);
    
    return 0;
}

