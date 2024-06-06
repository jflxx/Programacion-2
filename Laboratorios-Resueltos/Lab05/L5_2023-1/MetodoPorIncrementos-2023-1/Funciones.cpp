#include "MetodoPorIncrementos.h"
#define INCREMENTO 5
#define ESCALA1 282.2
#define ESCALA2 362
#define ESCALA3 454.2
#define ESCALA4 556.7
#define ESCALA5 666.9
void aperturaDeArchivoParaLeer(ifstream &arch,const char *nombArch){
    arch.open(nombArch,ios::in);
    if(not arch.is_open()){
        cout << "El archivo " << nombArch << " no se pudo abrir correctamnete." <<endl;
        exit(1);
    }
}
void aperturaDeArchivoParaEscribir(ofstream &arch,const char *nombArch){
    arch.open(nombArch,ios::out);
    if(not arch.is_open()){
        cout << "El archivo " << nombArch << " no se pudo abrir correctamnete." <<endl;
        exit(1);
    }
}
char *leerCadena(ifstream &arch,int max,char delim){
    char cadena[100],*cad;
    arch.getline(cadena,max,delim);
    int longitud = strlen(cadena)+1;
    cad = new char [longitud];
    strcpy(cad,cadena);
    
    return cad;
}
char *leerCodEscala(ifstream &arch){
    char cadena[11]{},*cad;
    
    arch.getline(cadena,11,'.');
    cadena[8] = '.';
    arch >> cadena[9];
    cad = new char [11]{};
    strcpy(cad,cadena);
    if(arch.peek()==',')
        arch.get();
    return cad;
}
void imprimirLinea(ofstream &arch,char c,int num){
    for(int i=0;i<num;i++)
        arch << c;
    arch<<endl;
}

/////////////////////////////////////////////////PREGUNTA 1////////////////////////////////////////////////
void cargarCursos (const char *nombArch,char ***&cursos_datos,int *&cursos_credito,
        char ****&cursos_alumnos,double **&cursos_informacion_economica){
    ifstream arch;
    aperturaDeArchivoParaLeer(arch,nombArch);
    
    int numDatos=0,cap=0;
    char *codigoCurso;
    
    cursos_datos = nullptr;
    cursos_credito = nullptr;
    cursos_alumnos = nullptr;
    cursos_informacion_economica = nullptr;
    
    
    while(true){
        codigoCurso = leerCadena(arch,60,',');  
        if(arch.eof()) break;
        if(numDatos == cap)
            aumentarEspacios(cursos_datos,cursos_credito,cap,numDatos,
                    cursos_alumnos,cursos_informacion_economica);
        leerCurso(arch,cursos_datos[numDatos-1],cursos_credito,
                codigoCurso,cap,numDatos);
        leerAlumnos(arch,cursos_alumnos[numDatos-1],
                cursos_informacion_economica[numDatos-1],cursos_credito[numDatos-1]);
        numDatos++;
    }
}

