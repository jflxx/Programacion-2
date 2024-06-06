#include "MetodoDinamicoExacto.h"

int main(int argc, char **argv){
    char **alumno_Nombre,**curso_Nombre, *alumno_Modalidad;
    int *alumno_Codigo, *alumno_Porcentaje,*alumno_Escala;
    int **curso_Alumnos;
    double *curso_Credito;
    
    
    lecturaAlumnos ("alumnos.csv",alumno_Codigo, alumno_Nombre, alumno_Modalidad, alumno_Porcentaje, alumno_Escala);
    
    pruebaLecturaAlumnos ("ReporteAlumnos.txt",alumno_Codigo, alumno_Nombre, alumno_Modalidad, alumno_Porcentaje,alumno_Escala);

    lecturaCursos ("alumnos_cursos.csv", alumno_Codigo, alumno_Escala, curso_Nombre, curso_Credito, curso_Alumnos);
    
    pruebaDeLecturaCursos ("ReporteCursos.csv", curso_Nombre, curso_Credito, curso_Alumnos);
    
    reporteDeRecaudacionPorModalidad ("ReporteRecaudacionModalidad.txt", alumno_Codigo, alumno_Modalidad,
                alumno_Porcentaje, alumno_Nombre, curso_Nombre, curso_Credito, curso_Alumnos);
    
//    reporteDeRecaudacionPorModalidad (const char *nombArch,int *alumno_Codigo,int *alumno_Modalidad,
//                    int *alumno_Porcentaje,char **alumno_Nombre,char **curso_Nombre,double *curso_Credito,int **curso_Alumnos);

    return 0;
}