void pruebaCursos (const char *nombArch,char ***cursos_datos,int *cursos_credito,
            char ****cursos_alumnos,double **cursos_informacion_economica){
    ofstream arch;
    aperturaDeArchivoParaEscribir(arch,nombArch);
    
    arch.precision(2);
    arch << fixed;
    arch << left << setw(20) << "Curso Codigo"
            << setw(40) << "Curso Nombre"
            << setw(9) << "Credito"
            << setw(15) << "CantAlum"
            << setw(15) << "Recaudado"
            << setw(15) << "Alumno CodEscala"
            << setw(60) << "Almuno Nombre" <<endl;
    
    for(int i=0; cursos_datos[i]!=0 ;i++){
        imprimirCursoDatos(arch,cursos_datos[i],cursos_credito[i],
                cursos_informacion_economica[i]);
        imprimirAlumnos(arch,cursos_alumnos[i]);
    }
}
void imprimirAlumnos(ofstream &arch, char ***cursos_alumnos){
    for(int i=0;cursos_alumnos[i]!=0;i++){
        imprimirAlumnosDato(arch,cursos_alumnos[i]);
    }
}
void imprimirAlumnosDato(ofstream &arch, char **cursos_alumnos){
    arch << left << setw(100) << ""
            << setw(15) << cursos_alumnos[0]
            << setw(60) << cursos_alumnos[1]
            << endl;
}
void imprimirCursoDatos(ofstream &arch,char **cursos_datos,int cursos_credito,
                double *cursos_informacion_economica){
    arch << left << setw(20) << cursos_datos[0]
            << setw(40) << cursos_datos[1]
            << setw(9) << cursos_credito
            << setw(15) << cursos_informacion_economica[0]
            << setw(15) << cursos_informacion_economica[1] <<endl;
    
}
void leerAlumnos(ifstream &arch,char ***&cursos_alumnos,
                double *&cursos_informacion_economica,int curso_credito){
    int numAlumnos=0,cap=0;
    char *nombreAlumno, *codigoEscala;
    double ingresos=0;
    cursos_alumnos = nullptr;
    cursos_informacion_economica = nullptr;
    while(arch.peek()!='\n'){
        nombreAlumno = leerCadena(arch,60,',');
        codigoEscala = leerCodEscala(arch);
        if(numAlumnos==cap)
            aumentarEspacios(cursos_alumnos,numAlumnos,cap);
//        cout << codigoEscala << endl; 
        colocarAlumnos(cursos_alumnos[numAlumnos-1],nombreAlumno,codigoEscala);
        ingresos+=pagoAlumno(codigoEscala)*curso_credito;
        numAlumnos++;
    }
    //agregar costos
    cursos_informacion_economica = new double [2];
    cursos_informacion_economica[0] = numAlumnos;
    cursos_informacion_economica[1] = ingresos;
    
}
double pagoAlumno(char *codigoEscala){
    char cadena [11];
    
    strcpy(cadena,codigoEscala);
    
    if(cadena[9]=='1')
        return ESCALA1;
    if(cadena[9]=='2')
        return ESCALA2;
    if(cadena[9]=='3')
        return ESCALA3;
    if(cadena[9]=='4')
        return ESCALA4;
    else 
        return ESCALA5;
}
void colocarAlumnos(char **&cursos_alumnos,char *nombreAlumno,char *codigoEscala){
    cursos_alumnos = new char *[2]{};
    cursos_alumnos[0] = codigoEscala;
    cursos_alumnos[1] = nombreAlumno;
}
void aumentarEspacios(char ***&cursos_alumnos,int &numAlumnos,int &cap){
    char ***auxAlumnos;
    cap+=INCREMENTO;
    if(cursos_alumnos==nullptr){
        cursos_alumnos = new char **[cap]{};
        numAlumnos = 1;
    }else{
        auxAlumnos = new char **[cap]{};
        for(int i=0;i<numAlumnos;i++){
            auxAlumnos[i] = cursos_alumnos[i];
        }
        delete cursos_alumnos;
        cursos_alumnos = auxAlumnos;
    }
}

void leerCurso(ifstream &arch,char **&cursos_datos,int *&cursos_credito,
        char *codigoCurso,int cap,int numDatos){

    cursos_datos = new char *[2];
    cursos_datos[0] = codigoCurso;
    cursos_datos[1] = leerCadena(arch,100,',');
    arch >> cursos_credito[numDatos-1];
    arch.get();
}

void aumentarEspacios(char ***&cursos_datos,int *&cursos_creditos,int &cap,
        int &numDatos,char ****&cursos_alumnos, double **&cursos_informacion_economica){
    char ***auxDatos,****auxAlumnos;
    int *auxCreditos;
    double **auxInfEco;
    cap+=INCREMENTO;
    if(cursos_datos==nullptr){
        cursos_datos = new char **[cap]{};
        cursos_creditos = new int [cap]{};
        cursos_alumnos = new char ***[cap]{};
        cursos_informacion_economica = new double *[cap]{};
        numDatos=1;
    }else{
        auxDatos = new char**[cap]{};
        auxCreditos = new int [cap]{};
        auxAlumnos = new char ***[cap]{};
        auxInfEco = new double *[cap]{};
        for(int i=0; i<numDatos ;i++){
            auxCreditos[i] = cursos_creditos[i];
            auxDatos[i] = cursos_datos[i];
            auxAlumnos[i] = cursos_alumnos[i];
            auxInfEco[i] = cursos_informacion_economica[i];
        }
        delete cursos_creditos;
        delete cursos_datos;
        delete cursos_alumnos;
        delete cursos_informacion_economica;
        cursos_alumnos = auxAlumnos;
        cursos_creditos = auxCreditos;
        cursos_datos = auxDatos;
        cursos_informacion_economica = auxInfEco;
    }
}

/////////////////////////////////////////////////PREGUNTA 2////////////////////////////////////////////////

void reporteDeAlumnosPorCurso (const char *nombArch,char ***cursos_datos,int *cursos_credito,
        char ****cursos_alumnos,double **cursos_informacion_economica){
    ofstream arch;
    aperturaDeArchivoParaEscribir(arch,nombArch);
    
    arch.precision(2);
    arch << fixed;
    arch << right << setw(80) << "CURSOS EN EL CILO 2023-1" <<endl;
    imprimirLinea(arch,'=',120);
    arch << "RELACION DE ALUMNOS POR CURSO" <<endl;
    imprimirLinea(arch,'=',120);
    for(int i=0;cursos_datos[i]!=0;i++){
        arch << left << setw(20) << "CODIGO"
            << setw(40) << "Nombre"
            << setw(9) << "Creditos: " << right 
                <<  setw(5) <<cursos_credito[i] << endl;
        imprimirCurso(arch,cursos_datos[i]);
        imprimirLinea(arch,'-',120);
        arch << "RELACION DE ALUMNOS MATRICULADOS: " << endl;
        imprimirLinea(arch,'-',120);
        arch << setw(8) << ""
                <<setw(15) << "CODIGO"
                <<setw(50) << "NOMBRE"
                << "Pago total" <<endl;
        imprimirLinea(arch,'-',120);
        imprimirAlumnos(arch,cursos_alumnos[i],cursos_credito[i]);
        imprimirLinea(arch,'-',120);
        arch << right << setw(20) << "TOTAL:";
        imprimirTotal(arch,cursos_informacion_economica[i]);
        imprimirLinea(arch,'=',120);
    }
}
void imprimirTotal(ofstream &arch,double *cursos_informacion_economica){
    arch << setw(20) << cursos_informacion_economica[1]<<endl;
}
void imprimirCurso(ofstream &arch,char **cursos_datos){
    arch << left << setw(20) << cursos_datos[0]
            << setw(40) << cursos_datos[1] <<endl;
}
void imprimirAlumnos(ofstream &arch,char ***cursos_alumnos,int credito){
    for(int i=0;cursos_alumnos[i]!=0;i++){
        arch << " "<<i+1<<setw(6)<<"";
        imprimirAlumnoo(arch,cursos_alumnos[i],credito);
    }
}
void imprimirAlumnoo(ofstream &arch,char **cursos_alumnos,int credito){
    char cadena[11]{},cod[9]{},*codigo,*codEscala=cursos_alumnos[0];
    double pago = pagoAlumno(cursos_alumnos[0]);
    strcpy(cadena,codEscala);
    for(int i=0;i<8;i++)
        cod[i] = cadena[i];
    codigo = new char [strlen(cod)+1]{};
    strcpy(codigo,cod);
    arch << left <<setw(15) << codigo
                <<setw(50) << cursos_alumnos[1]
                << credito*pago <<endl;
}

